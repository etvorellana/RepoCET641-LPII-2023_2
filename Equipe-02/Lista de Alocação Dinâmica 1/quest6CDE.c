#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* histograma(int **img, int lin, int col)
{
    int *hist = (int *)malloc(256 * sizeof(int));

    if (hist == NULL)
    {
        printf("Memoria nao alocada");
        return NULL;
    }

    // Inicializando cada posição do histograma com 0
    for (int i = 0; i < 256; i++)
    {
        hist[i] = 0;
    }

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

void preencheFundo(int **imagem, int lin, int col, int corFundo)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            imagem[i][j] = corFundo;
        }
    }
}

void desenhaRetangulo(int **imagem, int x, int y, int largura, int altura, int cor)
{
    for (int i = x; i < x + largura; i++)
    {
        for (int j = y; j < y + altura; j++)
        {
            imagem[i][j] = cor;
        }
    }
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
        return 1;
    }

    for (int i = 0; i < lin; i++)
    {
        img[i] = (int *)malloc(col * sizeof(int));

        if (img[i] == NULL)
        {
            printf("Memoria nao alocada");
            return 1;
        }
    }

    // Preenche o fundo de branco (cor 255)
    preencheFundo(img, lin, col, 255);

    // Desenha um retângulo de cor 125 no meio da imagem
    int x = (lin - 200) / 2;
    int y = (col - 300) / 2;

    desenhaRetangulo(img, x, y, 200, 300, 125);

    // Desenha um retângulo de cor 0 dentro do retângulo anterior
    x = (lin - 100) / 2;
    y = (col - 100) / 2;
    desenhaRetangulo(img, x, y, 100, 100, 0);

    srand(time(NULL));

    for (int i = 0; i < lin; i++)
    {
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
        printf("Valor %d: %d\n", i, hist[i]);
    }

    printf("\n10 ultimos valores do histograma:\n");
    for (int i = fim - 10; i <= fim; i++)
    {
        printf("Valor %d: %d\n", i, hist[i]);
    }

    printf("\n10 valores centrais do histograma:\n");
    for (int i = 123; i <= 132; i++)
    {
        printf("Valor %d: %d\n", i, hist[i]);
    }

    liberaHistograma(hist);

    // Libera a memória alocada para a imagem
    for (int i = 0; i < lin; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}
