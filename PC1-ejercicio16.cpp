#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Ingrese la dimension de los vectores n: ");
    scanf("%d", &n);

    double u[n], v[n];
    double producto = 0.0, norma_u = 0.0, norma_v = 0.0;
    double x, y;

    printf("Ingrese los elementos de u y v uno a uno:\n");
    for(int i = 0; i < n; i++) {
        printf("u[%d]: ", i+1);
        scanf("%lf", &x);
        u[i] = x;
        printf("v[%d]: ", i+1);
        scanf("%lf", &y);
        v[i] = y;

        producto += x * y;
        norma_u += x * x;
        norma_v += y * y;
    }

    norma_u = sqrt(norma_u);
    norma_v = sqrt(norma_v);

    if(norma_u == 0 || norma_v == 0) {
        printf("\nUno de los vectores es el vector nulo. No se puede calcular el angulo.\n");
        return 0;
    }

    double coseno = producto / (norma_u * norma_v);

    if(coseno > 1.0) coseno = 1.0;
    if(coseno < -1.0) coseno = -1.0;

    double angulo_rad = acos(coseno);
    double angulo_deg = angulo_rad * 180.0 / M_PI;

    printf("\nEl angulo entre u y v es: %.6lf radianes o %.6lf grados\n", angulo_rad, angulo_deg);
    return 0;
}
