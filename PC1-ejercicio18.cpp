#include <stdio.h>

int main() {
    double u[3], v[3], w[3];

    printf("Ingrese los elementos de u y v uno a uno:\n");
    for(int i = 0; i < 3; i++) {
        printf("u[%d]: ", i+1);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i+1);
        scanf("%lf", &v[i]);
    }

    w[0] = u[1]*v[2] - u[2]*v[1];
    w[1] = u[2]*v[0] - u[0]*v[2];
    w[2] = u[0]*v[1] - u[1]*v[0];

    printf("\nEl producto vectorial u x v es:\n");
    printf("w[1] = %.6lf\n", w[0]);
    printf("w[2] = %.6lf\n", w[1]);
    printf("w[3] = %.6lf\n", w[2]);
    return 0;
}
