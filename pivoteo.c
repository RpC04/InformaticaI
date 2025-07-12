#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// --- Prototipos de Funciones ---
int leerDimension();
double leerDouble();
void intercambiarFilas(int n, double matrizAumentada[n][n + 1], int fila1, int fila2);
void intercambiarColumnas(int n, double matrizAumentada[n][n + 1], int col1, int col2);
void copiarMatriz(int n, double origen[n][n + 1], double destino[n][n + 1]);
double pivoteoParcial(int dimensionMatriz, double matrizAumentada[dimensionMatriz][dimensionMatriz + 1], int k);
double pivoteoTotal(int dimensionMatriz, double matrizAumentada[dimensionMatriz][dimensionMatriz + 1], int k, int indicesFilas[dimensionMatriz], int indicesVariables[dimensionMatriz]);
double limpiarCero(double valor);
int determinarTipoSistema(int n, double matrizAumentada[n][n + 1]);
void leerMatriz(int filas, int columnas, double matrizAumentada[filas][columnas + 1]);
bool resolverConPivoteoTotal(int n, double matrizOriginal[n][n + 1], double solucionFinal[n]);
void resolverConPivoteoParcial(int n, double matrizOriginal[n][n + 1], double solucionParcial[n]);
double calcularError(int n, double solucion1[n], double solucion2[n]);
void imprimirMatriz(int n, double matrizAumentada[n][n + 1]);
void imprimirResultadosFinales(int n, double solucionTotal[n], double solucionParcial[n]);

// --- Implementación de Funciones ---
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
                while (true) {
            		c = getchar();
            		if (c == '\n')
                		break;
           		}
            }
        } else { 
            break; 
        }

    } while (true);

    return dimension;
}

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
            
			while (true) {
            	c = getchar();
            	if (c == '\n')
                	break;
            }
        } else { 
            break;
        }

    } while (true);

    return numero;
}

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

void copiarMatriz(int n, double origen[n][n + 1], double destino[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            destino[i][j] = origen[i][j];
        
    }
}

double pivoteoParcial(int dimensionMatriz, double matrizAumentada[dimensionMatriz][dimensionMatriz + 1], int k)
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
    
    printf("\nPivote elegido = %.10f (posicion: A[%d][%d])\n", valorMaximo, indicesFilas[filaMax] + 1, indicesVariables[colMax] + 1);
    
	if (fabs(valorMaximo) < 1e-16)
        return 0.0;
    
    if (filaMax != k)
    {
        intercambiarFilas(dimensionMatriz, matrizAumentada, k, filaMax);
        int auxiliar = indicesFilas[k];
        indicesFilas[k] = indicesFilas[filaMax];
        indicesFilas[filaMax] = auxiliar;
        printf("Intercambio de filas: F%d->F%d.\n", k + 1, filaMax + 1);
    }
    if (colMax != k)
    {
        intercambiarColumnas(dimensionMatriz, matrizAumentada, k, colMax);
        int auxiliar = indicesVariables[k];
        indicesVariables[k] = indicesVariables[colMax];
        indicesVariables[colMax] = auxiliar;
        printf("Intercambio de columnas: C%d->C%d.\n", k + 1, colMax + 1);
    }
    return valorMaximo;
}

double limpiarCero(double valor)
{
    if (fabs(valor) < 1e-15)
        return 0.0;
    
    return valor;
}

int determinarTipoSistema(int n, double matrizAumentada[n][n + 1])
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool filaCoeficientesCero = true;
        for (int j = 0; j < n; j++)
        {
            if (fabs(matrizAumentada[i][j]) > 1e-15)
            {
                filaCoeficientesCero = false;
                break;
            }
        }
        if (filaCoeficientesCero)
        {
            if (fabs(matrizAumentada[i][n]) > 1e-15)
                return 0; // Sin solución (0 = b, con b != 0)
            else
                return 1; // Infinitas soluciones (0 = 0)
        }
    }
    return 2; // Solución única
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

void resolverConPivoteoParcial(int n, double matrizOriginal[n][n + 1], double solucionParcial[n])
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
        for (int i = k + 1; i < n; i++)
        {
            double factor = matrizParcial[i][k] / matrizParcial[k][k];
            for (int j = k; j <= n; j++)
                matrizParcial[i][j] -= factor * matrizParcial[k][j];
        }
    }
    
    int tipoSistema = determinarTipoSistema(n, matrizParcial);
    if (esSingular || tipoSistema != 2) // Si la matriz fue singular O el sistema no tiene solución única, retorna.
        return; 
    
    for (int i = n - 1; i >= 0; i--)
    {
        double suma = 0;
        for (int j = i + 1; j < n; j++)
            suma += matrizParcial[i][j] * solucionParcial[j];
        
        if (fabs(matrizParcial[i][i]) < 1e-15)
        {
            solucionParcial[i] = 0;
            continue;
        }
        solucionParcial[i] = (matrizParcial[i][n] - suma) / matrizParcial[i][i];
    }
}

bool resolverConPivoteoTotal(int n, double matrizOriginal[n][n + 1], double solucionFinal[n]) {
    double matrizAumentada[n][n + 1];
    copiarMatriz(n, matrizOriginal, matrizAumentada);
    
    int indicesFilas[n], indicesVariables[n];
    for(int i = 0; i < n; i++) {
        indicesFilas[i] = i;
        indicesVariables[i] = i;
    }

    printf("\n--- Solucion con Pivoteo Total ---\n");
    bool esSingular = false;
    for (int k = 0; k < n - 1; k++) {
        printf("\nPaso %d: Antes del pivoteo\n", k + 1);
        imprimirMatriz(n, matrizAumentada);

        double pivoteActual = pivoteoTotal(n, matrizAumentada, k, indicesFilas, indicesVariables);

        if (fabs(pivoteActual) < 1e-16) {
            esSingular = true;
            break;
        }
        
        printf("\nPaso %d: Despues del pivoteo\n", k + 1);
        imprimirMatriz(n, matrizAumentada); 

        for (int i = k + 1; i < n; i++) {
            double factor = matrizAumentada[i][k] / matrizAumentada[k][k];
            for (int j = k; j <= n; j++)
                matrizAumentada[i][j] -= factor * matrizAumentada[k][j];
        }
    }

    printf("\nMatriz triangular superior final (Pivoteo Total):\n");
    imprimirMatriz(n, matrizAumentada);

    int tipoSistema = determinarTipoSistema(n, matrizAumentada);
    if (esSingular || tipoSistema != 2) {
        if (tipoSistema == 0) 
			printf("\nEl sistema no tiene solucion (inconsistente).\n");
        else 
			printf("\nEl sistema tiene infinitas soluciones.\n"); 
		return false;
    } else {
        double solucionesPermutadas[n];
        for (int i = n - 1; i >= 0; i--) {
            double suma = 0;
            for (int j = i + 1; j < n; j++)
                suma += matrizAumentada[i][j] * solucionesPermutadas[j];
            solucionesPermutadas[i] = (matrizAumentada[i][n] - suma) / matrizAumentada[i][i];
        }
        for (int i = 0; i < n; i++)
            solucionFinal[indicesVariables[i]] = limpiarCero(solucionesPermutadas[i]);
            
        return true;
    }
}


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

void imprimirMatriz(int n, double matrizAumentada[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        printf("[ ");
        for (int j = 0; j <= n; j++)
        {
        	if (j == n)
                printf("| "); 
            
            printf("%.10f ", limpiarCero(matrizAumentada[i][j]));
        }
        printf("]\n");
    }
}

void imprimirResultadosFinales(int n, double solucionTotal[n], double solucionParcial[n]) {
    printf("\n\n------ Resultados ------\n\n");
    printf("Solucion con PIVOTEO TOTAL:\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %.10f\n", i + 1, solucionTotal[i]);

    printf("\nSolucion con Pivoteo Parcial:\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %.10f\n", i + 1, solucionParcial[i]);

    double error = calcularError(n, solucionTotal, solucionParcial);
    printf("\n\n--- Margen de error ---\n");
    printf("La Norma Infinito del error (diferencia maxima absoluta) entre los dos metodos es: %.16e\n", error);

    if (error < 1e-10)
        printf("Las soluciones son numericamente muy similares.\n");
    else
        printf("Las soluciones tienen una variacion.\n");
}
 
int main()
{ 
    printf("Ingrese el numero de ecuaciones (N): ");
    int dimensionMatriz = leerDimension();
 
    double matrizOriginal[dimensionMatriz][dimensionMatriz + 1];
    double solucionTotal[dimensionMatriz];
    double solucionParcial[dimensionMatriz];
    
    leerMatriz(dimensionMatriz, dimensionMatriz, matrizOriginal);

    bool tieneSolucionUnica = resolverConPivoteoTotal(dimensionMatriz, matrizOriginal, solucionTotal);

    if (tieneSolucionUnica) { 
        resolverConPivoteoParcial(dimensionMatriz, matrizOriginal, solucionParcial);
        imprimirResultadosFinales(dimensionMatriz, solucionTotal, solucionParcial);
    }

    return 0;
}