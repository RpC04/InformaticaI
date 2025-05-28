#include <stdio.h>

int main() {
    double a[3][3], sumDiag = 0;

    printf("Ingrese los elementos de la matriz A 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("A[%d][%d]:", i+1, j+1);
            scanf("%lf", &a[i][j]);
            if(i == j) {
                sumDiag = sumDiag + a[i][j];
            }
        }
    }

    printf("\nLa suma de la diagonal principal es: %.2lf\n", sumDiag);

    return 0;
}
