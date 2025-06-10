#include <stdio.h>

int main() {
    int n;
    printf("Ingrese la dimension del espacio n: ");
    scanf("%d", &n);

    double producto = 0, u, v;

    printf("Ingrese los elementos de ambos vectores (u y v) uno a uno:\n");
    for(int i = 0; i < n; i++) {
        printf("u[%d]: ", i);
        scanf("%lf", &u);
        printf("v[%d]: ", i);
        scanf("%lf", &v);
        producto += u * v;
    }

    printf("\nEl producto punto de u y v es: %.2lf\n", producto);
    return 0;
}
