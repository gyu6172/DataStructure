#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define element char
int MAXSIZE = 101;
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

int getPriority(char c, char next) {
	if (c == '!') {
		return 6;
	}
	else if (c == '*' || c == '/') {
		return 5;
	}
	else if (c == '+' || c == '-') {
		if (c == next) {
			return 6;
		}
		else {
			return 4;
		}
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
	
}

int main() {
	StackType stack;
	stack.top = -1;
	stack.data = (element*)malloc(sizeof(element) * MAXSIZE);

	StackType repeatStack;
	repeatStack.top = -1;
	repeatStack.data = (element*)malloc(sizeof(element) * MAXSIZE);

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
					push(&repeatStack, '0');
				}
				else if (str[j] == ')') {
					while (peek(&stack) != '(') {
						char op = pop(&stack);
						int rep = pop(&repeatStack);
						printf("%c", pop(&stack));
						if (rep == 1) {
							printf("%c", pop(&stack));
						}
					}
					pop(&stack);
					pop(&repeatStack);
				}
				else {
					while (1) {
						if (isEmpty(&stack) || getPriority(peek(&stack),peek(&repeatStack)) < getPriority(str[j], str[j+1])) {
							break;
						}
						char op = pop(&stack);
						int rep = pop(&repeatStack);
						printf("%c", pop(&stack));
						if (rep == '1') {
							printf("%c", pop(&stack));
						}
					}
					push(&stack, str[j]);
				}
			}
		}
		while (!isEmpty(&stack)) {
			char op = pop(&stack);
			int rep = pop(&repeatStack);
			printf("%c", pop(&stack));
			if (rep == '1') {
				printf("%c", pop(&stack));
			}
		}
		printf("\n");
	}

	free(stack.data);
	return 0;
}