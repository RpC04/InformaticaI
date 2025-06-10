#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Ingrese la dimension de los vectores n: ");
    scanf("%d", &n);

    double u[n], v[n];
    double producto = 0, normaU = 0, normaV = 0;
    double x, y;

    printf("Ingrese los elementos de u y v uno a uno:\n");
    for(int i = 0; i < n; i++) {
        printf("u[%d]: ", i);
        scanf("%lf", &x);
        u[i] = x;
        printf("v[%d]: ", i);
        scanf("%lf", &y);
        v[i] = y;

        producto += x * y;
        normaU += x * x;
        normaV += y * y;
    }

    normaU = sqrt(normaU);
    normaV = sqrt(normaV);

    if(normaU == 0 || normaV == 0) {
        printf("\nUno de los vectores es el vector nulo. No se puede calcular el angulo.\n");
        return 0;
    }

    double coseno = producto / (normaU * normaV);

    if(coseno > 1)
        coseno = 1;
    else if(coseno < -1)
        coseno = -1;

    double anguloRad = acos(coseno);
    double anguloDeg = anguloRad * 180 / M_PI;

    printf("\nEl angulo entre u y v es: %.2lf radianes o %.2lf grados\n", anguloRad, anguloDeg);
    return 0;
}
