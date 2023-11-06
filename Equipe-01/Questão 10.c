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

No* criarNo(Livro livro);
int adicionaLivroNoFinal(Lista *lista, Livro livro);
int adicionaLivroNoInicio(Lista *lista, Livro livro);
int adicionarNoMeio(Lista *lista, Livro livro, int pos);
void printLista(Lista *lista);
Livro removerNoInicio(Lista *lista);
Livro removerNoFinal(Lista *lista);
Livro removerNoMeio(Lista *lista, int pos);
void removeEnter (char *str);
void printLivro(Livro info);

int main(int argc, char const *argv[])
{
  int resp = 0, pos;
  Livro aux;
  Lista meusLivros;
  meusLivros.inicio = NULL;
  meusLivros.fim = NULL;
  meusLivros.qtd = 0;

  while(resp!=8){
    printf("\n1 - Mostrar a lista\n2 - Adicionar livro no início\n3 - Adicionar livro ao meio\n4 - Adicionar livro ao final\n5 - Remover livro do início\n6 - Remover livro do meio\n7 - Remover livro do final\n8 - Encerrar o programa\n\nDigite a sua opção: ");
    scanf("%d",&resp);
    fflush(stdin);
    
    if(resp == 1) printLista(&meusLivros);
    else if(resp == 2 || resp == 3 || resp == 4){
      getchar();
      printf("\nDigite o título do livro: ");
      fgets(aux.titulo,50,stdin);
      fflush(stdin);
      removeEnter(aux.titulo);
      printf("Digite o autor(a) do livro: ");
      fgets(aux.autor,50,stdin);
      fflush(stdin);
      removeEnter(aux.autor);
      printf("Digite o ano do livro: ");
      scanf("%d", &aux.ano);
      printf("Digite o número de páginas do livro: ");
      scanf("%d", &aux.paginas);
      printf("Digite o preço do livro: ");
      scanf("%f", &aux.preco);
      if(resp == 3){
        printf("Digite a posição onde deseja adicionar o livro: ");
        scanf(" %d", &pos);
      }
      if(resp == 2) adicionaLivroNoInicio(&meusLivros, aux);
      if(resp == 3) adicionarNoMeio(&meusLivros, aux,pos);
      if(resp == 4) adicionaLivroNoFinal(&meusLivros, aux);
    }
    else if(resp == 5 || resp == 6 || resp == 7){
      if(resp == 5) aux = removerNoInicio(&meusLivros);
      else if(resp == 6) {
        printf("\nDigite a posição onde deseja remover o livro: ");
        scanf(" %d", &pos);
        aux= removerNoMeio(&meusLivros,pos);
      }
      else aux = removerNoFinal(&meusLivros);
      if(aux.titulo[0] == 0) printf("\nErro na remoção. Tente novamente!\n");
      else{
        printf("\nLivro removido: \n");
        printLivro(aux);
      }
    }
    else if(resp >8 || resp < 1) printf("\nEntrada inválida, tente novamente!\n");
    
  }
  
  return 0;
}

/*
    Função: criarNo
    Objetivo: Criar um novo nó para a lista
    Parâmetros: Livro livro - livro a ser inserido no nó
    Retorno: No* - ponteiro para o nó criado
*/
No* criarNo(Livro livro)
{
  No* noh = (No*) malloc(sizeof(No));
  noh->info = livro;
  noh->prox = NULL;
  
  return noh;
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
  No* liv = criarNo(livro);
  if(liv == NULL) return 0;
  
  if(lista->inicio == NULL){
    lista->inicio = lista->fim = liv;
  }
  else {
    lista->fim->prox = liv;
    lista->fim = liv;
  }

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
  No* liv = criarNo(livro);
  if(liv == NULL) return 0;

  if(lista->inicio == NULL){
    lista->inicio = lista->fim = liv;
  }
  else {
    liv->prox = lista->inicio;
    lista->inicio = liv;
  }
  
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
  No* liv = criarNo(livro);
  if(liv == NULL || pos<1){
    free(liv);
    return 0;
  }

  if(lista->inicio == NULL || pos == 1){
    adicionaLivroNoInicio(lista,livro);
  }
  else if(pos > lista->qtd) {
    adicionaLivroNoFinal(lista, livro);
  }
  else{
    No* aux = lista->inicio;
    for(int i = 1; i< pos-1;i++){
      aux = aux->prox;
    }
    liv->prox = aux->prox;
    aux->prox = liv;
  }

  lista->qtd++;
  return 1;
}

void printLista(Lista *lista)
{
  No* aux = lista->inicio;
  if(lista->qtd == 0) printf("\nLista vazia!\n\n");
  for(int i =0; i<lista->qtd; i++){
    printf("\nTítulo: %s\nAutor: %s\nAno: %d\nPáginas: %d\nPreço: %.2f\n\n",aux->info.titulo,aux->info.autor,aux->info.ano,aux->info.paginas,aux->info.preco);
    aux = aux->prox;
  }

  return;
}

/*
    Função: removerNoInicio
    Objetivo: Remover um nó do início da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: Retorna o livro removido
*/
Livro removerNoInicio(Lista *lista)
{
  Livro aux = {0,0,0,0,0};
  No *noh = lista->inicio;
  if(lista->inicio == NULL) return aux;
  else if(lista->qtd == 1){
    lista->inicio= NULL;
    lista->fim = NULL;
  }
  else{
    lista->inicio = lista->inicio->prox;
  }
  
  aux = noh->info;
  free(noh);
  lista->qtd--;
  return aux;
}

/*
    Função: removerNoFinal
    Objetivo: Remover um nó do final da lista
    Parâmetros: Lista *lista - ponteiro para a lista
    Retorno: Retorna o livro removido
*/
Livro removerNoFinal(Lista *lista)
{
  Livro aux = {0,0,0,0,0};
  No *noh = lista->inicio;
  if(lista->inicio == NULL) return aux;
  else if(lista->qtd == 1){
    aux = lista->fim->info;
    free(lista->fim);
    lista->inicio= NULL;
    lista->fim = NULL;
  }
  else{
    for(int i = 1; i< lista->qtd-1;i++){
      noh = noh->prox;
    }
    aux = lista->fim->info;
    free(lista->fim);
    lista->fim = noh;
  }

  lista->qtd--;
  return aux;
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
  Livro aux = {0,0,0,0,0};
  No *noh = lista->inicio, *au;
  
  if(pos<1) return aux;

  if(lista->inicio == NULL || pos == 1){
    return removerNoInicio(lista);
  }
  else if(pos >= lista->qtd) {
    return removerNoFinal(lista);
  }
  else{
    for(int i = 1; i< pos-1;i++){
      noh = noh->prox;
    }
    aux = noh->prox->info;
    au = noh->prox;
    noh->prox = noh->prox->prox;
    free(au);
  }

  lista->qtd--;
  return aux;
}

void removeEnter (char *str){
  str[strlen(str)-1] = '\0';
  return;
}

void printLivro(Livro info)
{
  printf("\nTítulo: %s\nAutor: %s\nAno: %d\nPáginas: %d\nPreço: %.2f\n\n",info.titulo,info.autor,info.ano,info.paginas,info.preco);
  return;
}
