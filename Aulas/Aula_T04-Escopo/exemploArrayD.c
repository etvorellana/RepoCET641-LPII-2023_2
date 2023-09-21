#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers_Aula04.h"

int main(void)
{
    srand(time(NULL));
    double x[10];
    geraArrayRandom(x, 10, 5, 12);
    return 0;
}


void geraArrayRandom(double x[], int n, int a, int b)
{
    for(int i = 0 ; i < n ; i++)
        x[i] = (double)rand() / RAND_MAX * (b - a) + a;
    return;
}

void geraArrayRandonR(double x[], int n, int a, int b)
{
    if (n = 0)
        return;
    x[n-1] = (double)rand() / RAND_MAX * (b - a) + a;
    geraArrayRandonR(x, n - 1, a, b);
    return;
}

