#include <stdio.h>

int main() {
    double a[2][2], b[2][2];

    printf("Ingrese los elementos de la matriz A 2x2:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("A[%d][%d]:", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    double det = a[0][0] * a[1][1] - a[0][1] * a[1][0];

    if(det != 0) {
        b[0][0] =  a[1][1]/det;
        b[0][1] = -a[0][1]/det;
        b[1][0] = -a[1][0]/det;
        b[1][1] =  a[0][0]/det;

        printf("\nLa matriz inversa es:\n");
        for(int i = 0; i < 2; i++) {
            printf("[");
            for(int j = 0; j < 2; j++) {
                printf("%.4lf ", b[i][j]);
            }
            printf("]\n");
        }
    } else {
        printf("\nNo es posible calcular la inversa (determinante = 0).");
    }
    return 0;
}
