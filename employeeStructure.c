/******************************************************************************
 * Requirements:
 * 1)Create an employee structure with 3 members
 *   - name (character array)
 *   - hireDate (int)
 *   - salary (float)
 * 2) Read in a second employee from the console and store it in a structure
 *   of the type employee
 * 3) Print out the contents of each employee
 *****************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME_SIZE 100

struct Employee {
    char name[NAME_SIZE];
    int month;
    int day;
    int year;
    float salary;
};

int main(void)
{
    int numberOfEmployees = 0, i = 0;

    printf("How many employee data do you want to enter? ");
    scanf(" %i", &numberOfEmployees);
    
    struct Employee employees[numberOfEmployees];
    
    while (i < numberOfEmployees)
    {
        system("clear");
        printf("Enter data for Employee #%i\n", i+1);
        printf("Name: ");
        scanf(" ");
        fgets(employees[i].name, NAME_SIZE, stdin);

        printf("Hire Date: ");
        scanf("%i/%i/%i", &employees[i].month, &employees[i].day, &employees[i].year);
        
        printf("Salary: ");
        scanf(" %f", &employees[i].salary);

        ++i;
    }

    // Print employee information
    system("clear");
    printf("\n\nPrinting Employee Data....\n\n");
    for (int i = 0; i < numberOfEmployees; i++)
    {
        printf("Name: %s", employees[i].name);
        printf("Hire Date: %i/%i/%i\n", employees[i].month, employees[i].day, employees[i].year);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }

    return 0;
}