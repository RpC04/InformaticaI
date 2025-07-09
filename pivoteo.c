#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intercambiarFilas(int n, double matrizAumentada[n][n + 1], int fila1, int fila2)
{
    for (int j = 0; j <= n; j++)
    {
        double temp = matrizAumentada[fila1][j];
        matrizAumentada[fila1][j] = matrizAumentada[fila2][j];
        matrizAumentada[fila2][j] = temp;
    }
}

void intercambiarColumnas(int n, double matrizAumentada[n][n + 1], int col1, int col2)
{
    for (int i = 0; i < n; i++)
    {
        double temp = matrizAumentada[i][col1];
        matrizAumentada[i][col1] = matrizAumentada[i][col2];
        matrizAumentada[i][col2] = temp;
    }
}

// --- Funcion Principal de Pivoteo Total ---
double pivoteoTotal(int n, double matrizAumentada[n][n + 1], int k, int indicesFilas[n], int indicesVariables[n]) {
    double valorMaximo = 0.0;
    int filaMax = k;
    int colMax = k;

    for (int i = k; i < n; i++) {
        for (int j = k; j < n; j++) {
            if (fabs(matrizAumentada[i][j]) > fabs(valorMaximo)) {
                valorMaximo = matrizAumentada[i][j];
                filaMax = i;
                colMax = j;
            }
        }
    }

    if (fabs(valorMaximo) < 1e-9) {
        return 0.0;
    }

    if (filaMax != k) {
        intercambiarFilas(n, matrizAumentada, k, filaMax);
        int temp = indicesFilas[k];
        indicesFilas[k] = indicesFilas[filaMax];
        indicesFilas[filaMax] = temp;
    }

    if (colMax != k) {
        intercambiarColumnas(n, matrizAumentada, k, colMax);
        int temp = indicesVariables[k];
        indicesVariables[k] = indicesVariables[colMax];
        indicesVariables[colMax] = temp;
    }

    return valorMaximo;
}

// --- Funciones para Entrada/Salida ---

int leerDimension()
{
    int valor;
    while (1)
    {
        if (scanf("%d", &valor) == 1 && valor > 0)
        {
            break;
        }
        else
        {
            printf("Error: debe ingresar un numero entero y que sea mayor que 0.\nIngrese un numero que sea mayor que 0: ");
            while (getchar() != '\n')
                ; // Limpiar el buffer
        }
    }
    return valor;
}

void leerMatriz(int filas, int columnas, double matrizAumentada[filas][columnas + 1])
{
    printf("\nIntroducir los elementos de la matriz aumentada [A|b]:\n\n");
    for (int i = 0; i < filas; i++)
    {
        printf("Fila %d:\n", i + 1);
        for (int j = 0; j < columnas; j++)
        {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrizAumentada[i][j]);
        }
        printf("Termino independiente b[%d]: ", i + 1);
        scanf("%lf", &matrizAumentada[i][columnas]);
    }
}

void imprimirMatriz(int n, double matrizAumentada[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        printf("| ");
        for (int j = 0; j <= n; j++)
        {
            printf("%8.3f\t", matrizAumentada[i][j]);
        }
        printf("|\n");
    }
}

// --- Programa Principal ---
int main()
{
    int n;
    double pivoteActual;

    printf("=============================================");
    printf("\nPrograma para resolver un sistema de ecuaciones lineales\n");
    printf("con Eliminacion Gaussiana y Pivoteo Total\n");
    printf("=============================================\n");

    printf("Ingrese el numero de ecuaciones (N): ");
    n = leerDimension();

    // Declaraciones con double y array para indices de filas
    double matrizAumentada[n][n + 1];
    int indicesFilas[n];
    int indicesVariables[n];
    double solucionesPermutadas[n];
    double solucionFinal[n];

    leerMatriz(n, n, matrizAumentada);

    // Inicializar ambos arrays de indices
    for (int i = 0; i < n; i++)
    {
        indicesFilas[i] = i;
        indicesVariables[i] = i;
    }

    // Bucle principal de Eliminacion Gaussiana con Pivoteo Total
    for (int k = 0; k < n; k++)
    {
        printf("\nPaso %d: Antes del pivoteo total\n", k);
        imprimirMatriz(n, matrizAumentada);

        // Se pasan ambos arrays de indices a la funcion
        pivoteActual = pivoteoTotal(n, matrizAumentada, k, indicesFilas, indicesVariables);

        if (fabs(pivoteActual) < 1e-9)
        {
            printf("Advertencia: El sistema puede ser singular o mal condicionado. Pivote cercano a cero en paso %d.\n", k);
            return 1;
        }

        printf("\nPaso %d: Despues del pivoteo total (pivote elegido = %.3f)\n", k, pivoteActual);
        imprimirMatriz(n, matrizAumentada);
        printf("Orden de filas actualizado: ");
        for (int i = 0; i < n; i++) {
            printf("x%d ", indicesFilas[i] + 1);
        }
        printf("\n");

        printf("Orden de variables actualizado: ");
        for (int i = 0; i < n; i++) {
            printf("y%d ", indicesVariables[i] + 1);
        }
        printf("\n");

        if (fabs(matrizAumentada[k][k]) < 1e-9)
        {
            printf("Error critico: Division por cero inesperada en A[%d][%d] durante la eliminacion.\n", k, k);
            return 1;
        }

        for (int i = k + 1; i < n; i++)
        {
            double factor = matrizAumentada[i][k] / matrizAumentada[k][k];
            for (int j = k; j <= n; j++)
            {
                matrizAumentada[i][j] = matrizAumentada[i][j] - factor * matrizAumentada[k][j];
            }
        }
    }

    printf("\nMatriz triangular superior final:\n");
    imprimirMatriz(n, matrizAumentada);

    // --- Sustitucion hacia atras ---
    for (int i = n - 1; i >= 0; i--)
    {
        double suma = 0.0;
        for (int j = i + 1; j < n; j++)
        {
            suma += matrizAumentada[i][j] * solucionesPermutadas[j];
        }
        if (fabs(matrizAumentada[i][i]) < 1e-9)
        {
            printf("Error: Division por cero durante la sustitucion hacia atras.\n");
            return 1;
        }
        solucionesPermutadas[i] = (matrizAumentada[i][n] - suma) / matrizAumentada[i][i];
    }

    // --- Reordenar la solucion a su orden original ---
    for (int i = 0; i < n; i++)
    {
        solucionFinal[indicesVariables[i]] = solucionesPermutadas[i];
    }

    printf("\nSolucion del sistema:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %20.9f\n", i + 1, solucionFinal[i]);
    }

    return 0;
}