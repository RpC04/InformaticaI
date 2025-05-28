#include <stdio.h>

int main() {
    double a1, b1, c1, a2, b2, c2, x, y;
    printf("Ingrese a1, b1, c1 (primer ecuacion): ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("Ingrese a2, b2, c2 (segunda ecuacion): ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);
    if (b1 != 0) {
        y = (c1*a2 - c2*a1) / (b1*a2 - b2*a1);
        x = (c1 - b1*y) / a1;
        printf("Solucion: x = %.4lf, y = %.4lf\n", x, y);
    } else if (b2 != 0) {
        y = (c1*a2 - c2*a1) / (b1*a2 - b2*a1);
        x = (c2 - b2*y) / a2;
        printf("Solucion: x = %.4lf, y = %.4lf\n", x, y);
    } else {
        printf("No se puede resolver por sustitucion\n");
    }
    return 0;
}