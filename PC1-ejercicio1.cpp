#include <stdio.h>

int main() {
    double a[2][2];

    printf("Ingreso a la matriz A 2x2:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]:", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    double det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    printf("\nEl determinante de A es: %.2lf\n", det);

    return 0;
}
