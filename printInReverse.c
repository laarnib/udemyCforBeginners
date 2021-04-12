/******************************************************************************
 * Requirements:
 * Write a program that will print the contents of a file in reverse order. 
******************************************************************************/

#include<stdio.h>

int main(void)
{
    FILE *fp = NULL;
    int length = 0;
    char c;
    int i = 0;
    
    fp = fopen("printInReverse.c", "r");

    if(fp == NULL)
    {
        printf("File does not exist or can't open file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    
    length -= 1;
    while (length >= 0)
    {
        fseek(fp, length, SEEK_SET);
        printf("%c", fgetc(fp));
        length--;
    }

    printf("\n");

    fclose(fp);
    fp = NULL;

    return 0;
}