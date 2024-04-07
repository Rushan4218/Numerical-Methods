// Program to implement matrix inversion using Gauss Jordan method

#include <stdio.h>

int main()
{
  int n;
  printf("Enter the dimension the matrix: ");
  scanf("%d", &n);
  float matrixA[n][n], matrixB[n][n];
  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%f", &matrixA[i][j]);
      if (i == j)
        matrixB[i][j] = 1;
      else
        matrixB[i][j] = 0;
    }
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
    for (int j = 0; j < n; j++)
    {
      printf("%f\t", matrixB[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < n; i++)
  {
    if (matrixA[i][i] != 1)
    {
      for (int j = 0; j < n; j++)
      {
        matrixA[i][j] = matrixA[i][j] / matrixA[i][i];
        matrixB[i][j] = matrixB[i][j] / matrixA[i][i];
      }
    }
    float pivot = matrixA[i][i];
    for (int j = i + 1; j < n; j++)
    {
      float constant = matrixA[j][i] / pivot;
      for (int k = i; k < n; k++)
      {
        matrixA[j][k] = matrixA[j][k] - constant * matrixA[i][k];
        matrixB[j][k] = matrixB[j][k] - constant * matrixB[i][k];
      }
      printf("\nMatrix A:\n");
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          printf("%f\t", matrixA[i][j]);
        }
        printf("\n");
      }
      printf("\nReverse:\n");
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          printf("%f\t", matrixB[i][j]);
        }
        printf("\n");
      }
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      float constant = matrixA[j][i];
      for (int k = i; k >= 0; k--)
      {
        matrixA[j][k] = matrixA[j][k] - constant * matrixA[i][k];
        matrixB[j][k] = matrixB[j][k] - constant * matrixB[i][k];
        printf("\nMatrix A:\n");
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
          {
            printf("%f\t", matrixA[i][j]);
          }
          printf("\n");
        }
        printf("\nReverse:\n");
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
          {
            printf("%f\t", matrixB[i][j]);
          }
          printf("\n");
        }
      }
    }
  }

  printf("\nReduced Echelon Form:\n");
  printf("\nMatrix A:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%f\t", matrixA[i][j]);
    }
    printf("\n");
  }
  printf("\nReverse:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%f\t", matrixB[i][j]);
    }
    printf("\n");
  }
  return 0;
}