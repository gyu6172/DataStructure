#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAXSIZE;
typedef struct Stack {
	int top;
	char* data;
}Stack;

int isEmpty(struct Stack* stack) {
	if (stack->top < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(struct Stack* stack) {
	if (stack->top >= MAXSIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

char pop(struct Stack* stack) {
	if (isEmpty(stack)) {
		//printf("Stack Empty");
		return 0;
	}
	else {
		return stack->data[(stack->top)--];
	}
}

void push(struct Stack* stack, char c) {
	if (isFull(stack)) {
		//printf("Stack FULL\n");
	}
	else {
		stack->data[++(stack->top)] = c;
	}
}

void peek(struct Stack* stack) {
	if (isEmpty(stack)) {
		//printf("Stack Empty");
	}
	else {
		//printf("%c\n", stack->data[stack->top]);
	}
}

void print(struct Stack* stack) {
	for (int idx = stack->top; idx >= 0; idx--) {
		printf("%c", stack->data[idx]);
	}
	printf("\n");
}

int main() {

	MAXSIZE = 1001;

	Stack bracketStack;
	bracketStack.top = -1;
	bracketStack.data = (char*)malloc(sizeof(char) * MAXSIZE);

	char str[1001];
	gets_s(str);

	const char *rstStr = "OK";
	int rstNum=0;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(&bracketStack, str[i]);
			rstNum++;
		}
		else {
			if (str[i] == ')') {
				rstNum++;
				char c = pop(&bracketStack);
				if (c != '(') {
					rstStr = "Wrong";
				}
			}
			else if (str[i] == '}') {
				rstNum++;
				char c = pop(&bracketStack);
				if (c != '{') {
					rstStr = "Wrong";
				}
			}
			else if (str[i] == ']') {
				rstNum++;
				char c = pop(&bracketStack);
				if (c != '[') {
					rstStr = "Wrong";
				}
			}
		}
	}
	if (!isEmpty(&bracketStack)) {
		rstStr="Wrong";
	}

	printf("%s_%d",rstStr, rstNum);

}