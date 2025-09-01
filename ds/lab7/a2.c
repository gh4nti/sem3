/*
Write a C program to convert an infix expression to its equivalent prefix form.
- Use a stack-based algorithm, and handle operator precedence and associativity appropriately.
- Operands can be single characters.
- Display the resulting prefix expression
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
	char *arr;
	int top, capacity;
} Stack;

Stack *init(int capacity);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, char item);
char pop(Stack *stack);
char peek(Stack *stack);
int precedence(char op);
void reverse(char *exp);
void infixToPrefix(char *infix, char *prefix);

int main()
{
	char *infix = (char *)malloc(100 * sizeof(char));
	char *prefix = (char *)malloc(100 * sizeof(char));

	printf("Enter an infix expression: ");
	if (fgets(infix, sizeof(infix), stdin))
	{
		infix[strcspn(infix, "\n")] = '\0';
	}

	infixToPrefix(infix, prefix);

	printf("Prefix Expression: %s\n", prefix);

	return 0;
}

Stack *init(int capacity)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (char *)malloc(stack->capacity * sizeof(char));
	return stack;
}

int isEmpty(Stack *stack)
{
	return stack->top == -1;
}

int isFull(Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

void push(Stack *stack, char item)
{
	if (isFull(stack))
		return;
	stack->arr[++stack->top] = item;
}

char pop(Stack *stack)
{
	if (isEmpty(stack))
		return '\0';
	return stack->arr[stack->top--];
}

char peek(Stack *stack)
{
	if (isEmpty(stack))
		return '\0';
	return stack->arr[stack->top];
}

int precedence(char op)
{
	switch (op)
	{
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return -1;
	}
}

void reverse(char *exp)
{
	int n = strlen(exp);
	for (int i = 0; i < n / 2; i++)
	{
		char temp = exp[i];
		exp[i] = exp[n - i - 1];
		exp[n - i - 1] = temp;
	}
}

void infixToPrefix(char *infix, char *prefix)
{
	int n = strlen(infix);

	reverse(infix);
	for (int i = 0; i < n; i++)
	{
		if (infix[i] == '(')
			infix[i] = ')';
		else if (infix[i] == ')')
			infix[i] = '(';
	}

	Stack *stack = init(n);
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		char ch = infix[i];

		if (isalnum(ch))
		{ // Operand
			prefix[k++] = ch;
		}
		else if (ch == '(')
		{
			push(stack, ch);
		}
		else if (ch == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
			{
				prefix[k++] = pop(stack);
			}
			pop(stack);
		}
		else
		{
			while (!isEmpty(stack) && precedence(ch) <= precedence(peek(stack)))
			{
				prefix[k++] = pop(stack);
			}
			push(stack, ch);
		}
	}

	while (!isEmpty(stack))
	{
		prefix[k++] = pop(stack);
	}
	prefix[k] = '\0';

	reverse(prefix);

	free(stack->arr);
	free(stack);
}