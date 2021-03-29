/* Requirements:
 * 1. Write a program that sorts strings using bubble sort. 
 * Contraints: Cannot scan multiple word strings
 *    Allowed  "one"
 *    Not allowed  "apple pie"
 */

#include<stdio.h>
#include<string.h>

#define SIZE 100
void sort(int numOfStrings, char arr[][SIZE]);

int main(void)
{
    int numOfStrings = 0, i = 0;

    printf("Input number of strings: ");
    scanf(" %i", &numOfStrings);

    char unsorted[numOfStrings][SIZE];
    char strInput[SIZE];

    printf("Input %i strings:\n", numOfStrings);
    
    while (i < numOfStrings) {
        scanf("%s", strInput);  
        strncpy(unsorted[i], strInput, sizeof(unsorted[i]));
        ++i;
    }

    // Sort strings
    sort(numOfStrings, unsorted);
    printf("\nThe strings appears after sorting: \n");
    for (int i = 0; i < numOfStrings; i++)
    {
        printf("%s\n", unsorted[i]);
    }

    return 0;
}

void sort(int numOfStrings, char arr[][SIZE])
{
    char temp[SIZE];
    int stringsLeft = numOfStrings, result = 0;

    while (stringsLeft > 1)
    {
        for (int i = 0; i < stringsLeft - 1; i++) {
            result = strcmp(arr[i], arr[i+1]);
            if (result > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
            }
        }
        --stringsLeft;
    }
}