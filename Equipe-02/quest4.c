/* Questãao 4. Crie uma função que recebe um array bidimensional com valores inteiros entre 0 e 255,
dois inteiros contendo o número de linhas e colunas do array, e um array de
inteiros (void histograma(int img[ ][ ], int lin, int col,int hist[ ])) e retorna, no array de inteiros,
quantas vezes aparece na matriz cada uma dos 256 possíveis valores. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// cabeçalho da função
void histograma(int img[255][255], int lin, int col, int hist[]);

int main()
{

    int lin, col, hist[256], img[255][255];

    printf("Digite o numero de linhas: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &col);

  
    printf("\n");

    // inicializando a semente para gerar números aleatórios
    srand(time(NULL));

    // Gera números aleatórios entre 0 e 255 para preencher a matriz
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            img[i][j] = rand() % 256;
        }
    }

    printf("Valores inteiros entre 0 e 255: \n");
    // Exibição dos números aleatórios na matriz
    for (int i = 0; i < lin; i++)
    {
        printf("\n");
        for (int j = 0; j < col; j++)
        {
            printf(" %8d ", img[i][j]);
        }
    }

    printf("\n\n");

    histograma(img, lin, col, hist);

    // Exibir o histograma
    for (int i = 0; i < 256; i++)
    {
        printf("Valor %d: %d vezes\n", i, hist[i]);
    }

    return 0;
}
void histograma(int img[255][255], int lin, int col, int hist[])
{
    // Zerando o histograma para garantir que todas as posições inicializem com 0
    for (int i = 0; i < 256; i++)
    {
        hist[i] = 0;
    }

    // Contagem de quantas vezes cada elemento aparece na matriz
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int cont = img[i][j];
            hist[cont]++;
        }
    }

    return;
}
