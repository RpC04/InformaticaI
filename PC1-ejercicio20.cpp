#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    printf("Ingrese la dimension de los vectores n: ");
    scanf("%d", &n);

    double u[n], v[n];
    double producto = 0.0, norma_u = 0.0, norma_v = 0.0;
    double proporcion = 0.0;
    int son_paralelos = 1;

    printf("Ingrese los elementos de u y v uno a uno:\n");
    for(i = 0; i < n; i++) {
        printf("u[%d]: ", i+1);
        scanf("%lf", &u[i]);
        printf("v[%d]: ", i+1);
        scanf("%lf", &v[i]);
        producto += u[i] * v[i];
    }

    if(fabs(producto) < 1e-6) {
        printf("\nLos vectores son ortogonales.\n");
        return 0;
    }

    for(i = 0; i < n; i++) {
        if(fabs(v[i]) > 1e-6) {
            proporcion = u[i] / v[i];
            break;
        }
    }
    for(; i < n; i++) {
        if(fabs(v[i]) > 1e-6) {
            if(fabs(u[i] / v[i] - proporcion) > 1e-6) {
                son_paralelos = 0;
                break;
            }
        } else if(fabs(u[i]) > 1e-6) {
            son_paralelos = 0;
            break;
        }
    }

    if(son_paralelos) {
        printf("\nLos vectores son paralelos.\n");
    } else {
        printf("\nLos vectores no son ortogonales ni paralelos.\n");
    }

    return 0;
}
