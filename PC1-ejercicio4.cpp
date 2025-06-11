#include <stdio.h>

int n;
double A[10][10], b[10];

double determinante(double M[10][10], int tam) {
    if (tam == 1) return M[0][0];
    if (tam == 2) return M[0][0] * M[1][1] - M[0][1] * M[1][0];

    double det = 0;
    double subM[10][10];

    for (int x = 0; x < tam; x++) {
        int subi = 0;
        for (int i = 1; i < tam; i++) {
            int subj = 0;
            for (int j = 0; j < tam; j++) {
                if (j == x) continue;
                subM[subi][subj] = M[i][j];
                subj++;
            }
            subi++;
        }
        double signo = (x % 2 == 0) ? 1 : -1;
        det += signo * M[0][x] * determinante(subM, tam - 1);
    }

    return det;
}

void copiarConColumnaModificada(double destino[10][10], int col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            destino[i][j] = (j == col) ? b[i] : A[i][j];
        }
    }
}

int main() {
    printf("Ingrese el orden del sistema (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Orden no valido.\n");
        return 1;
    }

    printf("Ingrese la matriz A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }

    printf("Ingrese el vector b:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d]: ", i);
        scanf("%lf", &b[i]);
    }

    double detA = determinante(A, n);
    if (detA == 0) {
        int todosCero = 1;
        for (int i = 0; i < n; i++) {
            double Ai[10][10];
            copiarConColumnaModificada(Ai, i);
            if (determinante(Ai, n) != 0) {
                todosCero = 0;
                break;
            }
        }
        if (todosCero)
            printf("\nSistema con infinitas soluciones.\n");
        else
            printf("\nSistema inconsistente.\n");
    } else {
        double x[10];
        for (int i = 0; i < n; i++) {
            double Ai[10][10];
            copiarConColumnaModificada(Ai, i);
            double detAi = determinante(Ai, n);
            x[i] = detAi / detA;
        }

        printf("\nSolucion unica:\n");
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %.4lf\n", i, x[i]);
        }
    }

    return 0;
}
