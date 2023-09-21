#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int maiorElemento(int array[], int n);

int main(void)
{
    srand(time(NULL));
    int notas[N];
    for(int i = 0; i < N; i++)
        notas[i] = rand()%101;

    return 0;
}

int maiorElemento(int array[], int n)
{
    int max = array[0];
    for(int i = 1; i < n; i++)
        if (max < array[i])
            max = array[i];
    return max;    
}

int maiorElementoR(int array[], int n)
{
    if(n == 1)
        return array[0];
    int max = maiorElementoR(&array[1], n-1);
    return array[0] > max ? array[0]:max;
}

