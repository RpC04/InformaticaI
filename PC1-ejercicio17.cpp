#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C, x0, y0;

    printf("Ingrese los coeficientes de la recta Ax + By + C = 0:\n");
    printf("A: ");
    scanf("%lf", &A);
    printf("B: ");
    scanf("%lf", &B);
    printf("C: ");
    scanf("%lf", &C);

    printf("Ingrese las coordenadas del punto:\n");
    printf("x0: ");
    scanf("%lf", &x0);
    printf("y0: ");
    scanf("%lf", &y0);

    double distancia = fabs(A * x0 + B * y0 + C) / sqrt(A * A + B * B);

    printf("\nLa distancia entre el punto y la recta es: %.2lf\n", distancia);
    return 0;
}
