#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(1-pow(x,2)))

double simpson_threebyeight(double x0, double x3)
{
    double I;
    double h = (x3 - x0) / 3;
    double x1 = x0+h;
    double x2= x0+ 2*h;  
    double sum = f(x0) + 3 * f(x1) +3* f(x2)+ f(x3);
    I = 3 *(h / 8) * sum;
    return I;
}

int main()
{
    double x0, x3;
    printf("Enter the value of lower limit and upper limit: ");
    scanf("%lf %lf", &x0, &x3);

    double result = simpson_threebyeight(x0, x3);
    printf("The value of the integration is: %.6lf\n", result);

    return 0;
}
