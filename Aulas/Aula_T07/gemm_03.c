#include <stdio.h>
#include <stdlib.h>

#define MSIZE 4096 // Tamanho das matrizes

double ** alocaMatriz(int lin, int col)
{
    double **M;
    M = (double **) malloc(lin * sizeof(double *));
    for(int i = 0; i < lin; i++)
        M[i] = (double *) malloc(col * sizeof(double));
    return M;
}

void desalocaMatriz(double **M, int lin)
{
    for(int i = 0; i < lin; i++)
        free(M[i]);
    free(M);
}

void inicializaMatriz(double **M, int lin, int col)
{
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            M[i][j] = rand() % 100;
}

void gemm(  double **A, int m, int p, 
            double **B, int n,
            double **C, 
            double alpha, 
            double beta);

int main(void)
{
    int i, j, k;
    int m = MSIZE, n = MSIZE, p = MSIZE;
    double **A, **B, **C;
    // Aloca as matrizes A, B e C
    A = alocaMatriz(m, p);
    B = alocaMatriz(p, n);
    C = alocaMatriz(m, n);
    // Inicializa as matrizes A e B
    inicializaMatriz(A, m, p);
    inicializaMatriz(B, p, n);
    // Calcula a multiplicação C = A * B
    gemm(A, m, p, B, n, C, 1, 0);
    // Libera a memória alocada
    desalocaMatriz(A, m);
    desalocaMatriz(B, p);
    desalocaMatriz(C, m);
    return EXIT_SUCCESS;
}

void gemm(  double **A, int m, int p, 
            double **B, int n,
            double **C, 
            double alpha, 
            double beta)
{
    int i, j, k;

    // Calcula a multiplicação C = A * B
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            double soma = 0;
            for (k = 0; k < p; k++)
                soma += A[i][k] * B[k][j];
            C[i][j] = alpha * soma + beta * C[i][j];
        }

}