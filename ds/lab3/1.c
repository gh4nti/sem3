/*
Write a program to perform following string operations without using string handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stringLength(char *str);
void stringConcat(char *res, char *str1, char *str2);
int stringCompare(char *str1, char *str2);
void stringInsert(char *str, char *sub, int pos);
void stringDelete(char *str, int pos, int len);

int main()
{
	char *str1, *str2, *res;
	int c, pos, len;

	str1 = (char *)malloc(MAX * sizeof(char));
	str2 = (char *)malloc(MAX * sizeof(char));
	res = (char *)malloc((2 * MAX) * sizeof(char)); // Allocate enough space for concatenation

	if (!str1 || !str2 || !res)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}

	printf("Enter the first string: ");
	fgets(str1, MAX, stdin);
	printf("Enter the second string: ");
	fgets(str2, MAX, stdin);

	// remove trailing newline character, if any
	if (str1[stringLength(str1) - 1] == '\n')
	{
		str1[stringLength(str1) - 1] = '\0';
	}
	if (str2[stringLength(str2) - 1] == '\n')
	{
		str2[stringLength(str2) - 1] = '\0';
	}

	while (1)
	{
		printf("\nChoose an operation:\n");
		printf("1. Length of the string\n");
		printf("2. Concatenate two strings\n");
		printf("3. Compare two strings\n");
		printf("4. Insert a substring\n");
		printf("5. Delete a substring\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);
		getchar();

		switch (c)
		{
		case 1:
			printf("Length of the first string: %d\n", stringLength(str1));
			printf("Length of the second string: %d\n", stringLength(str2));
			break;

		case 2:
			stringConcat(res, str1, str2);
			printf("Concatenated string: %s\n", res);
			break;

		case 3:
			if (stringCompare(str1, str2))
			{
				printf("The strings are equal.\n");
			}
			else
			{
				printf("The strings are not equal.\n");
			}
			break;

		case 4:
			printf("Enter the position to insert the substring: ");
			scanf("%d", &pos);
			getchar();

			printf("Enter the substring to insert: ");
			fgets(str2, MAX, stdin);

			// remove trailing newline from the substring if present
			if (str2[stringLength(str2) - 1] == '\n')
				str2[stringLength(str2) - 1] = '\0';

			if (pos >= 0 && pos <= stringLength(str1))
			{
				stringInsert(str1, str2, pos);
				printf("String after insertion: %s\n", str1);
			}
			else
			{
				printf("Invalid position for insertion.\n");
			}
			break;

		case 5:
			printf("Enter the position to delete the substring: ");
			scanf("%d", &pos);
			printf("Enter the length of the substring to delete: ");
			scanf("%d", &len);

			if (pos >= 0 && pos < stringLength(str1) && len >= 0 && pos + len <= stringLength(str1))
			{
				stringDelete(str1, pos, len);
				printf("String after deletion: %s\n", str1);
			}
			else
			{
				printf("Invalid position or length for deletion.\n");
			}
			break;

		case 6:
			printf("Exiting...\n");
			free(str1);
			free(str2);
			free(res);
			return 0;

		default:
			printf("Invalid choice! Please try again.\n");
		}
	}

	return 0;
}

int stringLength(char *str)
{
	int len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

void stringConcat(char *res, char *str1, char *str2)
{
	while (*str1 != '\0')
	{
		*res = *str1;
		res++;
		str1++;
	}

	while (*str2 != '\0')
	{
		*res = *str2;
		res++;
		str2++;
	}

	*res = '\0';
}

int stringCompare(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}

	return *str1 == *str2;
}

void stringInsert(char *str, char *sub, int pos)
{
	int subLength = stringLength(sub);
	int strLength = stringLength(str);
	int i;

	// Check if there is enough space to insert the substring
	// If not, print an error message and return
	if (strLength + subLength >= 100)
	{
		printf("Not enough space to insert the substring.\n");
		return;
	}

	// Shift the characters to make space for the substring
	for (i = strLength; i >= pos; i--)
	{
		*(str + i + subLength) = *(str + i);
	}

	// Insert the substring
	for (i = 0; i < subLength; i++)
	{
		*(str + pos + i) = *(sub + i);
	}

	// Null-terminate the string
	str[strLength + subLength] = '\0';
}

void stringDelete(char *str, int pos, int len)
{
	int i;
	int strLength = stringLength(str);

	// Shift the characters to overwrite the substring to be deleted
	for (i = pos; i <= strLength - len; i++)
	{
		*(str + i) = *(str + i + len);
	}

	// Null-terminate the string
	*(str + strLength - len) = '\0';
}