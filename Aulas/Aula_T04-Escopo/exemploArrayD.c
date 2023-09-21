#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers_Aula04.h"

int main(void)
{
    srand(time(NULL));
    double x[10];
    printf("%lu\n", sizeof(x));
    geraArrayRandom(x, 10, 5, 12);
    for(int i = 0 ; i < 10 ; i++)
        printf("%lf ", x[i]);
    printf("\n");
    geraArrayRandomR(x, 10, 5, 12);
    for(int i = 0 ; i < 10 ; i++)
        printf("%lf ", x[i]);
    printf("\n");
    return 0;
}


void geraArrayRandom(double x[], int n, int a, int b)
{
    printf("%lu\n", sizeof(x));
    for(int i = 0 ; i < n ; i++)
        x[i] = (double)rand() / RAND_MAX * (b - a) + a;
    return;
}

void geraArrayRandomR(double x[], int n, int a, int b)
{
    if (n == 0)
        return;
    x[n-1] = (double)rand() / RAND_MAX * (b - a) + a;
    geraArrayRandomR(x, n - 1, a, b);
    return;
}

