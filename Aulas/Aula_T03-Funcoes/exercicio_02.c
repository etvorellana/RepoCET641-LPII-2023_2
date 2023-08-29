#include <stdio.h>

double calcRaizDe2(int N, int mostra);

int main(void)
{
    int N;
    double raizDe2 = 0.0;
    printf("Calculando a raiz de 2 pelo método das frações periódicas continuadas.\n");
    printf("Digite o número de repetições: ");
    scanf("%d", &N);
    raizDe2 = calcRaizDe2(N, 0);
    printf("Com %d repetições, a raiz de 2 é aproximadamente: %.16lf\n", N, raizDe2);
    return 0;
}

double calcRaizDe2(int N, int mostra)
{
    double raizDe2 = 0.0;
    for (int i = 1; i <= N; i++)
    {
        raizDe2 = 1.0 / (2.0 + raizDe2);
        if (mostra)
            printf("%d - raizDe2 = \t%.16lf\n", i, 1 + raizDe2);
    }
    raizDe2 += 1.0;
    return raizDe2;
}
