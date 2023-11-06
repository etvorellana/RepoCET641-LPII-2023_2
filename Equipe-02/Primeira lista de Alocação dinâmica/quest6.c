#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *histograma(int **img, int lin, int col)
{
    int *hist = (int *)malloc(256 * sizeof(int));

    if (hist == NULL)
    {
        printf("Memoria nao alocada");
        return NULL;
    }

    // Inicializa o histograma com zeros
    for (int i = 0; i < 256; i++)
    {
        hist[i] = 0;
    }

    // Calcula o histograma a partir da imagem
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int intensidade = img[i][j];
            hist[intensidade]++;
        }
    }
    return hist;
}
void liberaHistograma(int *hist)
{
    free(hist);
}

int main(void)
{
    int lin = 480;
    int col = 640;

    int **img = (int **)malloc(lin * sizeof(int *));

    if (img == NULL)
    {
        printf("Memoria nao alocada");
    }

    srand(time(NULL));

    for (int i = 0; i < lin; i++)
    {
        img[i] = (int *)malloc(col * sizeof(int));

        if (img[i] == NULL)
        {
            printf("Memoria nao alocada");
        }

        for (int j = 0; j < col; j++)
        {
            img[i][j] = rand() % 256;
        }
    }

    int *hist = histograma(img, lin, col);

    // Imprimir o histograma
    int inicio = 0;
    int fim = 255;

    printf("10 primeiros valores do histograma:\n");
    for (int i = inicio; i < inicio + 10; i++)
    {
        printf("Valor %d: %d\n", i+1, hist[i]);
    }

    printf("\n10 valores centrais do histograma:\n");
    for (int i = 123; i <= 132; i++)
    {
        printf("Valor %d: %d\n", i, hist[i]);
    }

    printf("\n10 ultimos valores do histograma:\n");
    for (int i = 246; i <= fim; i++)
    {
        printf("Valor %d: %d\n", i, hist[i]);
    }

    liberaHistograma(hist);

    // libera a memoria alocada para a imagem
    for (int i = 0; i < lin; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}