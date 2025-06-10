#include <stdio.h>

int main() {
    double n1, n2, n3;

    printf("Ingrese el coeficiente n1 (x^3): ");
    scanf("%lf", &n1);
    printf("Ingrese el coeficiente n2 (x^2): ");
    scanf("%lf", &n2);
    printf("Ingrese el coeficiente n3 (x): ");
    scanf("%lf", &n3);

    int e1 = 3;
    int e2 = 2;
    int e3 = 1;

    double d1 = n1 * e1;
    double d2 = n2 * e2;
    double d3 = n3 * e3;

    printf("\nLa derivada es:\n");
    printf("%.2lfx^2 + %.2lfx + %.2lf\n", d1, d2, d3);

    return 0;
}
