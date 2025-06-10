#include <stdio.h>

int main() {
    double a[2][2], b[2];

    printf("Ingrese los coeficientes de la matriz A (2x2):\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("A[%d][%d]:", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
    }

    printf("\nIngrese el vector b:\n");
    for(int i = 0; i < 2; i++) {
        printf("b[%d]:", i+1);
        scanf("%lf", &b[i]);
    }

    double det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    double detX = b[0]*a[1][1] - a[0][1]*b[1];
    double detY = a[0][0]*b[1] - b[0]*a[1][0];

    if(det != 0) {
        double x = detX / det;
        double y = detY / det;
        printf("\nSolucion:\n");
        printf("x = %.2lf\n", x);
        printf("y = %.2lf\n", y);
    } else {
        if(detX == 0 && detY == 0) {
            printf("\nEl sistema tiene infinitas soluciones.\n");
        } else {
            printf("\nEl sistema es inconsistente.\n");
        }
    }

    return 0;
}
