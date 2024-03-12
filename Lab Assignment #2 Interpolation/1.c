// WAP to implement Larange's interpolation

#include <stdio.h>

double larangeInterpolation(int n, double x[], double y[], double xi)
{
  double lix[n];

  for (int i = 0; i < n; i++) {
    double result = 1.0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        result *= (xi - x[j]) / (x[i] - x[j]); 
      }
    }
    lix[i] = result;
  }
  double result = 0;

  for (int i = 0; i < n; i++) {
    result += lix[i] * y[i];
  }

  return result;
}
int main()
{
  double x[] = {0, 10, 15, 20, 30};
  double y[] = {0, 227.04, 362.78, 517.35, 901.67};
  int n = sizeof(x) / sizeof(double);
  double xi;
  printf("Enter the value at which value is needed: ");
  scanf("%lf", &xi);

  double interpolatedValue = larangeInterpolation(n, x, y, xi);
  printf("The value at %lf is %lf", xi, interpolatedValue);

  return 0;
}