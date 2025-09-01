// Write a program that converts a postfix expression to a fully parenthesized infix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
	char **arr;
	int top;
	int capacity;
} Stack;

Stack *init(int capacity);
void push(Stack *stack, char *str);
char *pop(Stack *stack);
char *postfixToInfix(char *postfix);

int main()
{
	char *postfix = (char *)malloc(100 * sizeof(char));
	printf("Enter a postfix expression: ");
	fgets(postfix, sizeof(postfix), stdin);

	postfix[strcspn(postfix, "\n")] = '\0';

	char *infix = postfixToInfix(postfix);
	printf("Fully parenthesized infix expression: %s\n", infix);

	free(infix);
	return 0;
}

Stack *init(int capacity)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (char **)malloc(capacity * sizeof(char *));
	return stack;
}

void push(Stack *stack, char *str)
{
	if (stack->top == stack->capacity - 1)
	{
		printf("Stack Overflow\n");
		return;
	}
	stack->arr[++stack->top] = str;
}

char *pop(Stack *stack)
{
	if (stack->top == -1)
	{
		printf("Stack Underflow\n");
		return NULL;
	}
	return stack->arr[stack->top--];
}

char *postfixToInfix(char *postfix)
{
	int len = strlen(postfix);
	Stack *stack = init(len);

	for (int i = 0; i < len; i++)
	{
		char c = postfix[i];

		if (isspace(c))
			continue;

		if (isalnum(c))
		{
			char *op = (char *)malloc(2 * sizeof(char));
			op[0] = c;
			op[1] = '\0';
			push(stack, op);
		}
		else
		{
			char *op2 = pop(stack);
			char *op1 = pop(stack);

			char *expr = (char *)malloc(strlen(op1) + strlen(op2) + 4);
			sprintf(expr, "(%s%c%s)", op1, c, op2);

			push(stack, expr);

			free(op1);
			free(op2);
		}
	}

	char *result = pop(stack);
	free(stack->arr);
	free(stack);
	return result;
}