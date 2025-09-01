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
	char data;
	struct Node *next;
} Node;

typedef struct Stack
{
	Node *top;
} Stack;

typedef struct NodeInt
{
	int data;
	struct NodeInt *next;
} NodeInt;

typedef struct StackInt
{
	NodeInt *top;
} StackInt;

void init(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char op);
int isOperator(char c);
void infixToPostfix(char *infix, char *postfix);

void initInt(StackInt *s);
int isEmptyInt(StackInt *s);
int popInt(StackInt *s);

int evaluatePostfix(char *postfix);

int main()
{
	char *infix = (char *)malloc(200 * sizeof(char));
	char *postfix = (char *)malloc(200 * sizeof(char));

	printf("Enter an infix expression: ");
	fgets(infix, sizeof(infix), stdin);

	int len = strlen(infix);
	if (len > 0 && infix[len - 1] == '\n')
	{
		infix[len - 1] = '\0';
	}

	infixToPostfix(infix, postfix);
	printf("Postfix Expression: %s\n", postfix);

	printf("Evaluating postfix expression...\n");
	int result = evaluatePostfix(postfix);
	printf("Result = %d\n", result);

	return 0;
}

void init(Stack *s)
{
	s->top = NULL;
}

int isEmpty(Stack *s)
{
	return s->top == NULL;
}

void push(Stack *s, char c)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = c;
	newNode->next = s->top;
	s->top = newNode;
}

char pop(Stack *s)
{
	if (isEmpty(s))
		return '\0';
	Node *temp = s->top;
	char c = temp->data;
	s->top = temp->next;
	free(temp);
	return c;
}

char peek(Stack *s)
{
	if (isEmpty(s))
		return '\0';
	return s->top->data;
}

int precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	return 0;
}

int isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char *infix, char *postfix)
{
	Stack s;
	init(&s);
	int k = 0;

	for (int i = 0; infix[i] != '\0'; i++)
	{
		char c = infix[i];

		if (isalnum(c))
		{
			postfix[k++] = c;
		}
		else if (c == '(')
		{
			push(&s, c);
		}
		else if (c == ')')
		{
			while (!isEmpty(&s) && peek(&s) != '(')
			{
				postfix[k++] = pop(&s);
			}
			pop(&s);
		}
		else if (isOperator(c))
		{
			while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c))
			{
				postfix[k++] = pop(&s);
			}
			push(&s, c);
		}
	}

	while (!isEmpty(&s))
	{
		postfix[k++] = pop(&s);
	}

	postfix[k] = '\0';
}

void initInt(StackInt *s)
{
	s->top = NULL;
}

int isEmptyInt(StackInt *s)
{
	return s->top == NULL;
}

void pushInt(StackInt *s, int val)
{
	NodeInt *newNode = (NodeInt *)malloc(sizeof(NodeInt));
	newNode->data = val;
	newNode->next = s->top;
	s->top = newNode;
}

int popInt(StackInt *s)
{
	if (isEmptyInt(s))
		return 0;
	NodeInt *temp = s->top;
	int val = temp->data;
	s->top = temp->next;
	free(temp);
	return val;
}

int evaluatePostfix(char *postfix)
{
	StackInt s;
	initInt(&s);

	for (int i = 0; postfix[i] != '\0'; i++)
	{
		char c = postfix[i];

		if (isdigit(c))
		{
			pushInt(&s, c - '0');
		}
		else if (isOperator(c))
		{
			int val2 = popInt(&s);
			int val1 = popInt(&s);
			int res;

			switch (c)
			{
			case '+':
				res = val1 + val2;
				break;
			case '-':
				res = val1 - val2;
				break;
			case '*':
				res = val1 * val2;
				break;
			case '/':
				res = val1 / val2;
				break;
			case '^':
			{
				res = 1;
				for (int j = 0; j < val2; j++)
					res *= val1;
				break;
			}
			default:
				res = 0;
			}
			pushInt(&s, res);
		}
	}

	return popInt(&s);
}