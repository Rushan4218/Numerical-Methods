// WAP to implement Bisection Method.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(int degree, float coeff[], float x)
{

  double result = 0;

  for (int i = 0; i <= degree; i++)
  {
    result = result + coeff[i] * pow(x, degree - i);
  }
  return result;
}

int main()
{
  int degree;
  float coeff[10];
  printf("Enter the degree: ");
  scanf("%d", &degree);

  for (int i = 0; i <= degree; i++)
  {
    coeff[i] = 0.0; // garbage value hatayera 0.0 haleko, fixed a bug
    printf("Enter the coefficient for x^%d: ", degree - i);
    scanf("%f", &coeff[i]);
  }

  float x0, x1, x2, f0, f1, f2, e, pf;
  int iteration = 1;
top:
  printf("\nEnter initial two guesses:\n");
  scanf("%f%f", &x0, &x1);
  printf("Enter tolerable error:\n");
  scanf("%f", &e);

  f0 = f(degree, coeff, x0);
  f1 = f(degree, coeff, x1);

  if (f0 * f1 > 0.0)
  {
    printf("The root doesn't lie between the points %f and %f", x0, x1);
    goto top;
  }

  printf("Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\n");

  do
  {
    x2 = (x0 + x1) / 2;
    f2 = f(degree, coeff, x2);

    printf("%d\t\t%f\t%f\t%f\t%f\n", iteration, x0, x1, x2, f2);

    if (f0 * f2 > 0.0)
    {
      x0 = x2;
      f0 = f2;
    }
    else
    {
      x1 = x2;
      f1 = f2;
    }
    iteration++;

  } while (fabs(f2) > e);

  printf("The root is %f", x2);

  return 0;
}
