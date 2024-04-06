//	derivative using backward difference formula.
#include <stdio.h>
#define f(x) ((x) * (x))

double derivativeBackward(double h, double x)
{
    double dx = (f(x) - f(x - h)) / h;
    return dx;
}

int main()
{
    double x, h;
    printf("Enter the value of x : ");
    scanf("%lf", &x);

    printf("Enter the value of h : ");
    scanf("%lf", &h);

    printf("the value of derivative is : %lf", derivativeBackward(h, x));

    return 0;
}