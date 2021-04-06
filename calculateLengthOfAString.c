/******************************************************************************
 * Purpose: Tests your understanding of pointer arithmetic and const modifier
 * by writing a function that calculates the length of a string
 * Requirements:
 * 1) function should take as a parameter a const char pointer
 * 2) function can only determine the length of a string using pointer
 *    arithmetic
 * 3) Use a while loop using the value of the pointer to exit 
 * 4) The function should subtract two pointers (one pointing to the end of the
 *    string and the other pointing to the beginning of the string
 * 5) The function should return an int that is the length of the string passed
 *    into the function
 * ***************************************************************************/

#include<stdio.h>

int calcStringLength(const char * startPtr);

int main(void)
{
    //char string[] = "C is fun!";
    char string[1000];

    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    printf("The length of the string is %i.\n", calcStringLength(string));

    return 0;
}

int calcStringLength(const char * startPtr)
{
    const char * endPtr = startPtr;

    // Need to check for \n because fgets adds a newline character to the string
    while (*endPtr && *endPtr != '\n')
    {
        ++endPtr;
    }

    return endPtr - startPtr;
}