#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define element int
int MAXSIZE = 100000;
typedef struct {
	int top;
	element* data;
}StackType;

int isEmpty(StackType* stack) {
	if (stack->top < 0) return 1;
	else return 0;
}

int isFull(StackType* stack) {
	if (stack->top >= MAXSIZE - 1) return 1;
	else return 0;
}

element pop(StackType* stack) {
	if (!isEmpty(stack))
		return stack->data[(stack->top)--];
}

void push(StackType* stack, element elem) {
	if (!isFull(stack)) {
		stack->data[++(stack->top)] = elem;
	}
}

element peek(StackType* stack) {
	if (!isEmpty(stack))
		return stack->data[(stack->top)];
}

int main() {
	StackType stack;
	stack.top = -1;
	stack.data = (element*)malloc(sizeof(element) * MAXSIZE);

	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		char str[101];
		scanf("%s",str);
		for (int j = 0; j < strlen(str); j++) {
			if ('0' <= str[j] && str[j] <= '9') {
				push(&stack, str[j]-'0');
			}
			else {
				int n2=pop(&stack);
				int n1=pop(&stack);
				if (str[j] == '+') {
					push(&stack, n1+n2);
				}
				else if (str[j] == '-') {
					push(&stack, n1 - n2);

				}
				else if (str[j] == '*') {
					push(&stack, n1 * n2);

				}
				else if (str[j] == '/') {
					push(&stack, n1 / n2);

				}
			}
		}
		printf("%d\n",pop(&stack));
	}

	free(stack.data);
	return 0;
}