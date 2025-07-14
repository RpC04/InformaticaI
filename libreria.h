#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* Función que lee y valida la dimension de la matriz (o sistema) */
int leerDimension()
{
    int dimension;
    int entrada, c;
    char charExtra;

    do {
        entrada = scanf("%d%c", &dimension, &charExtra);

        if (entrada != 2 || charExtra != '\n' || dimension <= 0)
        {
            printf("Entrada invalida. Ingrese solo un numero natural: ");

            if (entrada != 2 || charExtra != '\n') {
                c = getchar(); 
                while (c != '\n')
                    c = getchar(); 
            } 
        }
    } while (entrada != 2 || charExtra != '\n' || dimension <= 0);

    return dimension;
}

/* Función que valida que se ingresen números en los elementos de la matriz (o coeficientes del sistema) */
double leerDouble()
{
    double numero;
    int entrada, c;
    char charExtra;

    do {
        entrada = scanf("%lf%c", &numero, &charExtra);
        if (entrada != 2 || charExtra != '\n')
        {
            printf("Entrada invalida. Ingrese un numero valido: ");

            c = getchar(); 
            while (c != '\n')
                c = getchar(); 
        }  
    } while (entrada != 2 || charExtra != '\n');

    return numero;
}

/* Función para leer los elementos de la matriz */
void leerMatriz(int filas, int columnas, double matrizAumentada[][columnas + 1])
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

/* Limpia valores muy pequeños que deberían ser cero */
double limpiarCero(double valor)
{
    if (fabs(valor) < 1e-15)
        return 0.0;
    return valor;
}

/* Imprime la matriz antes y despues del pivoteo */
void imprimirMatriz(int n, double matrizAumentada[][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        printf("[ ");
        for (int j = 0; j <= n; j++)
        {
            if (j == n)
                printf("| ");
            printf("%.12f\t ", limpiarCero(matrizAumentada[i][j]));
        }
        printf("] \n");
    }
}

/* Funciones para realizar intercambios */
void intercambiarFilas(int n, double matrizAumentada[][n + 1], int fila1, int fila2)
{
    for (int j = 0; j <= n; j++)
    {
        double auxiliar = matrizAumentada[fila1][j];
        matrizAumentada[fila1][j] = matrizAumentada[fila2][j];
        matrizAumentada[fila2][j] = auxiliar;
    }
}

void intercambiarColumnas(int n, double matrizAumentada[][n + 1], int col1, int col2)
{
    for (int i = 0; i < n; i++)
    {
        double auxiliar = matrizAumentada[i][col1];
        matrizAumentada[i][col1] = matrizAumentada[i][col2];
        matrizAumentada[i][col2] = auxiliar;
    }
}

void intercambiarIndices(int indices[2], int pos1, int pos2)
{
    int auxiliar = indices[pos1];
    indices[pos1] = indices[pos2];
    indices[pos2] = auxiliar;
}

/* Función para copiar matriz */
void copiarMatriz(int n, double origen[][n + 1], double destino[][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            destino[i][j] = origen[i][j];
    }
}

/* Función para inicializar índices */
void inicializarIndices(int n, int indices[n])
{
    for(int i = 0; i < n; i++) {
        indices[i] = i;
    }
}

/* Función para realizar eliminación gaussiana en una etapa */
void eliminacionGaussiana(int n, double matrizAumentada[][n + 1], int k)
{
    for (int i = k + 1; i < n; i++)
    {
        double factor = matrizAumentada[i][k] / matrizAumentada[k][k];
        for (int j = k; j <= n; j++)
            matrizAumentada[i][j] -= factor * matrizAumentada[k][j];
    }
}

/* Función para realizar sustitución hacia atrás */
void sustitucionHaciaAtras(int n, double matrizAumentada[][n + 1], double solucion[n])
{
    for (int i = n - 1; i >= 0; i--)
    {
        double suma = 0;
        for (int j = i + 1; j < n; j++)
            suma += matrizAumentada[i][j] * solucion[j];

        if (fabs(matrizAumentada[i][i]) < 1e-16)
        {
            solucion[i] = 0;
            continue;
        }
        solucion[i] = (matrizAumentada[i][n] - suma) / matrizAumentada[i][i];
    }
}

/* Función para reordenar la solución según los índices de variables */
void reordenarSolucion(int n, double solucionPermutada[n], double solucionFinal[n], int indicesVariables[n])
{
    for (int i = 0; i < n; i++)
        solucionFinal[indicesVariables[i]] = limpiarCero(solucionPermutada[i]);
}

/* Función para realizar el pivoteo parcial */
double pivoteoParcial(int dimensionMatriz, double matrizAumentada[][dimensionMatriz + 1], int k)
{
    double valorMaximo = 0.0;
    int filaMax = k;
    for (int i = k; i < dimensionMatriz; i++)
    {
        if (fabs(matrizAumentada[i][k]) > fabs(valorMaximo))
        {
            valorMaximo = matrizAumentada[i][k];
            filaMax = i;
        }
    }

    if (filaMax != k)
        intercambiarFilas(dimensionMatriz, matrizAumentada, k, filaMax);

    return valorMaximo;
}

/* Función para realizar el pivoteo total */
double pivoteoTotal(int dimensionMatriz, double matrizAumentada[][dimensionMatriz + 1], int k, int indicesFilas[dimensionMatriz], int indicesVariables[dimensionMatriz])
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

    printf("\nPivote elegido = %.10f (posicion: A[%d][%d])\n", valorMaximo, indicesFilas[filaMax] + 1, indicesVariables[colMax] + 1);

    if (fabs(valorMaximo) < 1e-16)
        return 0.0;

    if (filaMax != k)
    {
        intercambiarFilas(dimensionMatriz, matrizAumentada, k, filaMax);
        intercambiarIndices(indicesFilas, k, filaMax);
        printf("Intercambio de filas: F%d->F%d.\n", k + 1, filaMax + 1);
    }
    
    if (colMax != k)
    {
        intercambiarColumnas(dimensionMatriz, matrizAumentada, k, colMax);
        intercambiarIndices(indicesVariables, k, colMax);
        printf("Intercambio de columnas: C%d->C%d.\n", k + 1, colMax + 1);
    }
    
    return valorMaximo;
}

/* Función para determinar el tipo del sistema */
int determinarTipoSistema(int n, double matrizAumentada[][n + 1])
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool filaCoeficientesCero = true;
        for (int j = 0; j < n; j++)
        {
            if (fabs(matrizAumentada[i][j]) > 1e-16)
            {
                filaCoeficientesCero = false;
                break;
            }
        }
        if (filaCoeficientesCero)
        {
            if (fabs(matrizAumentada[i][n]) > 1e-16)
                return 0; // Sin solucion (0 = b, con b != 0)
            else
                return 1; // Infinitas soluciones (0 = 0)
        }
    }
    return 2; // Solución única
}

/* Función para validar sistema y manejar casos especiales */
bool validarYManejarSistema(int n, double matrizAumentada[][n + 1], bool esSingular)
{
    int tipoSistema = determinarTipoSistema(n, matrizAumentada);
    
    if (esSingular || tipoSistema != 2) {
        if (tipoSistema == 0)
            printf("\nEl sistema no tiene solucion (inconsistente).\n");
        else
            printf("\nEl sistema tiene infinitas soluciones.\n");
        return false;
    }
    return true;
}

/* Función para procesar el pivoteo total completo */
bool procesarPivoteoTotal(int n, double matrizAumentada[][n + 1], int indicesFilas[n], int indicesVariables[n])
{
    for (int k = 0; k < n; k++) {
        printf("\nPaso %d: Antes del pivoteo\n", k + 1);
        imprimirMatriz(n, matrizAumentada);

        double pivoteActual = pivoteoTotal(n, matrizAumentada, k, indicesFilas, indicesVariables);

        if (fabs(pivoteActual) < 1e-16) {
            return false; // Sistema singular
        }

        printf("\nPaso %d: Despues del pivoteo\n", k + 1);
        imprimirMatriz(n, matrizAumentada);

        if (k < n - 1) {
            eliminacionGaussiana(n, matrizAumentada, k);
        }
    }
    return true;
}

/* Función para resolver con pivoteo parcial */
void resolverConPivoteoParcial(int n, double matrizOriginal[][n + 1], double solucionParcial[n])
{
    double matrizParcial[n][n + 1];
    copiarMatriz(n, matrizOriginal, matrizParcial);
    bool esSingular = false;

    for (int k = 0; k < n - 1; k++)
    {
        pivoteoParcial(n, matrizParcial, k);
        if (fabs(matrizParcial[k][k]) < 1e-16){
            esSingular = true;
            break;
        }
        eliminacionGaussiana(n, matrizParcial, k);
    }

    if (!validarYManejarSistema(n, matrizParcial, esSingular))
        return;

    sustitucionHaciaAtras(n, matrizParcial, solucionParcial);
}

/* Función para resolver con pivoteo total */
bool resolverConPivoteoTotal(int n, double matrizOriginal[][n + 1], double solucionFinal[n]) 
{
    double matrizAumentada[n][n + 1];
    copiarMatriz(n, matrizOriginal, matrizAumentada);

    int indicesFilas[n], indicesVariables[n];
    inicializarIndices(n, indicesFilas);
    inicializarIndices(n, indicesVariables);

    printf("\n--- Solucion con Pivoteo Total ---\n");
    
    bool procesoExitoso = procesarPivoteoTotal(n, matrizAumentada, indicesFilas, indicesVariables);
    
    printf("\nMatriz triangular superior final (Pivoteo Total):\n");
    imprimirMatriz(n, matrizAumentada);

    if (!validarYManejarSistema(n, matrizAumentada, !procesoExitoso)) {
        return false;
    }

    double solucionesPermutadas[n];
    sustitucionHaciaAtras(n, matrizAumentada, solucionesPermutadas);
    reordenarSolucion(n, solucionesPermutadas, solucionFinal, indicesVariables);

    return true;
}

/* Función para calcular el error entre dos soluciones */
double calcularError(int n, double solucion1[n], double solucion2[n])
{
    double errorMax = 0;
    for (int i = 0; i < n; i++)
    {
        double error = fabs(solucion1[i] - solucion2[i]);
        if (error > errorMax)
            errorMax = error;
    }
    return errorMax;
}

/* Función para imprimir los resultados finales */
void imprimirResultadosFinales(int n, double solucionTotal[n], double solucionParcial[n]) 
{
    printf("\n\n------ Resultados ------\n\n");
    printf("Solucion con PIVOTEO TOTAL:\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %.25f\n", i + 1, solucionTotal[i]);

    printf("\nSolucion con Pivoteo Parcial:\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %.25f\n", i + 1, solucionParcial[i]);

    double error = calcularError(n, solucionTotal, solucionParcial);
    printf("\n\n--- Margen de error ---\n");
    printf("La Norma Infinito del error (diferencia maxima absoluta) entre los dos metodos es: %.16e\n", error);

    if (error < 1e-10)
        printf("Las soluciones son numericamente muy similares.\n");
    else
        printf("Las soluciones tienen una variacion.\n");
} 