#include <stdio.h>
#include <math.h>
/*
Escrever a função double vpol(int n, double c[ ], double x), de forma recursiva, 
para calcular o valor do polinômio Pn(x) = c0xn +c1xn-1++cn-1x+cn para um dado x.
*/

/*double powy(double x, int n){
    int num = x;
    if (n == 0){
        x = 1;
    }
    for (int c = 1; c < n; c++){
        x = x * num;
    }
    return x;
}*/

double vpol(int n, double c[], double x){
    n--;
    if (n == 0){
        printf("%d: %f\n", n, c[0] * pow(x, n));
        return c[0];
    }
    printf("%d: %f\n", n, c[0] * pow(x, n));
    return c[0] * pow(x, n) + vpol(n, c + 1, x);
}

int main(void){
    double c[] = {2,2,2,2,2};
    double x = 2;

    printf("Polinomios: %f\n", vpol(5, c, x));

    return 0;
}

