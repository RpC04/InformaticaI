#include <stdio.h>

int main() {
    int numTerm;
    double x, resultado = 1, termSuce = 1;

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    printf("\nIngrese el numero de terminos n: ");
    scanf("%d", &numTerm);

    for (int i = 1; i < numTerm; i++) {
        termSuce = termSuce * x / i;
        resultado += termSuce;
    }

    printf("\nAproximacion de e^%lf usando %d termSuces: %lf\n", x, numTerm, resultado);

    return 0;
}
