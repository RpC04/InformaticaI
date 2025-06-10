#include <stdio.h>

int main() {
    double u[3], v[3], w[3];
    double v_cross_w[3];
    double triple;

    printf("Ingrese los elementos de u, v y w uno a uno:\n");
    for(int i = 0; i < 3; i++) {
        printf("u[%d]: ", i+1);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i+1);
        scanf("%lf", &v[i]);
        printf("w[%d]: ", i+1);
        scanf("%lf", &w[i]);
    }

    v_cross_w[0] = v[1]*w[2] - v[2]*w[1];
    v_cross_w[1] = v[2]*w[0] - v[0]*w[2];
    v_cross_w[2] = v[0]*w[1] - v[1]*w[0];

    triple = u[0]*v_cross_w[0] + u[1]*v_cross_w[1] + u[2]*v_cross_w[2];

    printf("\nEl triple producto escalar es: %.6lf\n", triple);
    return 0;
}
