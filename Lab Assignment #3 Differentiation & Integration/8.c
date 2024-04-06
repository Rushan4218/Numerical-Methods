#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(1-pow(x,2)))

double simpsonOneByThree(double x0, double x2)
{
    double I;
    double h = (x2 - x0) / 2;
    double x1 = x0+h;
    double sum = f(x0) + 4 * f(x1) + f(x2);
    I = (h / 3) * sum;
    return I;
}

int main()
{
    double x0, x2;
    printf("Enter the value of lower limit and upper limit: ");
    scanf("%lf %lf", &x0, &x2);

    double result = simpsonOneByThree(x0, x2);
    printf("The value of the integration is: %lf\n", result);

    return 0;
}
