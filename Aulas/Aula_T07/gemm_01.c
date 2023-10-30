#include <stdio.h>
#include <stdlib.h>

#define MSIZE 100 // Tamanho das matrizes 

void gemm_static(double A[MSIZE][MSIZE], double B[MSIZE][MSIZE], double C[MSIZE][MSIZE])    
{
    int i, j, k;
    int m = MSIZE, n = MSIZE, p = MSIZE;

    // Calcula a multiplicação C = A * B
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main(void)
{
    int i, j;
    int m = MSIZE, n = MSIZE, p = MSIZE;
    double A[m][p], B[p][n], C[m][n];

    // Inicializa as matrizes A e B
    for (i = 0; i < m; i++)
        for (j = 0; j < p; j++)
            A[i][j] = i + j;

    for (i = 0; i < p; i++)
        for (j = 0; j < n; j++)
            B[i][j] = i + j;

    // Calcula a multiplicação C = A * B
    gemm_static(A, B, C);

    // Imprime a matriz C
    /*
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d ", C[i][j]);
    }
    printf("\n");
    */
    return EXIT_SUCCESS;
}


//gcc-13 -Wall -Wextra -g3 -O2 gemm_01.c -o output/gemm_01