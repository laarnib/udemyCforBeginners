/******************************************************************************
 * Purpose: Test your understanding of dynamic memory allocation
 * Requirements:
 * 1) Write a program that allows a user to input a string.
 * 2) The program will print the text that was inputted.
 * 3) The program will utilize dynamic memory allocation.
 * 4) The user can enter the limit of the string they are entering.
 * 5) You can use this limit when invoking a malloc.
 * 6) The program should create a char pointer only, no character arrays.
 *****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char * strPtr = NULL;
    int size = 0;

    printf("What is the max size of the string?\n");
    printf("Be sure to allocate space for the null terminator and newline : ");
    scanf(" %i", &size);

    strPtr = (char *)malloc(size * sizeof(char));

    if(strPtr)
    {
        printf("Enter your string: ");
        scanf(" ");
        fgets(strPtr, size, stdin);
        
        printf("\nYou entered....\n\n");
        printf("%s\n\n", strPtr);
    }

    free(strPtr);
    strPtr = NULL;
    return 0;
}