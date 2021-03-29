/* Requirements:
 * 1. Write a program that tests your understanding of char arrays.
 * 2. Write a function to count the number of characters in a string.
 * 3. Write a function to concatenate two strings. 
 *    - should take three parameters:
 *      - char result[]
 *      - const char str1[]
 *      - const char str2[]
 * 4. Write a function that determines if two strings are equal.
 *
 */

#include<stdio.h>
#include<stdbool.h>

int getStrLength(const char str[]);
void concatenate(const char str1[], const char str2[], char result[]);
bool compareStrings(const char str1[], const char str2[]);

int main(void)
{
    char result[100];
    int length = 0;
    bool isEqual = false;

    char str1[100] = "Hello World", str2[100] = "hello";

    // Get string length
    length = getStrLength(str1);
    printf("%s has %i letters.\n", str1, length);

    length = getStrLength("Hello");
    printf("%s has %i letters.\n", str2, length);

    // Concatenate the two strings
    concatenate(str1, str2, result);
    printf("result = %s\n", result);

    // Compare strings
    isEqual = compareStrings(str1, str2) ? printf("Equal\n") : printf("Not Equal\n");
    return 0;
}

// Gets the length of a string
int getStrLength(const char str[])
{
    int count = 0;

    while (str[count] != '\0')
    {
        ++count;
    }

    return count;
}

// Concatenate two strings
void concatenate(const char str1[], const char str2[], char result[])
{
    int i = 0, j = 0;

    while (str1[i] != '\0')
    {
        result[i] = str1[i];
        ++i;
    }

    while (str2[j] != '\0')
    {
        result[i + j] = str2[j];
        ++j;
    }

    result[i + j] = '\0';

    return;
}

// Compare if the two strings are equal
bool compareStrings(const char str1[], const char str2[])
{
    int i = 0;

    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i]) {
            return false;
        }
        ++i;
    }

    return true;
}