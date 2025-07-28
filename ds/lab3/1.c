/*
Write a program to perform following string operations without using string handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring
*/

#include <stdio.h>

int stringLength(char *str);
void stringConcat(char *res, char *str1, char *str2);
int stringCompare(char *str1, char *str2);
void stringInsert(char *str, char *sub, int pos);
void stringDelete(char *str, int pos, int len);

int main()
{
	char *str1, *str2, *res;
	int c, pos, len;

	printf("Enter the first string: ");
	fgets(str1, sizeof(str1), stdin);
	printf("Enter the second string: ");
	fgets(str2, sizeof(str2), stdin);

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
			stringConcatenate(res, str1, str2);
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
			fgets(str2, sizeof(str2), stdin);

			// remove trailing newline from the substring if present
			if (str2[stringLength(str2) - 1] == '\n')
				str2[stringLength(str2) - 1] = '\0';
			stringInsert(str1, str2, pos);
			printf("String after insertion: %s\n", str1);
			break;

		case 5:
			printf("Enter the position to delete the substring: ");
			scanf("%d", &pos);
			printf("Enter the length of the substring to delete: ");
			scanf("%d", &len);
			stringDelete(str1, pos, len);
			printf("String after deletion: %s\n", str1);
			break;

		case 6:
			printf("Exiting...\n");
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
	char *original = str;

	for (char *temp = str + stringLength(str); temp >= str + pos; temp--)
	{
		*(temp + subLength) = *temp;
	}

	for (int i = 0; i < subLength; i++)
	{
		*(str + pos + i) = *(sub + i);
	}
}

void stringDelete(char *str, int pos, int len)
{
	for (char *tmp = str + pos; *(tmp + len) != '\0'; tmp++)
	{
		*tmp = *(tmp + len);
	}
}