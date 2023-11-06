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
  No *novoNo = (No*)malloc(sizeof(No));
  novoNo->info = livro;
  novoNo->prox = NULL;
  return novoNo;
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
  No *novoNo = criarNo(livro);
  if(novoNo == NULL)
    return 0;
  if(lista->inicio == NULL)
    lista->inicio = novoNo;
  else
    lista->fim->prox = novoNo;
  lista->fim = novoNo;
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
  No *novoNo = criarNo(livro);
  if(novoNo == NULL) 
    return 0;
  if(lista->inicio == NULL)
    lista->fim = novoNo;
  novoNo->prox = lista->inicio; // o novo nó aponta para o antigo primeiro nó
  lista->inicio = novoNo;
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
  No *novoNo = criarNo(livro);
  if(novoNo == NULL)
    return 0;
  if(pos < 0 || pos > lista->qtd)
    return 0;
  if(pos == 0)
    return adicionaLivroNoInicio(lista, livro);
  if(pos == lista->qtd)
    return adicionaLivroNoFinal(lista, livro);
  No *aux = lista->inicio; // nó auxiliar para percorrer a lista
  for(int i = 0; i < pos - 1; i++) // percorre a lista até a posição anterior ao nó a ser inserido
    aux = aux->prox; // avança para o próximo nó
  novoNo->prox = aux->prox; // o novo nó aponta para o próximo nó do nó anterior ao nó a ser inserido
  aux->prox = novoNo; // o nó anterior ao nó a ser inserido aponta para o novo nó 
  lista->qtd++;
  return 1;
}


void printLista(Lista *lista)
{
  No *aux = lista->inicio;
  while(aux != NULL)
    printf("%s ", aux->info.titulo);
  aux = aux->prox;
  printf("\n");
    
}

/*
    Função: removerNoInicio
    Objetivo: Remover um nó do início da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: Retorna o livro removido
*/
Livro removerNoInicio(Lista *lista)
{
  No *aux = lista->inicio; // nó auxiliar para percorrer a lista
  Livro livro = aux->info;
  lista->inicio = aux->prox; // o primeiro nó passa a ser o segundo nó
  free(aux);
  lista->qtd--;
  return livro;
}

/*
    Função: removerNoFinal
    Objetivo: Remover um nó do final da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: Retorna o livro removido
*/
Livro removerNoFinal(Lista *lista)
{
  No *aux = lista->inicio; // nó auxiliar para percorrer a lista  
  No *aux2 = NULL; // nó auxiliar para guardar o nó anterior ao nó a ser removido
  Livro livro = aux->info;
  while(aux->prox != NULL) // percorre a lista até o último nó 
    aux2 = aux; // o nó anterior ao nó a ser removido recebe o nó atual
    aux = aux->prox; 
  if(aux2 == NULL) 
    lista->inicio = NULL;
  else
    aux2->prox = NULL; // o nó anterior ao último nó aponta para NULL
  free(aux);
  lista->qtd--;
  return livro;
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
  No *aux = lista->inicio;
  No *aux2 = NULL;
  Livro livro = aux->info;
  for(int i = 0; i < pos; i++)
    aux2 = aux;
    aux = aux->prox;
  if(aux2 == NULL)
    lista->inicio = aux->prox;
  else
    aux2->prox = aux->prox;
  free(aux);
  lista->qtd--;
  return livro;
}

int main(int argc, char const *argv[])
{
    Lista meusLivros;
    meusLivros.inicio = NULL;
    meusLivros.fim = NULL;
    meusLivros.qtd = 0;


    return 0;
}