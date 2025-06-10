#include <stdio.h>

int main() {
    int filA, colA, filB, colB;

    printf("Ingrese la cantidad de filas y columnas");
    printf("\nFilas A: ");
    scanf("%d", &filA);
    printf("Columnas A: ");
    scanf("%d", &colA);

    printf("\nFilas B: ");
    scanf("%d", &filB);
    printf("Columnas B: ");
    scanf("%d", &colB);

    if (colA == filB) {
        double a[filA][colA];
        double b[filB][colB];
        double c[filA][colB] = {};

        printf("Ingrese los elementos de la matriz A:\n");
        for (int i = 0; i < filA; i++) {
            for (int j = 0; j < colA; j++) {
                printf("a[%d][%d]:", i, j);
                scanf("%lf", &a[i][j]);
            }
        }

        printf("Ingrese los elementos de la matriz B:\n");
        for (int i = 0; i < filB; i++) {
            for (int j = 0; j < colB; j++) {
                printf("b[%d][%d]:", i, j);
                scanf("%lf", &b[i][j]);
            }
        }

        for (int i = 0; i < filA; i++) {
            for (int j = 0; j < colB; j++) {
                for (int k = 0; k < colA; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("\nProducto de las matrices:\n");
        for (int i = 0; i < filA; i++) {
            printf("[");
            for (int j = 0; j < colB; j++) {
                printf("%.2lf", c[i][j]);
            }printf("]");
            printf("\n");
        }
    } else {
        printf("\nDimensiones incompatibles para multiplicacion.\n");
    }

    return 0;
}