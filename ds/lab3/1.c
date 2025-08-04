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
    char *str1, *str2, *res, *sub;
    int c, pos, len;

    str1 = (char *)malloc(MAX * sizeof(char));
    str2 = (char *)malloc(MAX * sizeof(char));
    res = (char *)malloc(2 * MAX * sizeof(char)); // Allocate enough space for concatenation
    sub = (char *)malloc(MAX * sizeof(char));  // Space for substring input

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
    if (str1[stringLength(str1) - 1] == '\n')
        str1[stringLength(str1) - 1] = '\0';
    if (str2[stringLength(str2) - 1] == '\n')
        str2[stringLength(str2) - 1] = '\0';

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
            getchar();  // to clear the newline

            printf("Enter the substring to insert: ");
            fgets(sub, MAX, stdin);
            sub[stringLength(sub) - 1] = '\0';  // Remove the newline character

            if (pos >= 0 && pos <= stringLength(str1))
            {
                stringInsert(str1, sub, pos);
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
            free(sub);
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

    // Ensure enough space for the new substring
    if (strLength + subLength >= MAX)
    {
        printf("Not enough space to insert the substring.\n");
        return;
    }

    // Shift the characters to make space for the substring
    for (int i = strLength - 1; i >= pos; i--)
    {
        *(str + i + subLength) = *(str + i);
    }

    // Insert the substring
    for (int i = 0; i < subLength; i++)
    {
        *(str + pos + i) = *(sub + i);
    }

    // Null-terminate the string
    str[strLength + subLength] = '\0';
}

void stringDelete(char *str, int pos, int len)
{
    int strLength = stringLength(str);

    // Shift characters to the left to delete the substring
    for (int i = pos; i < strLength - len; i++)
    {
        *(str + i) = *(str + i + len);
    }

    // Null-terminate the string
    *(str + strLength - len) = '\0';
}
