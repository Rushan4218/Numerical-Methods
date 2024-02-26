// WAP to implement Bisection Method.

#include <stdio.h>
#include <math.h>

#define f(x) pow(x, 3) - (4 * x) - 9


int main()
{
  float x0, x1, x2, f0, f1, f2, e, pf;
  int iteration = 1;
  top:
  printf("\nEnter initial two guesses:\n");
  scanf("%f%f", &x0, &x1);
  printf("Enter tolerable error:\n");
  scanf("%f", &e);

  f0 = f(x0);
  f1 = f(x1);

  if (f0 * f1 > 0.0) {
    printf("The root doesn't lie between the points %f and %f", x0, x1);
    goto top;
  }

  printf("Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\n");

  do {
    x2 = (x0 + x1) / 2;
    f2 = f(x2);

    printf("%d\t\t%f\t%f\t%f\t%f\n", iteration, x0, x1, x2, f2);

    if (f0 * f2 > 0.0) {
      x0 = x2;
      f0 = f2;
    } else {
      x1 = x2;
      f1 = f2;
    }
    iteration++;

  } while(fabs(f2) > e);

  printf("The root is %f", x2);

  return 0;
}


