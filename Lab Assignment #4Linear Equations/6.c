//Program to implement Cholesky Decomposition Method

#include <stdio.h>
#include <math.h>

void choleskyDecomposition(double matrix[][3], double L[][3], double U[][3])
{
  int n = 3;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      L[i][j] = 0.0;
    }
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      double sum = 0.0;
      if (j == i)
      {
        for (int k = 0; k < j; ++k)
        {
          sum += L[j][k] * L[j][k];
        }
        L[j][j] = sqrt(matrix[j][j] - sum);
      }
      else
      {
        for (int k = 0; k < j; ++k)
        {
          sum += L[i][k] * L[j][k];
        }
        L[i][j] = (matrix[i][j] - sum) / L[j][j];
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      U[i][j] = L[j][i];
    }
  }
}

int main()
{
  double matrix[3][3] = {
      {6, 3, 4},
      {3, 6, 5},
      {4, 5, 10}};
  double L[3][3], U[3][3];

  choleskyDecomposition(matrix, L, U);

  printf("Original Matrix:\n");
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nLower Triangular Matrix (L):\n");
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      printf("%.2f ", L[i][j]);
    }
    printf("\n");
  }
  printf("\nUpper Triangular Matrix (L):\n");
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      printf("%.2f ", U[i][j]);
    }
    printf("\n");
  }

  return 0;
}
