// composite trapezoidal rule

#include <stdio.h>
#include <math.h>
#define f(x) (exp(x))

double com_trapezoidal(double x0, double x1, int k)
{
    double I;
    double h = (x1 - x0) / k;
    double sum = f(x0) + f(1);
    for (int i = 1; i < k; i++)
    {
        sum += 2 * f(x0 + i * h);
    }
    I = (h / 2) * sum;
    return I;
}
int main()
{
    double x0, x1;
    printf("enter the value of lower limit and  upper limit: ");
    scanf("%lf %lf", &x0, &x1);
    int k;
    printf("enter the value of k: ");
    scanf("%d", &k);

    double result = com_trapezoidal(x0, x1, k);
    printf("The value of the Integration is: %lf\n", result);
}