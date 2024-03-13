// WAP to implement maxima and minima of tabulated function.

#include <stdio.h>
#include <math.h>

void findMaxMin(int n, double x[], double y[])
{
  double h = x[1] - x[0];
  double fd[n];

  for (int i = 0; i < n; i++)
  {
    fd[i] = y[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j >= i + 1; j--)
    {
      fd[j] = fd[j] - fd[j - 1];
    }
  }

  double a = fd[2] / 2;
  double b = fd[1] - fd[2];
  double c = fd[0] + fd[1] / 2 + fd[2] / 3;

  double S1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  double S2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
  double x1 = x[0] + S1 * h;
  double x2 = x[0] + S2 * h;

  double value = (fd[2] + (16 * S1 - 6) * fd[3] / 6) / (h * h);

  if (value < 0)
  {
    printf("The maxima at x is %lf\n", x1);
  }
  else
  {
    printf("The minima at x is %lf\n", x1);
  }

  value = (fd[2] + (16 * S2 - 6) * fd[3] / 6) / (h * h);

  if (value < 0) {
    printf("The maxima at x is %lf\n", x2);
  } else {
    printf("The minima at x is %lf\n", x2);
  }
}

int main()
{
  double x[] = {5, 6, 7, 8, 9};
  double y[] = {10, 14.5, 19.5, 22.5, 32.0};

  int n = sizeof(x) / sizeof(n);

  findMaxMin(n, x, y);
  return 0;
}
