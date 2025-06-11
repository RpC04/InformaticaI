#include <stdio.h>

int main() {
    int n;
    printf("Ingrese la dimension de los vectores n: ");
    scanf("%d", &n);

    double u[n], v[n], proy[n];
    double productoUV = 0, productoVV = 0;

    printf("Ingrese los elementos de u y v:\n");
    for(int i = 0; i < n; i++) {
        printf("\nu[%d]: ", i);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i);
        scanf("%lf", &v[i]);

        productoUV += u[i] * v[i];
        productoVV += v[i] * v[i];
    }

    if(productoVV == 0) {
        printf("\nEl vector v es el vector nulo. No se puede proyectar.\n");
        return 0;
    }

    double escalar = productoUV / productoVV;

    printf("\nLa proyeccion ortogonal de u sobre v es:\n");
    for(int i = 0; i < n; i++) {
        proy[i] = escalar * v[i];
        printf("proy[%d] = %.2lf\n", i, proy[i]);
    }
    return 0;
}
