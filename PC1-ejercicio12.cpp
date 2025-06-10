#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    double a[n][n], vector[n], resultado[n];

    printf("Ingrese los elementos de la matriz A %dx%d:\n", n, n);
    for(int i = 0; i < n; i++) {
        vector[i] = 1;
        for(int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
    }

    double autovalor = 0, autovalorPrevio = 0;
    int iteraciones = 0;

    do {
        for(int i = 0; i < n; i++) {
            resultado[i] = 0;
            for(int j = 0; j < n; j++) {
                resultado[i] += a[i][j] * vector[j];
            }
        }

        double norma = 0;
        for(int i = 0; i < n; i++) {
            norma += resultado[i] * resultado[i];
        }
        norma = sqrt(norma);
        for(int i = 0; i < n; i++) {
            vector[i] = resultado[i] / norma;
        }

        double numerador = 0, denominador = 0;
        for(int i = 0; i < n; i++) {
            double temporal = 0;
            for(int j = 0; j < n; j++) {
                temporal += a[i][j] * vector[j];
            }
            numerador += vector[i] * temporal;
            denominador += vector[i] * vector[i];
        }
        autovalorPrevio = autovalor;
        autovalor = numerador / denominador;
        iteraciones++;
    } while(iteraciones < 1000 && fabs(autovalor - autovalorPrevio) > 1e-6);

    printf("\nAutovalor dominante (aproximado): %.2lf\n", autovalor);
    printf("Vector propio asociado (aproximado):\n");
    for(int i = 0; i < n; i++) {
        printf("v[%d] = %.6lf\n", i + 1, vector[i]);
    }

    return 0;
}
