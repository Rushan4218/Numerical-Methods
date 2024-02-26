// WAP to implement Newton Raphson Method

#include <stdio.h>
#include <math.h>

#define f(x) pow(x, 2) - (3 * x) + 2
#define df(x) 2 * x - 3

float findRoot(float x0, float e, int iteration)
{
  float f0, df0, x1;
  iteration++;
  f0 = f(x0);
  df0 = df(x0);
  x1 = x0 - (f0 / df0);
  if (fabs(f0) < e)
    return x0;
  printf("%d\t\t%f\t%f\t%f\n", iteration, x0, x1, f0);
  return findRoot(x1, e, iteration);
}

int main()
{

  float x0, e;

  printf("Enter the initial point: ");
  scanf("%f", &x0);
  printf("Enter tolerable error: ");
  scanf("%f", &e);

  printf("Iteration\tx0\t\tx1\t\tf0\n");
  float root = findRoot(x0, e, 0);
  printf("The root is %f", root);

  return 0;
}