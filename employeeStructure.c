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

typedef struct Employee {
    char name[NAME_SIZE];
    int month;
    int day;
    int year;
    float salary;
} EMPLOYEE;

void get_employee_data(EMPLOYEE * employeePtr);
void print_data(EMPLOYEE const * employeePtr);

int main(void)
{
    int employee_size = 0, i = 0;

    printf("How many employee data do you want to enter? ");
    scanf(" %i", &employee_size);
    
    EMPLOYEE employees[employee_size], * employeePtr = NULL;
    
    employeePtr = employees;
    
    while (i < employee_size)
    {
        system("clear");
        printf("Enter data for Employee #%i\n", i + 1);
        get_employee_data(employeePtr + i);
        ++i;
    }

    // Print employee information
    system("clear");
    printf("\n\nPrinting Employee Data....\n\n");
    for (i = 0; i < employee_size; i++)
    {
        print_data(employeePtr + i);
    }

    return 0;
}

void get_employee_data(EMPLOYEE * employeePtr)
{
    printf("Name: ");
    scanf(" ");
    fgets(employeePtr->name, NAME_SIZE, stdin);

    printf("Hire Date: ");
    scanf("%i/%i/%i", &employeePtr->month, &employeePtr->day, &employeePtr->year);
    
    printf("Salary: ");
    scanf(" %f", &employeePtr->salary);
}

void print_data(EMPLOYEE const * employeePtr)
{   
    printf("Name: %s", employeePtr->name);
    printf("Hire Date: %i/%i/%i\n", employeePtr->month, employeePtr->day, employeePtr->year);
    printf("Salary: %.2f\n\n", employeePtr->salary);
}