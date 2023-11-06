#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Crie uma função para liberar o espaço de memória ocupado por uma imagem matriz
de inteiros. A função recebe um ponteiro de ponteiros para inteiros, contendo valores
entre 0 e 255, dois inteiros contendo o número de linhas e colunas do array (void
liberaImagem(int** img, int lin, int col). Implemente uma aplicação que:

a. Gere uma imagem de 640 x 480 pixels preenchidos de forma aleatória e
mostre os 25 pixels do canto superior esquerdo (a submatriz de 5x5 do
campo superior esquerdo).

b. Libere a memória alocada para a imagem;

*/

int** geraImagem(int lin, int col)
{

    int** img = (int**)malloc(lin * sizeof(int*));

    if (img == NULL)
    {
        printf("Memoria nao alocada");
        return NULL;
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
    return img;
}
void liberaImagem(int** img, int lin)
{
    for (int i = 0; i < lin; i++)
    {
        free(img[i]);
    }
    free(img);
}

int main(void)
{

    int lin = 480, col = 640;

    int** img = geraImagem(lin, col);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%8d", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}