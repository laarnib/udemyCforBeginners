/* Requirements:
   1. Write a function that finds the greatest common divisor
      of two non-negative integer values and to return the results.
   2. Write a function to calculate the absolute value of a number.
      Must accept ints and floats.
   3. Write a function to compute the square root of a number without 
      using C's helper functions. If a negative value is passed then 
      a message is displayed and should return -1.0.
*/


#include<stdio.h>
#include<stdbool.h>

bool isNegative(float num);
int findGcd (int a, int b);
float getAbsoluteValue(float num);
long double calcSquareRoot(long double num);

int main(void)
{
    char option;
    int scanfValidItems = 0;

    // Prompt user on operation to perform
    printf("Choose from the following options:\n");
    printf("Enter g to get the greatest common divisor of two integral numbers.\n");
    printf("Enter a to get the absolute value of a number.\n");
    printf("Enter s to get the square root of a number.\n");
    scanf("%c", &option);

    // Get inputs and call operation selected by user
    switch(option)
    {
        case 'g' : {
            int x = 0, y = 0, gcd = 0;
            printf("Enter two non-negative integral numbers separated by space. ");
            scanfValidItems = scanf("%i %i", &x, &y);

            // Check if user entered valid values
            if (scanfValidItems < 2) {
                printf("\nYou entered an invalid value.\n\n");
            }
            else if (isNegative(x) || isNegative(y)) {
                printf("\nDecimal numbers and negative values are not allowed.\n\n");
            }
            else {
                gcd = findGcd(x, y);
                printf("\n\nThe greatest common divisor for  %i and %i is %i.\n\n", x, y, gcd);
            }
            break;
        }

        case 'a' : {
            float num = 0.0, absoluteValue = 0.0;

            printf("Enter a number: ");
            scanfValidItems = scanf("%f", &num);

            // Check if user entered a valid values
            if (scanfValidItems < 1) {
                printf("\nInvalid Value.\n\n");
            }
            else {
                absoluteValue = getAbsoluteValue(num);
                printf("\n\nThe absolute value of %0.2f is %0.2f.\n\n", num, absoluteValue);
            }
            break;
        }

        case 's' : {
            long double num = 0.0, squareRoot = 0.0;

            printf("Enter a number: ");
            scanfValidItems = scanf("%Lf", &num);

            squareRoot = calcSquareRoot(num);
            if (scanfValidItems < 1) {
                printf("\nInvalid Value.\n\n");
            }
            else if (squareRoot < 0) {
                printf("\nError: You entered a negative value.\n\n");
            }
            else {
                printf("\nThe square root of %0.2Lf is %0.2Lf\n\n", num, squareRoot);
            }
            break;
        }

        default:
            printf("\nInvalid option.\n");
            break;
    }

    return 0;
}

// Checks if number is negative
bool isNegative(float num)
{
    if (num < 0) {
        return true;
    }
    else {
        return false;
    }
}

// Finds the greatest common divisior of two non-negative integral values
int findGcd (int a, int b)
{
    if (b == 0) {
        return a;
    } 
    else {
        return findGcd(b, a % b);
    }
}

// Gets the absolute value of a number
float getAbsoluteValue(float num)
{
    if (isNegative(num)) {
        return num * -1;
    }
    else {
        return num;
    }
}

// Find the square root of a number using bisection search
long double calcSquareRoot(long double num)
{
    long double guess = 0.0, epsilon = 0.0001, low = 0.0, high = 0.0;

    // Check if number is negative and return an error
    if (isNegative(num)) {
        return -1;
    }
    else {
        high = num;

        // Find the midpoint between the low and high values and that will be the first guess
        guess = (high + low) / 2;

        // Keep guessing for the square root until you get very close to num
        while (getAbsoluteValue(guess * guess - num) >= epsilon)
        {
            if ((guess * guess) > num) {
                high = guess;
            }
            else {
                low = guess;
            }
            guess = (high + low) / 2;
        }
    }
    return guess;
}