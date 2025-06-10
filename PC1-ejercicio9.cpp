#include <stdio.h>

int main() {
    int m, n, i, j, k, rank;
    printf("Ingrese numero de filas: ");
    scanf("%d", &m);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &n);

    double mat[m][n];

    printf("Ingrese la matriz:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%lf", &mat[i][j]);

    rank = n;
    for(i=0; i<rank; i++) {
        if(mat[i][i]) {
            for(j=0; j<m; j++) {
                if(j != i) {
                    double mult = mat[j][i] / mat[i][i];
                    for(k=0; k<rank; k++)
                        mat[j][k] -= mult * mat[i][k];
                }
            }
        } else {
            int reduce = 1;
            for(j=i+1; j<m; j++) {
                if(mat[j][i]) {
                    for(k=0; k<rank; k++) {
                        double tmp = mat[i][k];
                        mat[i][k] = mat[j][k];
                        mat[j][k] = tmp;
                    }
                    reduce = 0;
                    break;
                }
            }
            if(reduce) {
                rank--;
                for(j=0; j<m; j++)
                    mat[j][i] = mat[j][rank];
            }
            i--;
        }
    }

    printf("El rango de la matriz es: %d\n", rank);
    return 0;
}
