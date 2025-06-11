#include <stdio.h>

void ingresarMatriz(int n, int A[][11]) {
    printf("\nIngrese los elementos de la matriz aumentada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j != n)
                printf("A[%d][%d]: ", i, j);
            else
                printf("b[%d][%d]: ", i, j);

            scanf("%d", &A[i][j]);
        }
        printf("\n");
    }
}

int eliminacionGaussJordan(int n, int A[][11]) {
    for (int i = 0; i < n; i++) {
        if (A[i][i] == 0) {
            int pivoteEncontrado = 0;
            for (int k = i + 1; k < n; k++) {
                if (A[k][i] != 0) {
                    for (int j = 0; j <= n; j++) {
                        int temporal = A[i][j];
                        A[i][j] = A[k][j];
                        A[k][j] = temporal;
                    }
                    pivoteEncontrado = 1;
                    break;
                }
            }
            if (!pivoteEncontrado && A[i][i] == 0) {
                int ceros = 1;
                for (int j = 0; j < n; j++) {
                    if (A[i][j] != 0) {
                        ceros = 0;
                        break;
                    }
                }
                if (ceros && A[i][n] != 0) {
                    printf("\nSistema inconsistente\n");
                    return -1;
                }
                continue;
            }
        }

        int pivote = A[i][i];
        for (int k = 0; k < n; k++) {
            if (k != i) {
                int factor = A[k][i];
                for (int j = 0; j <= n; j++) {
                    A[k][j] = A[k][j] * pivote - factor * A[i][j];
                }
            }
        }
    }
    return 0;
}

void imprimirResultado(int n, int A[][11]) {
    int rango = 0;
    for (int i = 0; i < n; i++) {
        int ceros = 1;
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                ceros = 0;
                break;
            }
        }
        if (!ceros) rango++;
    }

    if (rango < n) {
        printf("\nEl sistema tiene infinitas soluciones.\n");
    } else {
        printf("\nSolucion unica:\n");
        for (int i = 0; i < n; i++) {
            printf("x%d = %d\n", i + 1, A[i][n] / A[i][i]);
        }
    }
}

int main() {
    int n;
    printf("Ingrese la orden del sistema: ");
    scanf("%d", &n);
    if (n <= 0 || n > 10) {
        printf("Error: n debe estar entre 1 y 10\n");
        return 1;
    }

    int A[10][11];
    ingresarMatriz(n, A);

    if (eliminacionGaussJordan(n, A) == -1) {
        return 1;
    }

    imprimirResultado(n, A);
    return 0;
}
