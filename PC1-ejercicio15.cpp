#include <stdio.h>

int main() {
    int n;
    printf("Ingrese la dimension de los vectores n: ");
    scanf("%d", &n);

    double u[n], v[n], proy[n];
    double producto_uv = 0.0, producto_vv = 0.0, escalar;

    printf("Ingrese los elementos de u y v uno a uno:\n");
    for(int i = 0; i < n; i++) {
        printf("u[%d]: ", i+1);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i+1);
        scanf("%lf", &v[i]);
    }

    for(int i = 0; i < n; i++) {
        producto_uv += u[i] * v[i];
        producto_vv += v[i] * v[i];
    }

    if(producto_vv == 0) {
        printf("\nEl vector v es el vector nulo. No se puede proyectar.\n");
        return 0;
    }

    escalar = producto_uv / producto_vv;

    printf("\nLa proyeccion ortogonal de u sobre v es:\n");
    for(int i = 0; i < n; i++) {
        proy[i] = escalar * v[i];
        printf("proy[%d] = %.6lf\n", i+1, proy[i]);
    }
    return 0;
}
