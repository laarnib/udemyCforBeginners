/******************************************************************************
 * Purpose: To test understanding of pas sby reference
 * Requirements:
 * 1) Write a function that squares a number by itself.
 * 2) function should define as a parameter an int pointer.
 * 3) Print out the value of the pointer that you passed to the function.
 *****************************************************************************/

#include<stdio.h>

void square(int * number);

int main(void)
{
    int number = 0;

    printf("Enter a number: ");
    scanf(" %i", &number);

    printf("The square of %i ", number);
    square(&number);
    printf("is %i.\n", number);
    return 0;
}

void square(int * number)
{
    *number *= *number;
    return;
}