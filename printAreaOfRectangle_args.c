// Calculates and prints the perimeter and area of a rectangle
// Input is provided as arguments when running the program

#include<stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    double width = 0.0, height = 0.0, perimeter = 0.0, area = 0.0;

    if (argc < 3 || argc > 3) {
        printf("Too few or many arguments. Only provided values for height and width.\n");
        return 1;
    }
    
    height = atof(argv[1]);
    width = atof(argv[2]);
    
    // Calculate rectangle's perimeter
    perimeter = 2 * (width + height);

    // Calculate rectangle's area
    area = width * height;

    // Print the results
    printf("Height = %.2lf\n Width = %.2lf\n Perimeter = %.2lf\n Area=%.2lf\n",
            height, width, perimeter, area);
    return 0;
}