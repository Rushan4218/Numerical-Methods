// Program to implement Do-Little LU Decomposition

#include <stdio.h>

void dooLittleDecomposition(double matrix[][3], double L[][3], double U[][3], int n)
{

  for (int i = 0; i < n; i++)
  {
    L[i][i] = 1.0;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      U[i][j] = matrix[i][j];
      for (int k = 0; k < i; k++)
      {
        U[i][j] -= L[i][k] * U[k][j];
      }
    }
    for (int j = i + 1; j < n; j++)
    {
      L[j][i] = matrix[j][i];
      for (int k = 0; k < i; k++)
      {
        L[j][i] -= L[j][k] * U[k][i];
      }
      L[j][i] /= U[i][i];
    }
  }
}

int main()
{

  printf("Enter the dimension of the matrix: ");
  int n;
  scanf("%d", &n);
  double matrix[n][n], L[n][n], U[n][n];
  printf("Enter the elements: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%lf", &matrix[i][j]);
    }
  }

  dooLittleDecomposition(matrix, L, U, n);

  printf("Lower Triangular Matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%.2f ", L[i][j]);
    }
    printf("\n");
  }

  printf("\nUpper Triangular Matrix: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%.2f ", U[i][j]);
    }
    printf("\n");
  }
  return 0;
}
