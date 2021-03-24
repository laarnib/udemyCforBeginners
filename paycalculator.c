/* C program that calculates your weekly pay.

Requirements:
1. Ask the user to enter the number of hours worked in a week.
2. Display the output as gross pay, the taxes, and the net pay.

Assumptions:
- Basic pay rate = $12.00/hr
- Overtime (in excess of 40 hours) = time and a half
- Tax rate:
  - 15% of the first $300
  - 20% of the next $150
  - 25% of the rest
  */

 #include<stdio.h>

#define PAY_RATE 12.00
#define OVERTIME_RATE 1.5
#define TAXRATE_300 0.15
#define TAXRATE_150 0.20
#define TAXRATE_REM 0.25
#define REGULAR_HOURS 40

int main(void)
{
    float gross_pay = 0.0, net_pay = 0.0, tax = 0.0;
    int hours = 0;

    // Promp user for number of hours worked
    printf("Hours worked: ");
    scanf("%i", &hours);

    // Calculate gross pay
    if (hours > REGULAR_HOURS) {
        int overtime = hours - REGULAR_HOURS;
        gross_pay = (REGULAR_HOURS * PAY_RATE) + (overtime * (PAY_RATE * OVERTIME_RATE));
    }
    else {
        gross_pay = hours * PAY_RATE;
    }

    // Calculate taxes
    if (gross_pay > 0 && gross_pay <= 300) {
        tax = gross_pay * TAXRATE_300;
    }
    else if ((gross_pay > 300) && (gross_pay <= 450)){
        tax = (300 * TAXRATE_300) + ((gross_pay - 300) * TAXRATE_150);
    }
    else if (gross_pay > 450) {
        tax = (300 * TAXRATE_300) + (150 * TAXRATE_150) + ((gross_pay - 300 - 150) * TAXRATE_REM);
    }
    else {
        tax = 0.0;
    }

    // Calculate net pay
    net_pay = gross_pay - tax;

    // Display gross pay, taxes, and net pay 
    printf("********************************\n");
    printf("Gross Pay: $%0.2f\n", gross_pay);
    printf("Taxes: $%0.2f\n", tax);
    printf("Net Pay: $%0.2f\n", net_pay);
    printf("********************************\n");

    return 0;
}


