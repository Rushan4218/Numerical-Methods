// Program to implement gaussian elimination

#include <stdio.h>

int main()
{
  int n;
  printf("Enter the dimension of system of equation: ");
  scanf("%d", &n);
  double matrixA[n][n], matrixB[n];
  printf("Enter the coefficients row-wise:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%lf", &matrixA[i][j]);
    }
  }
  printf("Enter the RHS vector: ");
  for (int i = 0; i < n; i++) 
  {
    scanf("%lf", &matrixB[i]);
  }

printf("\nMatrix A: \n");
for (int i = 0; i < n; i++) 
{
  for (int j = 0; j < n; j++) 
  {
    printf("%lf\t", matrixA[i][j]);
  }
  printf("\n");
}
printf("\nMatrix B: \n");
for (int i = 0; i < n; i++)
{
  printf("%lf\n", matrixB[i]);
}
  for (int i = 0; i < n; i++)
  {
    double pivot = matrixA[i][i];
    for (int j = i + 1; j < n; j++)
    {
      double constant = matrixA[j][i] / pivot;
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
      printf("%lf\t", matrixA[i][j]);
    }
    printf("\n");
  }
  printf("\nMatrixB:\n");
  for (int i = 0; i < n; i++) 
  {
    printf("%lf\n", matrixB[i]);
  }
  double matrixX[n];
  for (int i = n - 1; i >= 0; i--) 
  {
    double sum = 0;
    for (int j = i + 1; j <= n; j++) 
    {
      sum = sum + matrixA[i][j] * matrixX[j];
      matrixX[i] = (matrixB[i] - sum) / matrixA[i][i];
    }
  }
  printf("\nSolution X: \n");
  for (int i = 0; i < n; i++) {
    printf("%lf\n", matrixX[i]);
  }
  return 0;
}