#include <stdio.h>

void ingresarMatriz(int n, float A[10][20]) {
    printf("Ingrese los elementos de la matriz %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
        for (int j = n; j < 2 * n; j++) {
            if (j - n == i)
                A[i][j] = 1.0;
            else
                A[i][j] = 0.0;
        }
    }
}

int invertirMatriz(int n, float A[10][20]) {
    for (int i = 0; i < n; i++) {
        if (A[i][i] == 0) {
            int filaCambio = -1;
            for (int k = i + 1; k < n; k++) {
                if (A[k][i] != 0) {
                    filaCambio = k;
                    break;
                }
            }
            if (filaCambio == -1) {
                return 0;
            }
            for (int j = 0; j < 2 * n; j++) {
                float temp = A[i][j];
                A[i][j] = A[filaCambio][j];
                A[filaCambio][j] = temp;
            }
        }

        float pivote = A[i][i];
        for (int j = 0; j < 2 * n; j++) {
            A[i][j] = A[i][j] / pivote;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = A[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    A[k][j] = A[k][j] - factor * A[i][j];
                }
            }
        }
    }
    return 1;
}

void mostrarInversa(int n, float A[10][20]) {
    printf("Matriz inversa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    float matriz[10][20];

    printf("Tamanio de la matriz (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Tamanio no valido.\n");
        return 1;
    }

    ingresarMatriz(n, matriz);

    if (invertirMatriz(n, matriz)) {
        mostrarInversa(n, matriz);
    } else {
        printf("La matriz no se puede invertir.\n");
    }

    return 0;
}
