#include <stdio.h>

int main() {
    int m, n, rango;
    printf("Ingrese numero de filas: ");
    scanf("%d", &m);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &n);

    double A[m][n];

    printf("Ingrese los elementos de la matriz A %dx%d:\n", m, n);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%lf", &A[i][j]);
        }
    }

    rango = n;
    for(int i=0; i<rango; i++) {
        if(A[i][i]) {
            for(int j=0; j<m; j++) {
                if(j != i) {
                    double mult = A[j][i] / A[i][i];
                    for(int k=0; k<rango; k++)
                        A[j][k] -= mult * A[i][k];
                }
            }
        } else {
            int reduce = 1;
            for(int j=i+1; j<m; j++) {
                if(A[j][i]) {
                    for(int k=0; k<rango; k++) {
                        double tmp = A[i][k];
                        A[i][k] = A[j][k];
                        A[j][k] = tmp;
                    }
                    reduce = 0;
                    break;
                }
            }
            if(reduce) {
                rango--;
                for(int j=0; j<m; j++)
                    A[j][i] = A[j][rango];
            }
            i--;
        }
    }

    printf("\nEl rango de la matriz es: %d\n", rango);
    return 0;
}
