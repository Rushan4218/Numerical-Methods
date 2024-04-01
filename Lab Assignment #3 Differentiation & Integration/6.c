// trapazoial rule

#include <stdio.h>
#define f(x) ((x) * (x) * (x) + 2)

double trapezoidal(double x0, double x1)
{
    double h = x1 - x0;
    double I = (h / 2) * (f(x0) + f(x1));
    return I;
}
int main()
{
    double x0, x1;
    printf("enter the value of lower limit and  upper limit: ");
    scanf("%lf %lf", &x0, &x1);

    double result = trapezoidal(x0, x1);
    printf("The value of the Integration is: %lf\n", result);
}