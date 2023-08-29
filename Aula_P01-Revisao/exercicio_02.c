/*
    Uma das formas de calcular a raiz quadrada de um número natural é pelo    |
    método das frações periódicas continuadas. Esse método usa como           |
    denominador uma repetição de frações. Essa repetição pode ser feita uma   |
    quantidade específica de vezes. Por exemplo, ao repetir 2 vezes a fração  |
    contínua para calcular a raiz quadrada de 2, temos a fórmula abaixo.      |
     sqrt(2) = 1 + 1 / (2 + 1/2)                                              |
    Sua tarefa é, dado o número N de repetições, calcular o valor aproximado  |
    da raiz quadrada de 2.                                                    |
*/

#include <stdio.h>

int main(void)
{
    int N;
    double raizDe2 = 0.0;
    printf("Calculando a raiz de 2 pelo método das frações periódicas continuadas.\n");
    printf("Digite o número de repetições: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        raizDe2 = 1.0 / (2.0 + raizDe2);
        printf("%d - raizDe2 = \t%.16lf\n", i, 1 + raizDe2);
    }
    raizDe2 += 1.0;
    printf("raizDe2 = \t%.16lf\n", raizDe2);
    return 0;
}
