#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void intercambiarFilas(int n, double matrizAumentada[n][n + 1], int fila1, int fila2)
{
    for (int j = 0; j <= n; j++)
    {
        double auxiliar = matrizAumentada[fila1][j];
        matrizAumentada[fila1][j] = matrizAumentada[fila2][j];
        matrizAumentada[fila2][j] = auxiliar;
    }
}

void intercambiarColumnas(int n, double matrizAumentada[n][n + 1], int col1, int col2)
{
    for (int i = 0; i < n; i++)
    {
        double auxiliar = matrizAumentada[i][col1];
        matrizAumentada[i][col1] = matrizAumentada[i][col2];
        matrizAumentada[i][col2] = auxiliar;
    }
}

// --- Funcion Principal de Pivoteo Total ---
double pivoteoTotal(int dimensionMatriz, double matrizAumentada[dimensionMatriz][dimensionMatriz + 1], int k, int indicesFilas[dimensionMatriz], int indicesVariables[dimensionMatriz])
{
    double valorMaximo = 0;
    int filaMax = k;
    int colMax = k;

    for (int i = k; i < dimensionMatriz; i++)
    {
        for (int j = k; j < dimensionMatriz; j++)
        {
            if (fabs(matrizAumentada[i][j]) > fabs(valorMaximo))
            {
                valorMaximo = matrizAumentada[i][j];
                filaMax = i;
                colMax = j;
            }
        }
    }

    if (fabs(valorMaximo) < 1e-16)
    {
        return 0.0; // Si el valor maximo es cero, no se puede hacer pivoteo
    }

    if (filaMax != k)
    {
        intercambiarFilas(dimensionMatriz, matrizAumentada, k, filaMax);
        int auxiliar = indicesFilas[k];
        indicesFilas[k] = indicesFilas[filaMax];
        indicesFilas[filaMax] = auxiliar;
    }

    if (colMax != k) {
        intercambiarColumnas(dimensionMatriz, matrizAumentada, k, colMax);
        int auxiliar = indicesVariables[k];
        indicesVariables[k] = indicesVariables[colMax];
        indicesVariables[colMax] = auxiliar;
    }

    return valorMaximo;
}

// --- Funciones para Entrada/Salida ---

int leerDimension() {
    int dimension;
    char extra;
    
    while (true) { 
        scanf("%d%c", &dimension, &extra);
        // Verificar si la entrada es un numero natural y no excede 9 digitos
        if (extra == '\n' && dimension > 0 && dimension < 999999999) {
            return dimension;
        }
        
        printf("Ingrese solo numeros naturales (max 9 digitos): ");
        while (getchar() != '\n');
    }
}

double leerDouble() {
    double numero;
    char extra;
    
    while (true) {
        scanf("%lf%c", &numero, &extra);
        if (extra == '\n') {
            return numero;
        }
        
        printf("Ingrese un numero valido: ");
        while (getchar() != '\n');
    }
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
            matrizAumentada[i][j] = leerDouble();
        }
        printf("Termino independiente b[%d]: ", i + 1);
        matrizAumentada[i][columnas] = leerDouble();
    }
}

void imprimirMatriz(int n, double matrizAumentada[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        printf("[ ");
        for (int j = 0; j <= n; j++)
        {
            printf("%12.10f\t", matrizAumentada[i][j]);
        }
        printf("]\n");
    }
}

// --- Programa Principal ---
int main()
{
    int dimensionMatriz;
    double pivoteActual; 

    printf("Ingrese el numero de ecuaciones (N): ");
    dimensionMatriz = leerDimension();

    // Declaraciones con double y array para indices de filas
    double matrizAumentada[dimensionMatriz][dimensionMatriz + 1];
    int indicesFilas[dimensionMatriz];
    int indicesVariables[dimensionMatriz];
    double solucionesPermutadas[dimensionMatriz];
    double solucionFinal[dimensionMatriz];

    leerMatriz(dimensionMatriz, dimensionMatriz, matrizAumentada);

    // Inicializar ambos arrays de indices
    for (int i = 0; i < dimensionMatriz; i++)
    {
        indicesFilas[i] = i;
        indicesVariables[i] = i;
    }

    // Bucle principal de Eliminacion Gaussiana con Pivoteo Total
    for (int k = 0; k < dimensionMatriz; k++)
    {
        printf("\nPaso %d: Antes del pivoteo total\n", k);
        imprimirMatriz(dimensionMatriz, matrizAumentada);

        // Se pasan ambos arrays de indices a la funcion
        pivoteActual = pivoteoTotal(dimensionMatriz, matrizAumentada, k, indicesFilas, indicesVariables);

        if (fabs(pivoteActual) < 1e-16)
        {
            printf("Advertencia: El sistema puede ser singular o mal condicionado. Pivote cercano a cero en paso %d.\n", k);
            return 1;
        }

        printf("\nPaso %d: Despues del pivoteo total (pivote elegido = %.3f)\n", k, pivoteActual);
        imprimirMatriz(dimensionMatriz, matrizAumentada);
        printf("Orden de filas actualizado: ");
        for (int i = 0; i < dimensionMatriz; i++)
        {
            printf("x%d ", indicesFilas[i] + 1);
        }
        printf("\n");

        printf("Orden de variables actualizado: ");
        for (int i = 0; i < dimensionMatriz; i++)
        {
            printf("y%d ", indicesVariables[i] + 1);
        }
        printf("\n");

        if (fabs(matrizAumentada[k][k]) < 1e-9)
        {
            printf("Division por cero inesperada en A[%d][%d] durante la eliminacion.\n", k, k);
            return 1;
        }

        for (int i = k + 1; i < dimensionMatriz; i++)
        {
            double factor = matrizAumentada[i][k] / matrizAumentada[k][k];
            for (int j = k; j <= dimensionMatriz; j++)
            {
                matrizAumentada[i][j] = matrizAumentada[i][j] - factor * matrizAumentada[k][j];
            }
        }
    }

    printf("\nMatriz triangular superior final:\n");
    imprimirMatriz(dimensionMatriz, matrizAumentada);

    // --- Sustitucion hacia atras ---
    for (int i = dimensionMatriz - 1; i >= 0; i--)
    {
        double suma = 0;
        for (int j = i + 1; j < dimensionMatriz; j++)
        {
            suma += matrizAumentada[i][j] * solucionesPermutadas[j];
        }
        if (fabs(matrizAumentada[i][i]) < 1e-9)
        {
            printf("Error: Division por cero durante la sustitucion hacia atras.\n");
            return 1;
        }
        solucionesPermutadas[i] = (matrizAumentada[i][dimensionMatriz] - suma) / matrizAumentada[i][i];
    }

    // --- Reordenar la solucion a su orden original ---
    for (int i = 0; i < dimensionMatriz; i++)
    {
        solucionFinal[indicesVariables[i]] = solucionesPermutadas[i];
    }

    printf("\nSolucion del sistema:\n");
    for (int i = 0; i < dimensionMatriz; i++)
    {
        printf("x%d = %.10f\n", i + 1, solucionFinal[i]);
    }

    return 0;
}