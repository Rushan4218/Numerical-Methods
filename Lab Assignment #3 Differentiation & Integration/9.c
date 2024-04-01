#include <stdio.h>
#include <math.h>

#define f(x) (exp(x))

double com_simpson_1(double x0, double x1, int k)
{
    double h = (x1 - x0) / k;
    double sum = f(x0) + f(x1);
    
    for (int i = 1; i < k; i++)
    {
        double xk = x0 + i * h;
        if (i % 2 == 0)
            sum += 2 * f(xk);
        else
            sum += 4 * f(xk);
    }

    return (h / 3) * sum;
}

int main()
{
    double x0, x1;
    printf("Enter the value of lower limit and upper limit: ");
    scanf("%lf %lf", &x0, &x1);
    
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    double result = com_simpson_1(x0, x1, k);
    printf("The value of the Integration is: %.6lf\n", result);

    return 0;
}
