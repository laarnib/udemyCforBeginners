/******************************************************************************
 * Requirements:
 * 1) Write a program to find the total number of lines in a text file.
 * 2) Create a file that contains some lines of text.
 * 3) Open your test file.
 * 4) Use the fgetc function 
 * 5) Display as output the total number of lines in the file.
 *****************************************************************************/


#include<stdio.h>

int main(void)
{
    FILE *fp = NULL;
    char c;
    int count = 0;

    fp = fopen("countLines.c", "r");
    
    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
        {
            ++count;
        }
    }

    printf("Total number of lines : %i\n", count + 1); // Add 1 to count to count the last line in the text file

    fclose(fp);
    fp = NULL;
    return 0;
}