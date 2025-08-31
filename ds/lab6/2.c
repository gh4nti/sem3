/*
Add Two Polynomials Represented as Doubly Linked Lists.
i) Represent each polynomial using a doubly linked list, where each node contains the coefficient and exponent of a term.
ii) Write a function to add two polynomials by merging terms with equal exponents. The resulting polynomial should be stored in a new doubly linked list, maintaining the order of terms in descending powers of exponents.
iii) Display all three polynomials: the two input polynomials and their sum. Ensure dynamic memory allocation is used for all node operations and that both prev and next pointers are maintained correctly.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int coeff;
	int exp;
	struct Node *prev, *next;
} Node;

Node *createNode(int coeff, int exp);
void insertSorted(Node **head, int coeff, int exp);
Node *addPolynomials(Node *poly1, Node *poly2);
void printPolynomial(Node *head);
void freePolynomial(Node **head);

int main()
{
	Node *p1 = NULL, *p2 = NULL;

	int n1;
	printf("Enter number of terms in first polynomial: ");
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		int c, e;
		printf("Enter coeff and exp for term %d: ", i + 1);
		scanf("%d %d", &c, &e);
		insertSorted(&p1, c, e);
	}

	int n2;
	printf("Enter number of terms in second polynomial: ");
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		int c, e;
		printf("Enter coeff and exp for term %d: ", i + 1);
		scanf("%d %d", &c, &e);
		insertSorted(&p2, c, e);
	}

	Node *sum = addPolynomials(p1, p2);

	printf("First polynomial: ");
	printPolynomial(p1);

	printf("Second polynomial: ");
	printPolynomial(p2);

	printf("Sum: ");
	printPolynomial(sum);

	freePolynomial(&p1);
	freePolynomial(&p2);
	freePolynomial(&sum);

	return 0;
}

Node *createNode(int coeff, int exp)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertSorted(Node **head, int coeff, int exp)
{
	if (coeff == 0)
		return;

	Node *newNode = createNode(coeff, exp);
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	Node *curr = *head;
	Node *prev = NULL;
	while (curr && curr->exp > exp)
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr && curr->exp == exp)
	{
		curr->coeff += coeff;
		free(newNode);
		if (curr->coeff == 0)
		{
			if (prev)
			{
				prev->next = curr->next;
			}
			else
			{
				*head = curr->next;
			}
			if (curr->next)
			{
				curr->next->prev = prev;
			}
			free(curr);
		}
		return;
	}

	newNode->next = curr;
	newNode->prev = prev;
	if (curr)
	{
		curr->prev = newNode;
	}
	if (prev)
	{
		prev->next = newNode;
	}
	else
	{
		*head = newNode;
	}
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
	Node *result = NULL;
	Node *tail = NULL;
	Node *p1 = poly1;
	Node *p2 = poly2;

	while (p1 && p2)
	{
		int coeff, exp_val;
		if (p1->exp > p2->exp)
		{
			coeff = p1->coeff;
			exp_val = p1->exp;
			p1 = p1->next;
		}
		else if (p2->exp > p1->exp)
		{
			coeff = p2->coeff;
			exp_val = p2->exp;
			p2 = p2->next;
		}
		else
		{
			coeff = p1->coeff + p2->coeff;
			exp_val = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
			if (coeff == 0)
				continue;
		}

		Node *newNode = createNode(coeff, exp_val);
		if (result == NULL)
		{
			result = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	while (p1)
	{
		Node *newNode = createNode(p1->coeff, p1->exp);
		if (result == NULL)
		{
			result = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		p1 = p1->next;
	}

	while (p2)
	{
		Node *newNode = createNode(p2->coeff, p2->exp);
		if (result == NULL)
		{
			result = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		p2 = p2->next;
	}

	return result;
}

void printPolynomial(Node *head)
{
	if (head == NULL)
	{
		printf("0\n");
		return;
	}
	Node *curr = head;
	int first = 1;
	while (curr)
	{
		int abs_coeff = abs(curr->coeff);
		if (!first)
		{
			printf(curr->coeff > 0 ? " + " : " - ");
		}
		else if (curr->coeff < 0)
		{
			printf("-");
		}
		first = 0;

		if (abs_coeff != 1 || curr->exp == 0)
		{
			printf("%d", abs_coeff);
		}
		if (curr->exp > 0)
		{
			printf("x");
			if (curr->exp != 1)
			{
				printf("^%d", curr->exp);
			}
		}
		curr = curr->next;
	}
	printf("\n");
}

void freePolynomial(Node **head)
{
	Node *curr = *head;
	while (curr)
	{
		Node *temp = curr;
		curr = curr->next;
		free(temp);
	}
	*head = NULL;
}