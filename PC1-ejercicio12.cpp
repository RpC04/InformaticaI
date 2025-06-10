#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    double A[n][n];
    double x[n];
    double Ax[n];

    printf("Ingrese los elementos de la matriz A %dx%d:\n", n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%lf", &A[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        x[i] = 1.0;
    }

    double lambda = 0, lambda_prev = 0;
    int iter = 0;

    do {
        for(int i = 0; i < n; i++) {
            Ax[i] = 0.0;
            for(int j = 0; j < n; j++) {
                Ax[i] += A[i][j] * x[j];
            }
        }

        double norma = 0.0;
        for(int i = 0; i < n; i++) {
            norma += Ax[i] * Ax[i];
        }
        norma = sqrt(norma);
        for(int i = 0; i < n; i++) {
            x[i] = Ax[i] / norma;
        }

        double num = 0.0, den = 0.0;
        for(int i = 0; i < n; i++) {
            double temp = 0.0;
            for(int j = 0; j < n; j++)
                temp += A[i][j] * x[j];
            num += x[i] * temp;
            den += x[i] * x[i];
        }
        lambda_prev = lambda;
        lambda = num / den;
        iter++;
    } while(iter < MAX_ITER && fabs(lambda - lambda_prev) > 1e-6);

    printf("\nAutovalor dominante (aproximado): %.6lf\n", lambda);
    printf("Vector propio asociado (aproximado):\n");
    for(int i = 0; i < n; i++) {
        printf("v[%d] = %.6lf\n", i+1, x[i]);
    }
    return 0;
}
