//Program to implement Jacobi iteration method

#include <stdio.h>
#include <math.h>

int main() {
    printf("Enter the dimension of the system: ");
    int n;
    scanf("%d", &n);
    double matrix[n][n], B[n];

    printf("Enter the coefficients row-wise: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Enter the RHS vector: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &B[i]);
    }

    double error;
    printf("Enter the accuracy limit: ");
    scanf("%lf", &error);

    double newX[n], oldX[n];
    for (int i = 0; i < n; i++) {
        oldX[i] = 0;
    }

    while (1) {
        double maxError = 0.0;
        for (int i = 0; i < n; i++) {
            newX[i] = B[i]; 
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    newX[i] -= matrix[i][j] * oldX[j];
                }
            }
            newX[i] /= matrix[i][i];
            double currentError = fabs(newX[i] - oldX[i]);
            if (currentError > maxError) {
                maxError = currentError;
            }
        }
        if (maxError < error) {
            break; 
        }
        
        for (int i = 0; i < n; i++) {
            oldX[i] = newX[i];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lf\n", newX[i]);
    }
    
    return 0;
}
