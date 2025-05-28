#include <stdio.h>

int main() {
    double a[3][3], at[3][3];

    printf("Ingrese los elementos de la matriz A 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("A[%d][%d]:", i, j);
            scanf("%lf", &a[i][j]);
            at[j][i] = a[i][j];
        }
    }

    printf("\nLa matriz transpuesta es:\n");
    for(int i = 0; i < 3; i++) {
        printf("[");
        for(int j = 0; j < 3; j++) {
            printf("%.2lf ", at[i][j]);
        }
        printf("]\n");
    }

    return 0;
}