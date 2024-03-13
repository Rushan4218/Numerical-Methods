// WAP to implement exponential regression.

#include <stdio.h>
#include <math.h>

void exponential_reg(int n, double x[], double y[])
{
  double Sx = 0.0;
  double Slogy = 0.0;
  double SxLogy = 0.0;
  double Sx2 = 0.0;

  for (int i = 0; i < n; ++i)
  {
    Sx += x[i];
    Slogy += log(y[i]);
    SxLogy += x[i] * log(y[i]);
    Sx2 += x[i] * x[i];
  }

  double b = ((n * SxLogy) - (Sx * Slogy)) / ((n * Sx2) - (Sx * Sx));
  double loga = (Slogy / n) - (b * Sx / n);
  double a = exp(loga);

  printf("a = %lf\n", a);
  printf("b = %lf\n", b);
  printf("f(x) = %lf * e^(%lf * x)\n", a, b);
}

int main()
{
  double x[] = {0.4, 0.8, 1.2, 1.6, 2, 2.3};
  double y[] = {750, 1000, 1400, 2000, 2700, 3750};

  int n = sizeof(x) / sizeof(double);
  exponential_reg(n, x, y);

  return 0;
}
