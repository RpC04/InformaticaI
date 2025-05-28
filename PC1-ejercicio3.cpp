#include <stdio.h>

int main() {
    double v[2], a[2][2];
    double w[2] = {};

    printf("Ingrese el vector de 2 dimensiones:\n");
    for(int i = 0; i < 2; i++) {
        printf("v[%d]:", i);
        scanf("%lf", &v[i]);
    }

    printf("\nIngrese la matriz A (2x2):\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("A[%d][%d]:", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            w[i] = w[i] + a[i][j] * v[j];
        }
    }

    printf("\nEl vecto w es:\n");
    for(int i = 0; i < 2; i++) {
        printf("w[%d]: %.2lf\n", i, w[i]);
    }

    return 0;
}
