#include <stdio.h>
#include <math.h>

int main()
{
    printf("Enter the dimension of the system: ");
    int n;
    scanf("%d", &n);
    double matrix[n][n], B[n];

    printf("Enter the coefficients row-wise: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Enter the RHS vector: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &B[i]);
    }

    double error;
    printf("Enter the accuracy limit: ");
    scanf("%lf", &error);

    double newX[n], oldX[n];
    for (int i = 0; i < n; i++)
    {
        oldX[i] = 0;
    }
    double E[n];
    while (1)
    {

        for (int i = 0; i < n; i++)
        {
            double sum = B[i];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum -= matrix[i][j] * newX[j];
                }
            }
            oldX[i] = newX[i];
            newX[i] = sum / matrix[i][i];

            E[i] = fabs((newX[i] - oldX[i]) / newX[i]);
        }

        int allConverged = 1;
        for (int i = 0; i < n; i++)
        {
            if (E[i] >= error)
            {
                allConverged = 0;
                break;
            }
        }
        if (allConverged)
        {
            break;
        }
    }

    printf("Solution vector:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.6f\n", newX[i]);
    }
    printf("\n");

    return 0;
}
