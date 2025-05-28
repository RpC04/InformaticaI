#include <stdio.h>

int main() {
    int i, j;
    double a[3][3];
    double fil1, fil2, fil3, det;

    printf("Ingrese la matriz 3x3:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Ingrese los elementos[%d][%d]:", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    fil1 = a[0][0] * (a[1][1]*a[2][2] - a[1][2]*a[2][1]);
    fil2 = -a[0][1] * (a[1][0]*a[2][2] - a[1][2]*a[2][0]);
    fil3 = a[0][2] * (a[1][0]*a[2][1] - a[1][1]*a[2][0]);

    det = fil1 + fil2 + fil3;

    printf("fil1 = %.2lf\n", fil1);
    printf("fil2 = %.2lf\n", fil2);
    printf("fil3 = %.2lf\n", fil3);
    printf("Determinante = %.2lf\n", det);

    return 0;
}