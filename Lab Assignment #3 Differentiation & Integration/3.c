//	derivative using central difference formula.
#include <stdio.h>
#define f(x) ((x) * (x))

double derivativeCentral(double h, double x)
{
    double dx = (f(x + h) - f(x - h)) / (2 * h);
    return dx;
}

int main()
{
    double x, h;
    printf("Enter the value of x : ");
    scanf("%lf", &x);

    printf("Enter the value of h : ");
    scanf("%lf", &h);

    printf("the value of derivative is : %lf", derivativeCentral(h, x));

    return 0;
}