#include <stdio.h>

int main() {
    int m, n;
    printf("Ingrese numero de filas: ");
    scanf("%d", &m);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &n);

    double a[m][n];
    int rango = n;

    printf("Ingrese la matriz:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("\n------ Fila %d, Columna %d ------\n", i, j);
            printf("A[%d][%d]:", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    for(int i = 0; i < rango; i++) {
        if(a[i][i] != 0) {
            for(int j = 0; j < m; j++) {
                if(j != i) {
                    double factMultiplicativo = a[j][i] / a[i][i];
                    for(int k = 0; k < rango; k++)
                        a[j][k] -= factMultiplicativo * a[i][k];
                }
            }
        } else {
            int reducir = 1;
            for(int j = i + 1; j < m; j++) {
                if(a[j][i]) {
                    for(int k = 0; k < rango; k++) {
                        double valTemporal = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = valTemporal;
                    }
                    reducir = 0;
                    break;
                }
            }
            if(reducir !=0 ) {
                rango--;
                for(int j = 0; j < m; j++)
                    a[j][i] = a[j][rango];
            }
            i--;
        }
    }

    printf("El rango de la matriz es: %d\n", rango);
    return 0;
}

