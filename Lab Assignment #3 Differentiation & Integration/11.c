#include <stdio.h>
#include <math.h>

#define f(x) (exp(x))

double com_simpson_2(double x0, double xn, int k)
{
    double h = (xn - x0) / k;
    double sum = f(x0) + f(xn);
    
    for (int i = 1; i < k; i++)
    {
        double xk = x0 + i * h;
        if (i % 2 == 0)
            sum += 2 * f(xk);
        else
            sum += 3 * f(xk);
    }
    double I= 3* (h/8) *sum;
    return I;
}

int main()
{
    double x0, x1;
    printf("Enter the value of lower limit and upper limit: ");
    scanf("%lf %lf", &x0, &x1);
    
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    double result = com_simpson_2(x0, x1, k);
    printf("The value of the Integration is: %.6lf\n", result);

    return 0;
}
