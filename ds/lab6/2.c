/*
Multiply two polynomials using circular doubly linked list (with Header Node)
i. Represent each polynomial using a circular doubly linked list with a header node.
ii. Multiply each term of the first polynomial with every term of the second polynomial.
iii. Merge like terms during or after multiplication.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
	int coeff, exp;
	struct Term *prev, *next;
} Term;

Term *createHeader();
void insertTerm(Term *header, int coeff, int exp);
Term *multiplyPolynomials(Term *p1, Term *p2);
void printPolynomial(Term *header);
void freePolynomial(Term *header);

int main()
{
	Term *p1 = createHeader(), *p2 = createHeader();

	int n1;
	printf("Enter number of terms in first polynomial: ");
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		int c, e;
		printf("Enter coeff and exp for term %d: ", i + 1);
		scanf("%d %d", &c, &e);
		insertTerm(p1, c, e);
	}

	int n2;
	printf("Enter number of terms in second polynomial: ");
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		int c, e;
		printf("Enter coeff and exp for term %d: ", i + 1);
		scanf("%d %d", &c, &e);
		insertTerm(p2, c, e);
	}

	printf("First polynomial: ");
	displayPoly(p1);

	printf("Second polynomial: ");
	displayPoly(p2);

	Term *result = multiplyPolynomials(p1, p2);

	printf("Product: ");
	displayPoly(result);

	freePoly(p1);
	freePoly(p2);
	freePoly(result);

	return 0;
}

Term *createHeader()
{
	Term *header = (Term *)malloc(sizeof(Term));
	if (header == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	header->next = header;
	header->prev = header;
	header->coeff = 0;
	header->exp = -1;
	return header;
}

void insertTerm(Term *header, int coeff, int exp)
{
	if (coeff == 0)
		return;

	Term *curr = header->next;
	while (curr != header && curr->exp > exp)
	{
		curr = curr->next;
	}

	if (curr != header && curr->exp == exp)
	{
		curr->coeff += coeff;
		if (curr->coeff == 0)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr);
		}
		return;
	}

	Term *temp = (Term *)malloc(sizeof(Term));
	if (temp == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	temp->coeff = coeff;
	temp->exp = exp;
	temp->next = curr;
	temp->prev = curr->prev;
	curr->prev->next = temp;
	curr->prev = temp;
}

Term *multiplyPolynomials(Term *p1, Term *p2)
{
	Term *result = createHeader();
	Term *term1 = p1->next;
	while (term1 != p1)
	{
		Term *term2 = p2->next;
		while (term2 != p2)
		{
			int newCoeff = term1->coeff * term2->coeff;
			int newExp = term1->exp + term2->exp;
			insertTerm(result, newCoeff, newExp);
			term2 = term2->next;
		}
		term1 = term1->next;
	}
	return result;
}

void printPolynomial(Term *header)
{
	Term *curr = header->next;
	if (curr == header)
	{
		printf("0\n");
		return;
	}
	int first = 1;
	while (curr != header)
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

void freePolynomial(Term *header)
{
	Term *curr = header->next;
	while (curr != header)
	{
		Term *temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(header);
}