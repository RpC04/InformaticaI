#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "libreria.h"
int main()
{ 
    printf("============================================\n");
    printf("Programa para determinar el error en pivoteo\n");
    printf("============================================\n");
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