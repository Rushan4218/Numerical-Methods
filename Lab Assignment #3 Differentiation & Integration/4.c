// forward DD
#include <stdio.h>

double forward_DD(int n, double value, double x[], double f[])
{
    double fd[n];
    for (int i = 0; i < n; i++)
    {
        fd[i] = f[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= i + 1; j--)
        {
            fd[j] = (fd[j] - fd[j - 1]) / (x[j] - x[j - i - 1]);
        }
    }

    double val = fd[0]; 
    double factor = 1;
    for(int i = 1; i < n; i++ )
    {
        double term = 1.0;
        for(int j = 0; j < i; j++)
        {
            term *= (value - x[j]);
        }
        val += (fd[i] * term);
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

    double result = forward_DD(n, value, x, f);
    printf("The value of the derivative is: %lf\n", result);

    return 0;
}
