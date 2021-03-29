/* Requirements: 
 * 1. Write a program that displays a string in reverse order.
 * 2. Should read input from the keyboard
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    int size = 101, length = 0;
    char str[size];

    // Prompt user for a string
    printf("Enter a word or sentence. Must be less than 100 characters.\n");
    fgets(str, 101, stdin);

    // Get length of string
    length = strlen(str);
    
    // Reverse string
    printf("\nReverse : ");
    for (int i = length; i >= 0; i--)
    {
        printf("%c",str[i]);
    }
    printf("\n\n");

    return 0;
}