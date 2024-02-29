
#include <stdio.h>

int sum(int a, int b);
void print_hello();

int main()
{
    int num1, num2;
    int add;
    void print_hello();

printf("Enter the first number: ");
scanf("%d", &num1);
printf("Enter the second number: ");
scanf("%d", &num2);
add = sum(num1, num2);
printf("The sum of %d and %d is %d\n", num1, num2, add);


    return 0;
}

int sum(int a, int b)
{
    int s = a + b;
    return s;
}
