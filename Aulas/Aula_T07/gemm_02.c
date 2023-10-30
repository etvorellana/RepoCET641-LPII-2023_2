#include <stdio.h>
#include <stdlib.h>

#define MSIZE 100 // Tamanho das matrizes

int main(void)
{
    double *x;
    double **M;


    x = (double *) malloc(MSIZE * sizeof(double));
    //x = (double *) calloc(MSIZE, sizeof(double));
    //realloc(x, 2 * MSIZE * sizeof(double));

    M = (double **) malloc(MSIZE * sizeof(double *));
    for(int i = 0; i < MSIZE; i++)
        M[i] = (double *) malloc(MSIZE * sizeof(double));
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            M[i][j] = rand() % 100;
    
    for(int i = 0; i < MSIZE; i++)
        x[i] = rand() % 100;
    
    for(int i = 0; i < MSIZE; i++)
        free(M[i]);
    free(M);
    
    free(x);



    return 0;
}
