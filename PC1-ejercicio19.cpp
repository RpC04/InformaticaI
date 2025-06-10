#include <stdio.h>

int main() {
    double u[3], v[3], w[3];
    double vCrossW[3];

    printf("Ingrese los elementos de u, v y w uno a uno:\n");
    for(int i = 0; i < 3; i++) {
        printf("u[%d]: ", i);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i);
        scanf("%lf", &v[i]);
        printf("w[%d]: ", i);
        scanf("%lf", &w[i]);
    }

    vCrossW[0] = v[1]*w[2] - v[2]*w[1];
    vCrossW[1] = v[2]*w[0] - v[0]*w[2];
    vCrossW[2] = v[0]*w[1] - v[1]*w[0];

    double triple = u[0] * vCrossW[0] + u[1] * vCrossW[1] + u[2] * vCrossW[2];

    printf("\nEl triple producto escalar es: %.2lf\n", triple);
    return 0;
}
