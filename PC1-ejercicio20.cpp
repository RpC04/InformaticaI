#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Ingrese la dimension de los vectores n: ");
    scanf("%d", &n);

    double u[n], v[n], producto = 0;
    printf("Ingrese los elementos de u y v uno a uno:\n");
    for (int i = 0; i < n; i++) {
        printf("\nu[%d]: ", i);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i);
        scanf("%lf", &v[i]);
        producto += u[i] * v[i];
    }

    if (fabs(producto) == 0) {
        printf("\nLos vectores son ortogonales.\n");
    } else {
        double proporcion = 0;
        int sonParalelos = 1, primero = 1;

        for (int i = 0; i < n; i++) {
            if (fabs(v[i]) != 0) {
                if (primero) {
                    proporcion = u[i] / v[i];
                    primero = 0;
                } else if (fabs(u[i] / v[i] - proporcion) != 0) {
                    sonParalelos = 0;
                    break;
                }
            } else if (fabs(u[i]) != 0) {
                sonParalelos = 0;
                break;
            }
        }

        if (sonParalelos)
            printf("\nLos vectores son paralelos.\n");
        else
            printf("\nLos vectores no son ortogonales ni paralelos.\n");
    }

    return 0;
}
