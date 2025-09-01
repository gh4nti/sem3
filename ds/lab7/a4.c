// Write a program to evaluate prefix expressions. The input to the program is a prefix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct Stack
{
	int *arr;
	int top;
	int capacity;
} Stack;

Stack *init(int capacity);
void push(Stack *stack, int val);
int pop(Stack *stack);
int isOperator(char c);
int evaluatePrefix(char *expr);

int main()
{
	char *expr = (char *)malloc(100 * sizeof(char));
	printf("Enter a prefix expression: ");
	fgets(expr, sizeof(expr), stdin);

	expr[strcspn(expr, "\n")] = '\0';

	int result = evaluatePrefix(expr);
	printf("Result = %d\n", result);

	return 0;
}

Stack *init(int capacity)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (int *)malloc(capacity * sizeof(int));
	return stack;
}

void push(Stack *stack, int val)
{
	if (stack->top == stack->capacity - 1)
	{
		printf("Stack Overflow\n");
		exit(1);
	}
	stack->arr[++stack->top] = val;
}

int pop(Stack *stack)
{
	if (stack->top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack->arr[stack->top--];
}

int isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluatePrefix(char *expr)
{
	int len = strlen(expr);
	Stack *stack = init(len);

	for (int i = len - 1; i >= 0; i--)
	{
		char c = expr[i];

		if (isspace(c))
			continue;

		if (isdigit(c))
		{
			push(stack, c - '0');
		}
		else if (isOperator(c))
		{
			int op1 = pop(stack);
			int op2 = pop(stack);
			int result;

			switch (c)
			{
			case '+':
				result = op1 + op2;
				break;
			case '-':
				result = op1 - op2;
				break;
			case '*':
				result = op1 * op2;
				break;
			case '/':
				if (op2 == 0)
				{
					printf("Error: Division by zero\n");
					exit(1);
				}
				result = op1 / op2;
				break;
			case '^':
				result = (int)pow(op1, op2);
				break;
			default:
				result = 0;
			}

			push(stack, result);
		}
	}

	int finalResult = pop(stack);
	free(stack->arr);
	free(stack);
	return finalResult;
}