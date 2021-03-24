/* This program will find the total rainfall for each year,
the average yearly rainfall, and the average rainfall for 
each month. */

#include<stdio.h>
#define MONTHS 12
#define YEARS 5

int main(void) {
    int start_year = 2015;
    float total = 0.0, yearly_avg = 0.0;
    float rainfall[YEARS][MONTHS] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    // Get average rainfall each year
    printf("\nYEAR    RAINFALL (inches)\n");
    for (int i = 0; i < YEARS; i++) {
        float total_per_year = 0.0, per_year_avg = 0.0;

        for (int j = 0; j < MONTHS; j++) {
            total_per_year += rainfall[i][j];
        }

        total += total_per_year;

        printf("%i %10.1f\n", start_year, total_per_year);
        start_year += 1;
    }

    yearly_avg = total / YEARS;
    printf("\n\nThe yearly average is %.1f inches.\n\n", yearly_avg);

    // Get monthly average rainfall
    printf("MONTHLY AVERAGES:\n\n");
    printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    for (int month = 0; month < MONTHS; month++) {
        float monthly_sum = 0.0, monthly_avg = 0.0;

        for (int i = 0; i < YEARS; i++) {
            monthly_sum += rainfall[i][month];
        }
        monthly_avg = monthly_sum / YEARS;
        printf("%0.1f  ", monthly_avg);
    }

    printf("\n\n");

    return 0;
}