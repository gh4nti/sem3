/*
Array-Based Stack:
i. Check whether a given string is a palindrome using stack.
- Use character stack to compare original and reversed string.
ii. Check for matching parentheses in each expression.
- Push opening brackets, pop for matching closing brackets.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	char *arr;
	int top, capacity;
} Stack;

void init(Stack *s, int capacity);
void freeStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void resize(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
void removeNewLineChar(char *str);
int isPalindrome(char *str);
int isMatchingPair(char open, char close);
int areParenthesesBalanced(char *expr);

int main()
{
	char *str = (char *)malloc(200 * sizeof(char));
	char *expr = (char *)malloc(200 * sizeof(char));

	printf("Enter a string: ");
	if (fgets(str, sizeof(str), stdin))
	{
		removeNewLineChar(str);
	}

	if (isPalindrome(str))
		printf("%s is a palindrome.\n", str);
	else
		printf("%s is not a palindrome.\n", str);

	printf("\nEnter an expression: ");
	if (fgets(expr, sizeof(expr), stdin))
		removeNewLineChar(expr);

	if (areParenthesesBalanced(expr))
		printf("Parentheses are balanced.\n");
	else
		printf("Parentheses are NOT balanced.\n");

	return 0;
}

void init(Stack *s, int capacity)
{
	s->arr = (char *)malloc(capacity * sizeof(char));
	s->top = -1;
	s->capacity = capacity;
}

void freeStack(Stack *s)
{
	free(s->arr);
	s->arr = NULL;
	s->top = -1;
	s->capacity = 0;
}

int isEmpty(Stack *s)
{
	return s->top == -1;
}

int isFull(Stack *s)
{
	return s->top == s->capacity - 1;
}

void resize(Stack *s)
{
	s->capacity *= 2;
	s->arr = (char *)realloc(s->arr, s->capacity * sizeof(char));
}

void push(Stack *s, char c)
{
	if (isFull(s))
		resize(s);
	s->arr[++(s->top)] = c;
}

char pop(Stack *s)
{
	if (!isEmpty(s))
	{
		return s->arr[(s->top)--];
	}
	return '\0';
}

char peek(Stack *s)
{
	if (!isEmpty(s))
		return s->arr[s->top];
	return '\0';
}

void removeNewLineChar(char *str)
{
	int len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

int isPalindrome(char *str)
{
	int len = strlen(str);
	Stack s;
	init(&s, len > 0 ? len : 1);

	for (int i = 0; i < len; i++)
	{
		push(&s, str[i]);
	}

	for (int i = 0; i < len; i++)
	{
		if (str[i] != pop(&s))
		{
			freeStack(&s);
			return 0;
		}
	}

	freeStack(&s);
	return 1;
}

int isMatchingPair(char open, char close)
{
	return (open == '(' && close == ')') ||
		   (open == '{' && close == '}') ||
		   (open == '[' && close == ']');
}

int areParenthesesBalanced(char *expr)
{
	int len = strlen(expr);
	Stack s;
	init(&s, len > 0 ? len : 1);

	for (int i = 0; i < len; i++)
	{
		char c = expr[i];

		if (c == '(' || c == '{' || c == '[')
		{
			push(&s, c);
		}
		else if (c == ')' || c == '}' || c == ']')
		{
			if (isEmpty(&s) || !isMatchingPair(pop(&s), c))
			{
				freeStack(&s);
				return 0;
			}
		}
	}

	int balanced = isEmpty(&s);
	freeStack(&s);
	return balanced;
}