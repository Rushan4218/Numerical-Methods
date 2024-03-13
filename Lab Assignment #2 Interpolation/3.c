// WAP to implement Newton's forward difference formula.

#include <stdio.h>

int fact(int x)
{
  if (x <= 1)
    return 1;
  return x * fact(x - 1);
}
double newtonsFD(double x[], double y[], int n, double xi)
{

  double h = x[1] - x[0];

  double s = (xi - x[0]) / h;

  double fd[n];
  for (int i = 0; i < n; i++)
  {
    fd[i] = y[i];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j > i; j--)
    {
      fd[j] = fd[j] - fd[j - 1];
    }
  }

  double v = 0.0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      fd[i] *= (s - j);
    }
    fd[i] /= fact(i);
    v += fd[i];
  }
  return v;
}

int main()
{
  double x[] = {10, 20, 30, 40, 50};
  double y[] = {0.1736, 0.3420, 0.5000, 0.6428, 0.7660};
  int n = sizeof(x) / sizeof(double);
  double xi;
  printf("Enter the value at which interpolated value is required: ");
  scanf("%lf", &xi);

  double interpolatedValue = newtonsFD(x, y, n, xi);
  printf("The interpolated value is %lf", interpolatedValue);

  return 0;
}