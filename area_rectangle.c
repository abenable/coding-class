#include <stdio.h>

double computeArea(double length, double width) {
    return length * width;
}

int main() {
    double length, width, area;

    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);

    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    area = computeArea(length, width);

    printf("The area of the rectangle is: %.2lf\n", area);

    return 0;
}
