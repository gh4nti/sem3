/*
Write a program to perform following string operations without using string handling functions:
- length of the string
- string concatenation
- string comparison
- to insert a sub string
- to delete a substring
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int strLength(char *str);
void strConcat(char *res, char *str1, char *str2);
int strCompare(char *str1, char *str2);
void strInsert(char *str, char *sub, int pos);
void strDelete(char *str, int pos, int len);

int main()
{
	char *str1, *str2, *res, *sub;
	int pos, len;

	str1 = (char *)malloc(MAX * sizeof(char));
	str2 = (char *)malloc(MAX * sizeof(char));
	res = (char *)malloc(2 * MAX * sizeof(char)); // Allocate enough space for concatenation
	sub = (char *)malloc(MAX * sizeof(char));	  // Space for substring input

	if (!str1 || !str2 || !res || !sub)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}

	printf("Enter the first string: ");
	fgets(str1, MAX, stdin);

	printf("Enter the second string: ");
	fgets(str2, MAX, stdin);

	// remove trailing newline character, if any
	if (str1[strLength(str1) - 1] == '\n')
		str1[strLength(str1) - 1] = '\0';
	if (str2[strLength(str2) - 1] == '\n')
		str2[strLength(str2) - 1] = '\0';

	printf("\nString Operations:\n");

	// Length
	printf("Length of the first string: %d\n", strLength(str1));
	printf("Length of the second string: %d\n", strLength(str2));

	// Concatenation
	strConcat(res, str1, str2);
	printf("Concatenated string: %s\n", res);

	// Comparison
	if (strCompare(str1, str2))
	{
		printf("The strings are equal.\n");
	}

	else
	{
		printf("The strings are not equal.\n");
	}

	// Insertion
	printf("Enter the position to insert the substring: ");
	scanf("%d", &pos);
	getchar(); // to clear the newline

	printf("Enter the substring to insert: ");
	fgets(sub, MAX, stdin);
	sub[strLength(sub) - 1] = '\0'; // Remove the newline character

	if (pos >= 0 && pos <= strLength(str1))
	{
		strInsert(str1, sub, pos);
		printf("String after insertion: %s\n", str1);
	}

	else
	{
		printf("Invalid position for insertion.\n");
	}

	// Deletion
	printf("Enter the position to delete the substring: ");
	scanf("%d", &pos);
	printf("Enter the length of the substring to delete: ");
	scanf("%d", &len);

	if (pos >= 0 && pos < strLength(str1) && len >= 0 && pos + len <= strLength(str1))
	{
		strDelete(str1, pos, len);
		printf("String after deletion: %s\n", str1);
	}

	else
	{
		printf("Invalid position or length for deletion.\n");
	}

	free(str1);
	free(str2);
	free(res);
	free(sub);
	return 0;
}

int strLength(char *str)
{
	int len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

void strConcat(char *res, char *str1, char *str2)
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

int strCompare(char *str1, char *str2)
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

void strInsert(char *str, char *sub, int pos)
{
	int subl = strLength(sub);
	int strl = strLength(str);

	// Ensure enough space for the new substring
	if (strl + subl >= MAX)
	{
		printf("Not enough space to insert the substring.\n");
		return;
	}

	// Shift the characters to make space for the substring
	for (int i = strl - 1; i >= pos; i--)
	{
		*(str + i + subl) = *(str + i);
	}

	// Insert the substring
	for (int i = 0; i < subl; i++)
	{
		*(str + pos + i) = *(sub + i);
	}

	// Null-terminate the string
	str[strl + subl] = '\0';
}

void strDelete(char *str, int pos, int len)
{
	int strl = strLength(str);

	// Shift characters to the left to delete the substring
	for (int i = pos; i < strl - len; i++)
	{
		*(str + i) = *(str + i + len);
	}

	// Null-terminate the string
	*(str + strl - len) = '\0';
}
