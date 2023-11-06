#include <stdio.h>
#include <stdlib.h>

double *prodvetescal(double *vetA, double a, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        vetA[i] *= a;
    }
    return vetA;
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

int main(void)
{
    int dimensao;
    double valor;

    printf("Digite a dimensao do vetor: ");
    scanf("%d", &dimensao);

    double *A = (double *)malloc(dimensao * sizeof(double));

    if (A == NULL)
    {
        printf("Memória não alocada\n");
        return 1;
    }

    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < dimensao; i++)
    {
        printf("valor %d: ", i + 1);
        scanf("%lf", &A[i]);
    }

    printf("Digite o numero que multiplicara o vetor: ");
    scanf("%lf", &valor);

    prodvetescal(A, valor, dimensao);
    printf("Vetor resultante: ");
    imprimevet(A, dimensao);

    free(A);

    return 0;
}
