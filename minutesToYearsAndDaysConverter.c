#include<stdio.h>

int main(void)
{
    double minutes;
    double years, days;
    double minutesInYear = 0;

    printf("Minutes: ");
    scanf("%lf", &minutes);

    minutesInYear = (60 * 24 * 365);
    days = (minutes / 60.0) / 24.0;
    years = (minutes / minutesInYear);

    printf("%lF minutes has %e days and %e years\n", minutes, days, years);

    return 0;
}