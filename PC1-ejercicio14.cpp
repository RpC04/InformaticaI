#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Ingrese la dimension del vector n: ");
    scanf("%d", &n);

    double x, norma1 = 0, norma2 = 0, normainf = 0;

    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x);

        double absx = fabs(x);
        norma1 += absx;
        norma2 += x * x;
        if(i == 0 || absx > normainf) {
            normainf = absx;
        }
    }

    norma2 = sqrt(norma2);

    printf("\nNorma 1 = %.2lf\n", norma1);
    printf("Norma 2 = %.2lf\n", norma2);
    printf("Norma infinito = %.2lf\n", normainf);

    return 0;
}
