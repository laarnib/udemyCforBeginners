// Calculates and prints the perimeter and area of a rectangle

#include<stdio.h>

int main(void)
{
    double width = 0.0, height = 0.0, perimeter = 0.0, area = 0.0;

    // Prompt user for height and width of rectangle
    printf("Rectangle Perimeter and Area Calculator\n");
    printf("Please provide the height and width of your rectangle: ");
    scanf("%lf %lf", &height, &width);

    // Calculate rectangle's perimeter
    perimeter = 2 * (width + height);

    // Calculate rectangle's area
    area = width * height;

    // Print the results
    printf("Height = %.2lf\n Width = %.2lf\n Perimeter = %.2lf\n Area=%.2lf\n",
            height, width, perimeter, area);
    return 0;
}