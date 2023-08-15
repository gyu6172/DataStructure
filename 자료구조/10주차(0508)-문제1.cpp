#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define element char
int MAXSIZE = 101;
typedef struct StackType {
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

int isOperator(char c) {
	if (c=='+' || c=='-' || c=='*' || c=='/' || c=='!' || c=='&' || c=='|' || c=='>' || c=='<') {
		return 1;
	}
	else {
		return 0;
	}
}

int getPriority(char c, char prev) {
	if (c == '!') {
		return 6;
	}
	else if (c == '*' || c == '/') {
		return 5;
	}
	else if (c == '+' || c == '-') {
		if (isOperator(prev)) {
			return 7;
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
	else if (c == '(' || c==')') {
		return 0;
	}
}



int main() {
	StackType stack;
	stack.top = -1;
	stack.data = (element*)malloc(sizeof(element) * MAXSIZE);

	StackType prev_stack;
	prev_stack.top = -1;
	prev_stack.data = (element*)malloc(sizeof(element) * MAXSIZE);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[101];
		scanf("%s", str);

		for (int j = 0; j < strlen(str); j++) {
			if ('A' <= str[j] && str[j] <= 'Z') {
				printf("%c", str[j]);
			}
			else {
				if (str[j] == '&' || str[j] == '|') {
					j++;
				}
				if (isEmpty(&stack) || str[j] == '(') {
					
					push(&stack, str[j]);
					if (j == 0) {
						push(&prev_stack, '+');
						
					}
					else {
						push(&prev_stack, str[j - 1]);

					}
				}
				else if (str[j] == ')') {
					char c = pop(&stack);
					pop(&prev_stack);
					
					while (c != '(') {
						printf("%c", c);
						if (c == '&' || c == '|') {
							printf("%c", c);
						}
						c = pop(&stack);
						pop(&prev_stack);
					}
				}
				else {
					while (1) {
						if (isEmpty(&stack) || getPriority(peek(&stack), peek(&prev_stack)) < getPriority(str[j], str[j - 1])) {
							break;
						}
						char c = pop(&stack);
						pop(&prev_stack);
						printf("%c", c);
						if (c == '&' || c == '|') {
							printf("%c", c);

						}
					}
					push(&stack, str[j]);
					push(&prev_stack, str[j - 1]);
				
				}
			}
		}
		while (!isEmpty(&stack)) {
			char c = pop(&stack);
			pop(&prev_stack);
			printf("%c", c);
			if (c == '&' || c == '|') {
				printf("%c", c);

			}
		}
		printf("\n");
	}


	return 0;
}