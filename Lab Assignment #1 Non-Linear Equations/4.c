// WAP to implement fixed point iteration method

#include <stdio.h>
#include <math.h>

// f(x) = cos(x) - (3 * x) + 1

#define p(x) (cos(x) + 1) / 3

float findRoot(float x0, float e, int iteration) {
  iteration++;
  float x1 = p(x0);
  printf("%d\t\t%f\t%f\n", iteration, x0, x1);
  if (fabs(x1 - x0) < e) return x0;
  return findRoot(x1, e, iteration);
}

int main()
{
  float x0, p0, e, root;

  printf("Enter the initial guess: ");
  scanf("%f", &x0);
  printf("Enter the tolerable error: ");
  scanf("%f", &e);

  printf("iteration\tx0\t\tx1\n");
  root = findRoot(x0, e, 0);
  printf("The root is %f", root);
  return 0;
}
