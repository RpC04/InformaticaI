#include <stdio.h>

int main() {
    int n, m;


    printf("Ingrese el numero de filas de A y B: ");
    scanf("%d", &n);
    printf("Ingrese el numero de columnas de A y B: ");
    scanf("%d", &m);

    double a[n][m], b[n][m], c[n][m];

    printf("Ingrese los elementos de las matrices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("\n------ Fila %d, Columna %d ------\n", i, j);
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &a[i][j]);
            printf("B[%d][%d]: ", i, j);
            scanf("%lf", &b[i][j]);
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nLa matriz suma C es:\n");
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < m; j++) {
            printf("%.2lf ", c[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
