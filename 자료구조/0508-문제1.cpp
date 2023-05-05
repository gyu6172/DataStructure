#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define element char
int MAXSIZE = 100;
typedef struct StackType{
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

int getPriority(char c) {
	if (c == '!'/* || c == '+' || c == '-'*/) {
		return 6;
	}
	else if (c == '*' || c == '/') {
		return 5;
	}
	else if (c == '+' || c == '-') {
		return 4;
	}
	else if (c == '>' || c == '<') {
		return 3;
	}
	else if (c == '&') {
		return 2;
	}
	else if (c == '|') {
		return 1;
	}
	else if (c == '(') {
		return 0;
	}
}

void printOperator(StackType* stack) {
	if (peek(stack) == '&' || peek(stack) == '|') {
		printf("%c", peek(stack));
	}
	printf("%c", pop(stack));
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
			if ('A' <= str[j] && str[j] <= 'Z') {
				printf("%c",str[j]);
			}
			else {
				if (str[j] == '&' || str[j] == '|') {
					j++;
				}
				if (isEmpty(&stack) || str[j]=='(') {
					push(&stack, str[j]);
				}
				else if (str[j] == ')') {
					while (peek(&stack) != '(') {
						printOperator(&stack);
					}
					pop(&stack);
				}
				else {
					while (1) {
						if (isEmpty(&stack) || getPriority(peek(&stack)) < getPriority(str[j])) {
							break;
						}
						printOperator(&stack);
					}
					push(&stack, str[j]);
				}
			}
		}
		while (!isEmpty(&stack)) {
			printOperator(&stack);
		}
		printf("\n");
	}

	free(stack.data);
	return 0;
}