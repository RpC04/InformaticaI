#include <cmath>
#include <math.h>
#include <stdio.h>

int main() {
    double a, b, c, disc;

    printf("Ingrese los valores de los coeficientes");
    printf("\nAx^2:", a);
    scanf("%lf", &a);
    printf("Bx:", b);
    scanf("%lf", &b);
    printf("C:", c);
    scanf("%lf", &c);

    if (a != 0) {
        disc = b*b - 4*a*c;
        if (disc != 0) {
            if (disc > 0) {
                double x1 = (-b + sqrt(disc)) / (2*a);
                double x2 = (-b - sqrt(disc)) / (2*a);
                printf("\nLas soluciones son: ");
                printf("\nx1 = %.2f", x1);
                printf("\nx2 = %.2f", x2);
            } else {
                double pReal = (-b) / (2*a);
                double pImag = sqrt(-disc) / (2*a);
                printf("\nLas soluciones son: ");
                printf("\nx1 = %.2f + i %.2f", pReal, pImag);
                printf("\nx2 = %.2f - i %.2f", pReal, pImag);
            }
        } else {
            double x = (-b) / (2*a);
            printf("\nLas solucion es: ");
            printf("\nx1, x2 = %.2f", x);
        }
    } else if (b != 0) {
        double x = -c / b;
        printf("\nLa solucion es: ");
        printf("\nx1, x2 = %.2f", x);
    } else {
        printf("\nLa ecuacion no tiene solucion");
    }
    return 0;
}