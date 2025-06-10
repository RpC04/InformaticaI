#include <stdio.h>

int main() {
    int n;
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);

    double a[n];

    for(int i = 0; i < n; i++) {
        printf("a[%d]: ", i+1);
        scanf("%lf", &a[i]);
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                double temporal = a[j];
                a[j] = a[j+1];
                a[j+1] = temporal;
            }
        }
    }

    printf("\nLista ordenada:\n");
    for(int i = 0; i < n; i++) {
        printf("%.2lf\n", a[i]);
    }

    return 0;
}
