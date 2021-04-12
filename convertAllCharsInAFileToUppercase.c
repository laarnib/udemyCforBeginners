/******************************************************************************
 * Requirements:
 * Write a program that converts all characters of a file to uppercase and 
 * write the results out to a temporary file. Remove the original filename.
 * Then rename the temporary file to the original filename. Display the 
 * contents of the original file to standard output in uppercase.
 * ***************************************************************************/

#include<stdio.h>
#include<ctype.h>

int main(void)
{
    FILE * fpOriginal = NULL;
    FILE * fpTemp = NULL;
    char tempFile[20] = "temp.txt", orginalFile[20] = "file.txt";
    char c;

    // Open original file for reading
    fpOriginal = fopen(orginalFile, "r");

    // Open temporary file for writing
    fpTemp = fopen(tempFile, "w");

    // Check if file exists
    if (fpOriginal == NULL)
    {
        printf("File does not exist. Aborting...\n");
        return 1;
    }

    // Read each character in the file copy it to the temporary file.
    // If the character is in lowercase, convert it to uppercase.
    while((c = getc(fpOriginal)) != EOF)
    {
        if (islower(c))
        {
            fputc(c-32, fpTemp);
            continue;
        }

        fputc(c, fpTemp);
    }

    // Close original and temp files
    fclose(fpOriginal);
    fclose(fpTemp);
    fpOriginal = NULL;
    fpTemp = NULL;

    //Delete original file
    remove(orginalFile);
    
    // Rename temporary file to the name of the original file
    rename(tempFile, orginalFile);

    // Display contents of the file to the screen
    fpOriginal = fopen(orginalFile, "r");

    if (fpOriginal == NULL)
    {
        printf("Cannot read file or file does not exist.\n");
        return 1;
    }

    while ((c = fgetc(fpOriginal)) != EOF)
    {
        printf("%c", c);
    }

    return 0;
}