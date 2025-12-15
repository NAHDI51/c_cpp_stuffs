#include <stdio.h>
#include <math.h> 

#define PI 3.14159f

// Trapezoid area
int main() {
    double area;
    double height;
    double a, b;

    printf("Enter your height: ");
    scanf("%lf", &height);

    printf("Enter value of a: ");
    scanf("%lf", &a);

    printf("Enter value of b: ");
    scanf("%lf", &b);

    area = height * 0.5 * (a+b);

    printf("Your area is: %lf\n", area);
    printf("The size of double: %d\n", (int) sizeof(area));

    int aa;
    printf("The size of integer: %d\n", (int) sizeof(aa));

    return 0;
}