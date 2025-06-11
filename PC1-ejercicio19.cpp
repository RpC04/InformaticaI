#include <stdio.h>

int main() {
    double u[3], v[3], w[3];
    double productoCruzadoVW[3];

    printf("Ingrese los elementos de u, v y w:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nu[%d]: ", i);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i);
        scanf("%lf", &v[i]);
        printf("w[%d]: ", i);
        scanf("%lf", &w[i]);
    }

    productoCruzadoVW[0] = v[1] * w[2] - v[2] * w[1];
    productoCruzadoVW[1] = v[2] * w[0] - v[0] * w[2];
    productoCruzadoVW[2] = v[0] * w[1] - v[1] * w[0];

    double triple = u[0] * productoCruzadoVW[0] +
                    u[1] * productoCruzadoVW[1] +
                    u[2] * productoCruzadoVW[2];

    printf("\nEl triple producto escalar es: %.2lf\n", triple);

    return 0;
}
