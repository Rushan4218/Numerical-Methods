// WAP to implement Newton's backward differenciation formula

#include <stdio.h>

int fact(int x)
{
  if (x <= 1)
    return 1;
  return x * fact(x - 1);
}

double newtonsBD(double x[], double y[], double xi, int n)
{
  double h = x[1] - x[0];
  double s = (xi - x[n - 1]) / h;
  double bd[n];
  for (int i = 0; i < n; i++)
  {
    bd[i] = y[i];
  }

  for (int i = n - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      bd[j] = bd[j + 1] - bd[j];
    }
  }

  double v = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      bd[i] *= (s + j);
    }
    bd[i] /= fact(n - i - 1);
    v += bd[i];
  }

  return v;
}

int main()
{
  double x[] = {100, 150, 200, 250, 300, 350, 400};
  double y[] = {10.63, 13.03, 15.04, 16.81, 18.42, 19.90, 21.27};
  int n = sizeof(x) / sizeof(double);
  double xi;
  printf("Enter the value where interpolated value is required: ");
  scanf("%lf", &xi);

  double interpolatedValue = newtonsBD(x, y, xi, n);
  printf("The interpolated value is %lf", interpolatedValue);

  return 0;
}