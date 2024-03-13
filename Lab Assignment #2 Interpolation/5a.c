// Linear least square approximation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int n;
  double a, b, sx = 0, sx2 = 0, sy = 0, sxy = 0;

  double x[] = {1, 2, 3, 4, 5};
  double y[] = {3, 5, 7, 10, 12};

  int n = sizeof(x) / sizeof(double);

  for (int i = 0; i < n; i++)
  {
    sx += x[i];
    sy += y[i];
    sxy += x[i] * y[i];
    sx2 += (x[i] * x[i]);
  }

  b = ((n * sxy) - sx * sy) / ((n * sx2) - (sx * sx));
  a = (sy / n) - ((b * sx) / n);

  printf("a = %lf \n", a);
  printf("b = %lf \n", b);

  return 0;
}