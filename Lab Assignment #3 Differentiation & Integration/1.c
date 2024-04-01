//	derivative using forward difference formula.
#include <stdio.h>
#define f(x) ((x) * (x))

double derivative_forward(double h, double x)
{
    double dx= (f(x + h) - f(x))/h;
    return dx;

}

int main()
{
    double x, h;
    printf("Enter the value of x : ");
    scanf("%lf", &x);

    printf("Enter the value of h : ");
    scanf("%lf", &h);

    printf("the value of derivative is : %lf", derivative_forward(h, x));

    return 0;

}