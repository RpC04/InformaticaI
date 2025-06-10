#include <stdio.h>

int main() {
    double limInf, limSup;
    int numRectangulos;
    double delta, suma = 0, x_i;
    
    printf("Ingrese el limite inferior: ");
    scanf("%lf", &limInf);
    printf("\nIngrese el limite superior: ");
    scanf("%lf", &limSup);
    printf("\nIngrese el numero de rectangulos: ");
    scanf("%d", &numRectangulos);

    delta = (limSup - limInf) / numRectangulos;

    for (int i = 0; i < numRectangulos; i++) {
        x_i = limInf + i * delta;
        suma += (2*x_i*x_i + 3*x_i + 5) * delta;
    }

    printf("\nAproximacion de la integral definida es: %lf\n", suma);

    return 0;
}
