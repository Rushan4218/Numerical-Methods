//WAP to implement Horner's method

#include <stdio.h>
#include <math.h>

int main() {

  float x;
  float poly[] = {-6, 5, -4, 3};
  int n = sizeof(poly) / sizeof(n);
  printf("Enter a point: ");
  scanf("%f", &x);
  float b[n];
  b[n - 1] = poly[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    b[i] = poly[i] + b[i + 1] * x;
  }
  printf("The functional value of given polynomial is %f", b[0]);
  return 0;
}