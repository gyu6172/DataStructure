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
		printf("Stack Empty");
		return 0;
	}
	else {
		return stack->data[(stack->top)--];
	}
}

void push(struct Stack* stack, char c) {
	if (isFull(stack)) {
		printf("Stack FULL\n");
	}
	else {
		stack->data[++(stack->top)] = c;
	}
}

void peek(struct Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack Empty");
	}
	else {
		printf("%c\n", stack->data[stack->top]);
	}
}

void duplicate(struct Stack* stack) {
	char c = stack->data[stack->top];
	pop(stack);
	push(stack, c);
	push(stack, c);
}

void upRotate(struct Stack* stack, int n) {
	if (n <= stack->top + 1) {
		char tmp = stack->data[stack->top];
		for (int idx = stack->top; idx >= stack->top - n + 2; idx--) {
			stack->data[idx] = stack->data[idx - 1];
		}
		stack->data[stack->top - n + 1] = tmp;
	}
}

void downRotate(struct Stack* stack, int n) {
	if (n <= stack->top + 1) {
		char tmp = stack->data[stack->top - n + 1];
		for (int idx = stack->top - n + 1; idx < stack->top; idx++) {
			stack->data[idx] = stack->data[idx + 1];
		}
		stack->data[stack->top] = tmp;
	}
}

void print(struct Stack* stack) {
	for (int idx = stack->top; idx >= 0; idx--) {
		printf("%c", stack->data[idx]);
	}
	printf("\n");
}

int main() {

	scanf("%d", &MAXSIZE);

	Stack stack;
	stack.top = -1;
	stack.data = (char*)malloc(sizeof(char) * MAXSIZE);

	int orderCnt;
	scanf("%d", &orderCnt);

	for (int i = 0; i < orderCnt; i++) {
		char order[10];
		getchar();
		scanf("%s", order);

		if (strcmp(order, "POP") == 0) {
			pop(&stack);
		}
		else if (strcmp(order, "PUSH") == 0) {
			char c;
			getchar();
			scanf("%c", &c);
			push(&stack, c);
		}
		else if (strcmp(order, "PEEK") == 0) {
			peek(&stack);
		}
		else if (strcmp(order, "DUP") == 0) {
			duplicate(&stack);
		}
		else if (strcmp(order, "UpR") == 0) {
			int n;
			scanf("%d", &n);
			upRotate(&stack, n);
		}
		else if (strcmp(order, "DownR") == 0) {
			int n;
			scanf("%d", &n);
			downRotate(&stack, n);
		}
		else if (strcmp(order, "PRINT") == 0) {
			print(&stack);
		}
	}

}