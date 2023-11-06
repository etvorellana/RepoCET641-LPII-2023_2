#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*4. Crie uma função, para gerar uma imagem, que recebe dois inteiros contendo o
 número de linhas e colunas da mesma. A função retorna um ponteiro de ponteiros
 para inteiros (int** geraImagem(int lin, int col)).

 A matriz gerada
 representa uma imagem, contendo lin x col pixels, e em cada posição da
 mesma temos a intensidade da cor do pixel correspondente, preenchidos de forma
 aleatória, com valores entre 0 e 255*/

int** gerarImagem(int lin, int col)
{
    // alocação dinâmica de memória que cria uma matriz de ponteiros, onde cada ponteiro representa uma linha da matriz.
    // Aqui é indicado a quantidade de linhas
    int** imagem = (int **)malloc(lin * sizeof(int *));

    // Verificação da alocação de memória se foi feita com sucesso. Em casos de erro será exibida uma mensagem
    if (imagem == NULL)
    {
        printf("Memoria nao alocada");
    }
    
    // Inicializar o gerdador de números aleatórios
    srand(time(NULL));

    // Esse é o for externo que percorre cada linha da matriz
    for (int i = 0; i < lin; i++)
    {
        // O loop percorre cada linha e aloca um array com um número determinado de colunas
        imagem[i] = (int *)malloc(col * sizeof(int));

        // Verificação se alocação de memória foi feita com sucesso. Em casos de erro será exibida uma mensagem
        if (imagem[i] == NULL)
        {
            printf("Memoria nao alocada");
        }
        // Esse é o for interno, onde a cada iteração ele preenche os espaços da coluna de cada linha com números aleatórios entre 0 e 255
        for (int j = 0; j < col; j++)
        {
            imagem[i][j] = rand() % 256;
        }
    }
    return imagem;
}
// Ocorre a liberação da memória alocada para a matriz bidimensional. Primeiro as linhas individuais, em seguida a matriz de ponteiros que é a imagem
void freeImagem(int** imagem, int lin){
    for(int i = 0; i < lin; i++){
        free(imagem[i]);
    }
    free(imagem);
}

int main(void)
{

    int lin, col;

    printf("Digite o numero de linhas: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &col);

    int** imagem = gerarImagem(lin, col);

    for(int i = 0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("%4d", imagem [i][j]);
        }
        printf("\n");
    }
    freeImagem(imagem, lin);

    return 0;
}