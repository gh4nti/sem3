/*
Linked List-Based Stack:
i. Write a program to input an infix expression and convert into its equivalent post fix form and display. Operands can be single characters.
ii. Evaluate a postfix expression using stack.
- Push operands, pop two for operator, and push result back.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *top = NULL;

int isEmpty();
void push(int data);
int pop();
int peek();
int precedence(char op);
void infixToPostfix(char *infix);
void evaluatePostfix(char *postfix);

int main()
{
	int c;
	char *expr = (char *)malloc(100 * sizeof(char));

	while (1)
	{
		printf("\n--- Stack Operations Menu ---\n");
		printf("1. Infix to Postfix Conversion\n");
		printf("2. Postfix Expression Evaluation\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &c) != 1)
		{
			while (getchar() != '\n')
				;
			printf("Invalid input. Please enter a number.\n");
			continue;
		}

		switch (c)
		{
		case 1:
			printf("Enter an infix expression: ");
			scanf("%s", expr);
			infixToPostfix(expr);
			break;
		case 2:
			printf("Enter a postfix expression: ");
			scanf("%s", expr);
			evaluatePostfix(expr);
			break;
		case 3:
			printf("Exiting program.\n");
			while (!isEmpty())
				pop();

			exit(0);
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}

int isEmpty()
{
	return top == NULL;
}

void push(int data)
{
	Node *new = (Node *)malloc(sizeof(Node));

	if (!new)
		return;

	new->data = data;
	new->next = top;
	top = new;
}

int pop()
{
	if (isEmpty())
		return -1;

	Node *temp = top;
	int popped = temp->data;
	top = top->next;
	free(temp);

	return popped;
}

int peek()
{
	if (isEmpty())
		return -1;

	return top->data;
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
		return 0;
	}
}

void infixToPostfix(char *infix)
{
	char postfix[strlen(infix) + 1];
	int k = 0;

	for (int i = 0; i < strlen(infix); i++)
	{
		char c = infix[i];

		if (isalnum(c))
			postfix[k++] = c;

		else if (c == '(')
			push(c);

		else if (c == ')')
		{
			while (!isEmpty() && peek() != '(')
				postfix[k++] = pop();

			if (!isEmpty() && peek() == '(')
				pop();
		}

		else
		{
			while (!isEmpty() && precedence(c) <= precedence(peek()))
				postfix[k++] = pop();

			push(c);
		}
	}

	while (!isEmpty())
		postfix[k++] = pop();

	postfix[k] = '\0';
}

void evaluatePostfix(char *postfix)
{
	for (int i = 0; i < strlen(postfix); i++)
	{
		char c = postfix[i];

		if (isdigit(c))
			push(c - '0');

		else
		{
			int b = pop(), a = pop();

			if (a == -1 || b == -1)
			{
				while (!isEmpty())
					pop();

				return;
			}

			switch (c)
			{
			case '+':
				push(a + b);
				break;
			case '-':
				push(a - b);
				break;
			case '*':
				push(a * b);
				break;
			case '/':
				push(a / b);
				break;
			default:
				return;
			}
		}
	}

	int result = pop();

	if (!isEmpty())
	{
		while (!isEmpty())
			pop();
	}
	else
		printf("%d\n", result);
}