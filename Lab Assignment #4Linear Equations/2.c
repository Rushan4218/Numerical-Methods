// Program to implement gaussian elimination with pivoting

#include <stdio.h>

int main()
{
  int n;
  printf("Enter the dimension of system of equation: ");
  scanf("%d", &n);
  float matrixA[n][n], matrixB[n];
  printf("Enter the coefficients row-wise:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%f", &matrixA[i][j]);
    }
  }
  printf("Enter the RHS vector: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &matrixB[i]);
  }

  printf("\nMatrix A: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%f\t", matrixA[i][j]);
    }
    printf("\n");
  }
  printf("\nMatrix B: \n");
  for (int i = 0; i < n; i++)
  {
    printf("%f\n", matrixB[i]);
  }
  for (int i = 0; i < n; i++)
  {
    float pivot = matrixA[i][i];
    for (int x = i + 1; x < n; x++)
    {
      if (pivot < matrixA[x][i])
      {
        pivot = matrixA[x][i];
        for (int j = 0; j < n; j++)
        {
          float tempA = matrixA[i][j];
          matrixA[i][j] = matrixA[x][j];
          matrixA[x][j] = tempA;
          if (j == 0)
          {
            float tempB = matrixB[i];
            matrixB[i]= matrixB[x];
            matrixB[x] = tempB;
          }
        }
      }
    }
    for (int j = i + 1; j < n; j++)
    {
      float constant = matrixA[j][i] / pivot;
      for (int k = i; k < n; k++)
      {
        matrixA[j][k] = matrixA[j][k] - constant * matrixA[i][k];
        if (k == 0)
        {
          matrixB[j] = matrixB[j] - constant * matrixB[i];
        }
      }
    }
  }

  printf("\nEchelon Form:\n");
  printf("\nMatrix A:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%f\t", matrixA[i][j]);
    }
    printf("\n");
  }
  printf("\nMatrixB:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f\n", matrixB[i]);
  }
  float matrixX[n];
  for (int i = n - 1; i >= 0; i--)
  {
    float sum = 0;
    for (int j = i + 1; j <= n; j++)
    {
      sum = sum + matrixA[i][j] * matrixX[j];
      matrixX[i] = (matrixB[i] - sum) / matrixA[i][i];
    }
  }
  printf("\nSolution X: \n");
  for (int i = 0; i < n; i++)
  {
    printf("%f\n", matrixX[i]);
  }
  return 0;
}