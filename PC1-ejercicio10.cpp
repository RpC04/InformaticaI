#include <stdio.h>

int main() {
    int n;
    printf("Ingrese el orden del sistema (n): ");
    scanf("%d", &n);

    double A[n][n+1];

    printf("Ingrese los elementos de la matriz aumentada A|b de %dx%d:\n", n, n+1);
    for(int i=0; i<n; i++) {
        for(int j=0; j<=n; j++) {
            if(j == n) {
                printf("b[%d]: ", i+1);
                scanf("%lf", &A[i][j]);
                printf("\n");
            } else {
                printf("A[%d][%d]: ", i+1, j+1);
                scanf("%lf", &A[i][j]);
            }

        }
    }

    for(int i=0; i<n; i++) {
        double pivote = A[i][i];
        for(int j=0; j<=n; j++)
            A[i][j] /= pivote;

        for(int k=0; k<n; k++) {
            if(k != i) {
                double mult = A[k][i];
                for(int j=0; j<=n; j++)
                    A[k][j] -= mult * A[i][j];
            }
        }
    }

    printf("\nSolucion del sistema:\n");
    for(int i=0; i<n; i++)
        printf("x%d = %.6lf\n", i+1, A[i][n]);
    return 0;
}
