// Write a program to implement Secant method.

#include <stdio.h>
#include <math.h>

#define f(x) pow(x, 2) - (4 * x) - 10

int main()
{
  float x0, x1, x2, f0, f1, f2, e;
  int iteration = 1;

  printf("Enter two initial points:\n");
  scanf("%f%f", &x0, &x1);
  printf("Enter the tolerable error: ");
  scanf("%f", &e);

  f0 = f(x0);
  f1 = f(x1);

  printf("Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\n");
  do
  {

    if (f0 == f1)
    {
      printf("Division by zero error!");
      return 1;
    }

    x2 = x1 - ((f1 * (x1 - x0)) / (f1 - f0));
    f2 = f(x2);

    printf("%d\t\t%lf\t%lf\t%lf\t%lf\n", iteration, x0, x1, x2, f2);

    x0 = x1;
    f0 = f1;
    x1 = x2;
    f1 = f2;

    iteration++;
  } while (fabs(f2) > e);

  printf("The root is %f", x2);

  return 0;
}