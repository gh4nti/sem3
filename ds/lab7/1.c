/*
Array-Based Stack:
i. Check whether a given string is a palindrome using stack.
- Use character stack to compare original and reversed string.
ii. Check for matching parentheses in each expression.
- Push opening brackets, pop for matching closing brackets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char arr[MAX];
int top = -1;

int isEmpty();
int isFull();
void push(char c);
char pop();
char peek();
int isPalindrome(char *str);
int isBalanced(char *expr);

int main()
{
	char *str = (char *)malloc(MAX * sizeof(char));
	char *expr = (char *)malloc(MAX * sizeof(char));
	printf("Enter a string: ");
	fgets(str, MAX, stdin);
	str[strcspn(str, "\n")] = '\0';

	printf("Enter an expression: ");
	fgets(expr, MAX, stdin);
	expr[strcspn(expr, "\n")] = '\0';

	if (isPalindrome(str))
		printf("%s is a palindrome.\n", str);

	else
		printf("%s is not a palindrome.\n", str);

	if (isBalanced(expr))
		printf("%s is balanced.\n", expr);

	else
		printf("%s is not balanced.\n", expr);
}

int isEmpty()
{
	return top == -1;
}

int isFull()
{
	return top == MAX - 1;
}

void push(char c)
{
	if (isFull())
		return;
	arr[++top] = c;
}

char pop()
{
	if (isEmpty())
		return '\0';
	return arr[top--];
}

char peek()
{
	if (isEmpty())
		return '\0';
	return arr[top];
}

int isPalindrome(char *str)
{
	top = -1;

	for (int i = 0; i < strlen(str); i++)
	{
		push(str[i]);
	}

	for (int i = 0; i < strlen(str); i++)
	{
		return str[i] == pop();
	}
}

int isBalanced(char *expr)
{
	top = -1;

	for (int i = 0; expr[i] != '\0'; i++)
	{
		char c = expr[i];

		if (c == '(' || c == '{' || c == '[')
			push(c);

		else if (c == ')' || c == '}' || c == ']')
		{
			if (isEmpty() ||
				(c == ')' && peek() != '(') ||
				(c == '}' && peek() != '{') ||
				(c == ']' && peek() != '['))
			{
				return 0;
			}

			else
				pop();
		}
	}

	return isEmpty();
}