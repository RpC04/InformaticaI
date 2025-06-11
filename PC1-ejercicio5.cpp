#include <stdio.h>

int main() {

    int n;
    printf("Ingrese el número de coeficientes: ");
    scanf("%d", &n);

    double coeficientes[n], derivada[n-1];

    for(int i = 0; i < n; i++) {
        printf("Ingrese el coeficiente n%d: ", i);
        scanf("%lf", &coeficientes[i]);
    }

    printf("La derivada de la funcion polinomica ingresada es: "); 
    for (int i = 0; i < n-1; i++) {
        derivada[i] = coeficientes[i] * (n - i - 1);
        printf("%.2lf x^%d +\t", derivada[i], n-i-1);
    }

    return 0;
}
