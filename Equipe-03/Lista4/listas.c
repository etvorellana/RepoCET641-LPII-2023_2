#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    No *no = (No*) malloc(sizeof(No));
    no->info = livro;
    no->prox = NULL;
    return no;
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
    No *new = (No*) malloc(sizeof(No));
    
    new->info = livro;
    new->prox = NULL;

    if (lista->inicio != NULL){
        lista->fim->prox = new;
        lista->fim = new;
        lista->qtd++;
        return 1;
    }

    lista->inicio = new;
    lista->fim = new;
    lista->qtd++;
    return 1;
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
    No *new = (No*) malloc(sizeof(No));
    new->info = livro;
    new->prox = lista->inicio;
    lista->inicio = new;
    lista->qtd++;
    return 1;
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
    No *new = (No*) malloc(sizeof(No));
    new->info = livro;
    lista->qtd++;
    /* Considerando que o meio seja o meio da lista atual e não o meio da lista com mais um elemento
    Caso seja o meio de mais um elemento é so fazer pos++ */
    //pos++;
    if (lista->inicio == NULL){
        new->prox = NULL;
        lista->inicio = new;
        lista->fim = new;
        return 1;
    }else if (lista->inicio->prox != NULL && pos != 1){
        // Considerando que se queira adicionar no meio, pos é reduzido pela metade;
        pos = (pos % 2 == 0) ?   pos / 2: pos / 2 + 1;

        int c = 1;
        No *aux = NULL, *var = lista->inicio;

        while ((c < pos) && (var != NULL)){
            aux = var;
            var = var->prox;
            c++;
        }
        if (var == NULL) lista->fim = new;
        new->prox = var;
        aux->prox = new;
        return 1;
    } else if(pos == 1){
        new->prox = lista->inicio;
        lista->inicio = new;
        return 1;
    } else{
        return 0;
    }
}

void printLista(Lista *lista)
{
    No *aux = lista->inicio;
    int c = 1;
    while (aux != NULL){
        printf("\tLivro %d\n", c);
        printf("Título: %s\n", aux->info.titulo);
        printf("Autor: %s\n", aux->info.autor);
        printf("Ano: %d\n", aux->info.ano);
        printf("Páginas: %d\n", aux->info.paginas);
        printf("Preço: %.2f\n", aux->info.preco);
        printf("\n");
        aux = aux->prox;
        c++;
    }
}

/*
    Função: removerNoInicio
    Objetivo: Remover um nó do início da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: Retorna o livro removido
*/
Livro removerNoInicio(Lista *lista)
{   
    Livro removido;
    if(lista->inicio != NULL){
        No *aux = lista->inicio;
        removido = aux->info;
        lista->inicio = lista->inicio->prox;
        free(aux);
        lista->qtd--;
        return removido;
    }

    strcpy(removido.titulo, "NULL");
    return removido;

}

/*
    Função: removerNoFinal
    Objetivo: Remover um nó do final da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: Retorna o livro removido
*/
Livro removerNoFinal(Lista *lista)
{
    Livro removido;

    if(lista->fim != NULL){
        removido = lista->fim->info;
        No * aux = lista->inicio;
        while (aux->prox != lista->fim){
            aux = aux->prox;
        }
        free(aux->prox);
        aux->prox = NULL;
        lista->fim = aux;
        lista->qtd--;
        return removido;
    }
    strcpy(removido.titulo, "NULL");
    return removido;
}

/*
    Função: removerNoMeio
    Objetivo: Remover um nó do meio da lista
    Parâmetros: Lista *lista - ponteiro para a lista
                int pos - posição onde o nó será removido
    Retorno: Retorna o livro removido
*/
Livro removerNoMeio(Lista *lista, int pos)
{
    Livro removido;
    No *aux = lista->inicio;
    if (aux == NULL){
        strcpy(removido.titulo, "NULL");
        return removido;
    }else if (aux->prox == NULL){
        free(aux);
        strcpy(removido.titulo, "NULL");
        lista->qtd--;
        return removido;
    }else if(pos != 1){
        // Considerando que se queira remover no meio, pos é reduzido pela metade;
        pos = (pos % 2 == 0) ?   pos / 2: pos / 2 + 1;
        int c = 1;
        No *var = NULL;

        while ((c < pos) && (aux->prox != NULL)){
            var = aux;
            aux = aux->prox;
            c++;
        }
        if (aux->prox == NULL) lista->fim = var;
        var->prox = aux->prox;
        removido = aux->info;
        free(aux);
        lista->qtd--;
        return removido;
    } else{
        lista->inicio = aux->prox;
        free(aux);
        lista->qtd--;
        return removido;
    }
}

// Função para criar os livros mais facilmente
Livro criarlivro(char titulo[], char autor[], int ano, int paginas, float preco){
    Livro livro;
    strcpy(livro.titulo, titulo);
    strcpy( livro.autor, autor);
    livro.ano = ano;
    livro.paginas = paginas;
    livro.preco = preco;
    return livro;
}

int main(int argc, char const *argv[])
{
    Lista *meusLivros = (Lista*) malloc(sizeof(Lista));
    meusLivros->inicio = NULL;
    meusLivros->fim = NULL;
    meusLivros->qtd = 0;
    Livro l1, l2, l3, l4, l5;
    l1 = criarlivro("Teste 1", "Yuri", 2023, 20, 10.0f);
    l2 = criarlivro("Chimichanga", "Donatello", 2015, 340, 40.0f);
    l3 = criarlivro("Why linux its better", "annon", 2021, 777, 1.99f);
    l4 = criarlivro("Caro Vapor", "Don L", 2013, 13, 0.00f);
    l5 = criarlivro("Linha de Frente", "Rashid", 2022, 5, 0.00f);

    
    meusLivros->inicio = criarNo(l1);
    meusLivros->fim = meusLivros->inicio;
    meusLivros->qtd = 1;
    //printLista(meusLivros);

    adicionaLivroNoFinal(meusLivros, l2);
    adicionaLivroNoFinal(meusLivros, l3);
    //printf("Adicionado Livro no final\n");
    //printLista(meusLivros);

    
    adicionaLivroNoInicio(meusLivros, l4);
    //printf("Adicionado Livro no Inicio\n");
    //printLista(meusLivros);
    
    adicionarNoMeio(meusLivros, l5, meusLivros->qtd);
    //printf("Adicionado Livros no meio\n");
    printLista(meusLivros);

    Lista *lremovidos = (Lista*) malloc(sizeof(Lista));
    //lremovidos->inicio = criarNo(removerNoFinal(meusLivros));
    //lremovidos->inicio = criarNo(removerNoInicio(meusLivros));
    lremovidos->inicio = criarNo(removerNoMeio(meusLivros, meusLivros->qtd));
    printf("Removidos:\n");
    printLista(lremovidos);
    printf("Lista atual: ----------------------------------------------\n");
    printLista(meusLivros);

    return 0;
}

