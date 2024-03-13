//Write a program to implement Newton's divided difference interpolation.

#include <stdio.h>

double newtonsDDI(double x[], double y[], int n, double xi)
{
  double dd[n];
  for (int i = 0; i < n; i++) {
    dd[i] = y[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      dd[j] = (dd[j] - dd[j - 1]) / (x[j] - x[j - 1 - i]);
    }
  }

  double v = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      dd[i] *= (xi - x[j]);
    }
    v += dd[i];
  }
  return v;
}

int main() 
{
  double x[] = {1, 2, 3, 4};
  double y[] = {0, 0.3010, 0.4771, 0.6021};
  int n = sizeof(x) / sizeof(double);
  double xi;
  printf("Enter the value at which interpolated value is required: ");
  scanf("%lf", &xi);
  double interpolatedValue = newtonsDDI(x, y, n, xi);
  printf("The interpolated value is %lf", interpolatedValue);
  return 0;
}