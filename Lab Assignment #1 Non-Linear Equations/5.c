// WAP to implement synthetic division

#include <stdio.h>
#include <math.h>

int main()
{
  float poly[] = {-9, 15, -7, 1}; // x^3 - 7x^2 + 15x - 9
  float a = 3; //(x - 3)
  int n = sizeof(poly) / sizeof(float);
  float b[n];
  b[0] = 0;
  for (int i = n - 2; i >= 0; i--) {
    b[i] = poly[i + 1] + (a * b[i + 1]);
  }
  float rem = poly[0] * b[0] * a;

  printf("The given polynomial is: \n");
  for (int i = n - 1; i >= 0; i--) {
    printf("%f\t", poly[i]);
  }
  printf("\nThe quotient is: \n");
  for (int i = n - 1; i >= 0; i--) {
    printf("%f\t", b[i]);
  }
  printf("\nThe remainder is: %f", rem);
  return 0;
}