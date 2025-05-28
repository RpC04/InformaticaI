#include <stdio.h>

int main() {
    double a[3][3], b[3][3], c[3][3];

    printf("Ingrese los elementos de las matrices A y B:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("\n------ Fila %d, Columna %d ------\n", i, j);
            printf("A[%d][%d]:", i, j);
            scanf("%lf", &a[i][j]);
            printf("B[%d][%d]:", i, j);
            scanf("%lf", &b[i][j]);
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nLa matriz suma C es:\n");
    for(int i = 0; i < 3; i++) {
        printf("[");
        for(int j = 0; j < 3; j++) {
            printf("%.2lf ", c[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
