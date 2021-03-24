// Generate all prime numbers from 1 to 100

#include<stdio.h>
#include<stdbool.h>

#define SIZE 50

int main(void)
{
    // Declare an array of 101 numbers because index of an array starts at zero
    int prime[SIZE] = {2,3};
    int primeIndex = 2;

    /* Find all prime numbers starting at 5 but skipping all even numbers.
       Then loop through the prime numbers array and if the number is divisible 
       by the number in the prime array, mark it as not prime and exit the inner loop */
    for (int number = 5; number <= 100; number += 2) {
        bool isPrime = true; 
        for (int index = 0; index < primeIndex; index++) {
            if (number % prime[index] == 0) {
                isPrime = false;
                break;
            } 
        }
        if (isPrime == true) {
            prime[primeIndex] = number;
            primeIndex++;
        }
    }

    // Print all Prime numbers
    printf("\nPrime Numbers:\n");
    for (int index = 0; index < primeIndex; index++) {
        printf("%i ", prime[index]);
    }

    printf("\n\n");

    return 0;
}