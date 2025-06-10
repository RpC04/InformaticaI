#include <stdio.h>
#include <math.h>

int main() {
    int n, funcion;
    double a, b, h, area = 0.0, x0, x1, fx0, fx1;

    printf("Seleccione la funcion a utilizar:\n");
    printf("1. f(x) = x*x\n");
    printf("2. f(x) = e^(x)\n");
    printf("3. f(x) = ln(x)\n");
    printf("4. f(x) = 2*x*x*x - 3*x*x + x\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &funcion);

    printf("Ingrese el limite inferior a: ");
    scanf("%lf", &a);
    printf("Ingrese el limite superior b: ");
    scanf("%lf", &b);
    printf("Ingrese el numero de subintervalos: ");
    scanf("%d", &n);

    h = (b - a) / n;

    for (int i = 0; i < n; i++) {
        x0 = a + i * h;
        x1 = a + (i + 1) * h;

        switch(funcion) {
            case 1:
                fx0 = x0 * x0;
                fx1 = x1 * x1;
                break;
            case 2:
                fx0 = exp(x0);
                fx1 = exp(x1);
                break;
            case 3:
                if(x0 > 0)
                    fx0 = log(x0);
                else {
                    printf("Advertencia: ln(%.2lf) no definido. Se toma f(%.2lf) = 0.\n", x0, x0);
                    fx0 = 0;
                }
                if(x1 > 0)
                    fx1 = log(x1);
                else {
                    printf("Advertencia: ln(%.2lf) no definido. Se toma f(%.2lf) = 0.\n", x1, x1);
                    fx1 = 0;
                }
                break;
            case 4:
                fx0 = 2*x0*x0*x0 - 3*x0*x0 + x0;
                fx1 = 2*x1*x1*x1 - 3*x1*x1 + x1;
                break;
            default:
                fx0 = 0;
                fx1 = 0;
                break;
        }

        area += h / 2.0 * (fx0 + fx1);
    }

    printf("\nEl area bajo la curva es: %.2lf\n", area);
    return 0;
}

