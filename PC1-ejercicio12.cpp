#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Ingrese el tamanio de la matriz cuadrada: ");
    scanf("%d", &n);

    int a[n][n];
    int vector[10], resultado[10];
    for (int i = 0; i < n; i++) vector[i] = 1;

    printf("Ingrese los elementos de la matriz A %dx%d:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    int autovalor = 0, autovalorPrevio = 0, iteraciones = 0;

    do {
        for (int i = 0; i < n; i++) {
            resultado[i] = 0;
            for (int j = 0; j < n; j++) {
                resultado[i] += a[i][j] * vector[j];
            }
        }

        int max = abs(resultado[0]);
        for (int i = 1; i < n; i++) {
            if (abs(resultado[i]) > max)
                max = abs(resultado[i]);
        }

        for (int i = 0; i < n; i++) {
            vector[i] = resultado[i] / max;
        }

        autovalorPrevio = autovalor;
        autovalor = max;
        iteraciones++;
    } while (iteraciones < 100 && autovalor != autovalorPrevio);

    printf("\nAutovalor dominante aproximado: %d\n", autovalor);
    printf("Vector propio asociado (entero aproximado):\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d] = %d\n", i + 1, vector[i]);
    }

    return 0;
}
