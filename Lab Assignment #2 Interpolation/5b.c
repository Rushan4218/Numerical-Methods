#include <math.h>
#include <stdio.h>

int main() {
    int m, n;

    double x[] = {1, 2, 3, 4};
    double y[] = {6, 11, 18, 27};

    n = sizeof(x) / sizeof(double);
    
    double u, a[10], c[20][20], power, r;

    printf("Enter the order of polynomial: ");
    scanf("%d", &m);

    for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= m; k++) {
            c[j][k] = 0;
            for (int i = 0; i < n; i++) {
                power = pow(x[i], j + k);
                c[j][k] += power;
            }
        }
    }

    for (int j = 0; j <= m; j++) {
        c[j][m + 1] = 0;
        for (int i = 0; i < n; i++) {
            r = pow(x[i], j);
            c[j][m + 1] += y[i] * r;
        }
    }

    for (int k = 0; k <= m; k++) {
        for (int i = 0; i <= m; i++) {
            if (i != k) {
                u = c[i][k] / c[k][k];
                for (int j = k; j <= m + 1; j++) {
                    c[i][j] -= u * c[k][j];
                }
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        a[i] = c[i][m + 1] / c[i][i];
        printf("a[%d] = %.2lf\n", i, a[i]);
    }

    return 0;
}
