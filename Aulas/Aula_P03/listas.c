#include <stdio.h>

struct livro
{
    char titulo[50];
    char autor[50];
    int ano;
    int paginas;
    float preco;
};

typedef struct livro Livro;

typedef struct no   // Nó da lista  
{
    Livro info;
    struct no *prox;
} No;


typedef struct lista
{
    No *inicio;
    No *fim;
    int qtd;
} Lista;

/*
    Função: criarNo
    Objetivo: Criar um novo nó para a lista
    Parâmetros: Livro livro - livro a ser inserido no nó
    Retorno: No* - ponteiro para o nó criado
*/
No* criarNo(Livro livro)
{
    //...
}

/*
    Função: adicionarNo
    Objetivo: Adicionar um nó n final da lista
    Parâmetros: Lista *lista - ponteiro para a lista
                No *no - ponteiro para o nó a ser adicionado
    Retorno: int - 1 se conseguiu adicionar o nó, 0 caso contrário
*/

int adicionaLivroNoFinal(Lista *lista, Livro livro)
{
    //...
}

/*
    Função: adicionarNoInicio
    Objetivo: Adicionar um nó no início da lista
    Parâmetros: Lista *lista - ponteiro para a lista
                No *no - ponteiro para o nó a ser adicionado
    Retorno: int - 1 se conseguiu adicionar o nó, 0 caso contrário
*/
int adicionaLivroNoInicio(Lista *lista, Livro livro)
{
    //...
}

/*
    Função: adicionarNoMeio
    Objetivo: Adicionar um nó no meio da lista
    Parâmetros: Lista *lista - ponteiro para a lista
                No *no - ponteiro para o nó a ser adicionado
                int pos - posição onde o nó será adicionado
    Retorno: int - 1 se conseguiu adicionar o nó, 0 caso contrário
*/
int adicionarNoMeio(Lista *lista, Livro livro, int pos)
{
    //...
}

void printLista(Lista *lista)
{
    //...
}

/*
    Função: removerNoInicio
    Objetivo: Remover um nó do início da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: int - 1 se conseguiu remover o nó, 0 caso contrário
*/
int removerNoInicio(Lista *lista)
{
    //...
}

/*
    Função: removerNoFinal
    Objetivo: Remover um nó do final da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: int - 1 se conseguiu remover o nó, 0 caso contrário
*/
int removerNoFinal(Lista *lista)
{
    //...
}

/*
    Função: removerNoMeio
    Objetivo: Remover um nó do meio da lista
    Parâmetros: Lista *lista - ponteiro para a lista
                int pos - posição onde o nó será removido
    Retorno: int - 1 se conseguiu remover o nó, 0 caso contrário
*/
int removerNoMeio(Lista *lista, int pos)
{
    //...
}

int main(int argc, char const *argv[])
{
    Lista meusLivros;
    meusLivros.inicio = NULL;
    meusLivros.fim = NULL;
    meusLivros.qtd = 0;


    return 0;
}
