// backward divided difference
#include <stdio.h>

double backwardDividedDifference(int n, double value, double x[], double f[])
{
    double bd[n];
    for (int i = 0; i < n; i++)
    {
        bd[i] = f[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            bd[j] = (bd[j + 1] - bd[j]) / (x[j + n - i] - x[j]);
        }
    }

    double val = bd[n - 1]; 
    double factor = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        double term = 1.0;
        for (int j = n - 1; j > i; j--)
        {
            term *= (value - x[j]);
        }
        val += (bd[i] * term);
    }
    return val;
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], f[n];
    printf("Enter the values of x(n):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Value of x(%d): ", i);
        scanf("%lf", &x[i]);
    }

    printf("Enter the values of f(n):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Value of f(%d): ", i);
        scanf("%lf", &f[i]);
    }

    printf("Enter the value of x for which you want to find the value of the polynomial: ");
    double value;
    scanf("%lf", &value);

    double result = backwardDividedDifference(n, value, x, f);
    printf("The value of the derivative is: %lf\n", result);

    return 0;
}
