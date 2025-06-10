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
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    if (n<m)
        rango = n;
    else
        rango = m;

    for(int i=0; i<rango; i++) {
        if(A[i][i] != 0 ) {
            for(int j=0; j<m; j++) {
                if(j != i) {
                    double factMultiplicador = A[j][i] / A[i][i];
                    for(int k=0; k<rango; k++)
                        A[j][k] -= factMultiplicador * A[i][k];
                }
            }
        } else {
            int reduce = 1;
            for(int j=i+1; j<m; j++) {
                if(A[j][i] != 0) {
                    for(int k=0; k<rango; k++) {
                        double temporal = A[i][k];
                        A[i][k] = A[j][k];
                        A[j][k] = temporal;
                    }
                    reduce = 0;
                    break;
                }
            }
            if(reduce != 0) {
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
