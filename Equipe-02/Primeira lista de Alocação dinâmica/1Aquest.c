#include <stdio.h>
#include <stdlib.h>

double* somavet(double *vetA, double *vetB, int dim){

    double* vetC = (double*) malloc(dim * sizeof(double));
    for (int i = 0; i < dim; i++)
    {
        vetC[i] = vetA[i] + vetB[i];
    }
    return vetC;
}

void imprimevet(double *vetA, int dim)
{
    printf("\n{");
    for (int i = 0; i < dim; i++)
    {
        printf(" %.1f,", vetA[i]);
    }
    printf("}\n");
}

int main (void ){

    int dimensao;

    printf("Digite a dimensao dos vetores: ");
    scanf("%d", &dimensao);

    double *A = (double *)malloc(dimensao * sizeof(double));
    double *B = (double *)malloc(dimensao * sizeof(double));
    double *C = (double *)malloc(dimensao * sizeof(double));

    if(A == NULL || B == NULL || C == NULL){
        printf("Memoria nao alocada");
        return 1;
    }

    printf("Digite os valores do vetor 1:\n");
    for (int i = 0; i < dimensao; i++)
    {
        printf("valor %d: ", i + 1);
        scanf("%lf", &A[i]);
    }

    printf("Digite os valores do vetor 2:\n");
    for (int i = 0; i < dimensao; i++)
    {
        printf("valor %d: ", i + 1);
        scanf("%lf", &B[i]);
    }

    C = somavet(A, B, dimensao);
    printf("Vetor resultante: ");
    imprimevet(C, dimensao);

    free(A);
    free(B);
    free(C);

    return 0;
}
