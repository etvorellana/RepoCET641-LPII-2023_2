#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

Livro criarLivro()
{
  fflush(stdin);
  Livro temp;
  printf("\n\nDigite o titulo: ");
  fgets(temp.titulo, 50, stdin);
  temp.titulo[strlen(temp.titulo) - 1] = '\0';
  printf("Digite o autor: ");
  fgets(temp.autor, 50, stdin);
  temp.autor[strlen(temp.autor) - 1] = '\0';
  printf("Digite o ano: ");
  scanf("%d", &temp.ano);
  printf("Digite a quantidade de páginas: ");
  scanf("%d", &temp.paginas);
  printf("Digite o preço: ");
  scanf("%f", &temp.preco);
  getchar();
  printf("\n\n");
  return temp;
}

No* criarNo(Livro livro)
{
  No* temp;
  temp = (No*) malloc(sizeof(No));
  temp->info = livro;
  temp->prox = NULL;
  return temp;
}

int adicionaLivroNoFinal(Lista *lista, Livro livro)
{
  No* aux;
  aux = criarNo(livro);
  if(aux == NULL)
    return 0;
  if(lista->qtd == 0){
    lista->inicio = aux;
    lista->fim = aux;
  }
  else if (lista->qtd == 1){
    lista->inicio->prox = aux;
    lista->fim = aux;
  }
  else {
    lista->fim->prox = aux;
    lista->fim = aux;
  }
  if (lista->fim == aux)
    lista->qtd++;
  return (lista->fim == aux);
}


int adicionaLivroNoInicio(Lista *lista, Livro livro)
{
  if(lista->qtd == 0)
     return adicionaLivroNoFinal(lista, livro);
  No* aux;
  aux = criarNo(livro);
  if(aux == NULL)
    return 0;
  aux->prox = lista->inicio;
  lista->inicio = aux;
  if(lista->inicio == aux)
    lista->qtd++;
  return (lista->inicio == aux);
}


int adicionarNoMeio(Lista *lista, Livro livro, int pos)
{
  No* aux;
  aux = criarNo(livro);
  if(aux == NULL || pos < 1)
    return 0;
  No *ant;
  ant = lista->inicio;
  if (lista->qtd < pos)
    return  adicionaLivroNoFinal(lista, livro);
  else {
    for(int i = 1; i < (pos - 1); i++)
      ant = ant->prox;
    aux->prox = ant->prox;
    ant->prox = aux;
  }
  if(ant->prox == aux)
    lista->qtd++;
  return (ant->prox == aux);
}

void printLivro(Livro livro)
{
  printf("Nome: %s\n", livro.titulo);
  printf("Autor: %s\n", livro.autor);
  printf("Ano: %d\n", livro.ano);
  printf("Páginas: %d\n", livro.paginas);
  printf("Preço: %.2f\n\n", livro.preco);
}

void printLista(Lista lista)
{
  int i = 1;
  for(No* aux = lista.inicio; aux != NULL; aux = aux->prox, i++){
    printf("\nLivro %d/%d\n",i, lista.qtd);
    printLivro(aux->info);
  }
  printf("\n---Fim da lista---\nQuantidade de livros: %d\n\n",lista.qtd);
}

Livro removerNoInicio(Lista *lista)
{
  Livro removido = {0,0,0,0,0};
  No* ffree;
  if (lista->qtd == 0)
    return removido;
  
  if (lista->qtd == 1){
    removido = lista->inicio->info;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd--;
    return removido;
  }
  removido = lista->inicio->info;
  ffree = lista->inicio;
  lista->inicio = lista->inicio->prox;
  lista->qtd--;
  free(ffree);
  return removido;
}

Livro removerNoFinal(Lista *lista)
{
  Livro removido;
  No* ffree;
  if(lista->qtd < 2){
    return removerNoInicio(lista);
  }
  removido = lista->fim->info;
  ffree = lista->fim;
  No* ant;
  for(ant = lista->inicio; ant->prox->prox != NULL; ant = ant->prox);
  ant->prox = NULL;
  lista->fim = ant;
  lista->qtd--;
  free(ffree);
  return removido;
}

Livro removerNoMeio(Lista *lista, int pos)
{
  Livro removido = {0,0,0,0,0};
  No *ant, *aux;
  ant = lista->inicio;
  if(lista->qtd < pos)
    return removido;
    
  else if(pos == 1)
    return removerNoInicio(lista);
  for(int i = 1; i < (pos - 1) && ant != NULL; i++, ant = ant->prox);
  removido = ant->prox->info;
  aux = ant->prox;
  ant->prox = ant->prox->prox;
  lista->qtd--;
  free(aux);
  return removido;
}

int main(int argc, char const *argv[])
{
  Lista meusLivros;
  meusLivros.inicio = NULL;
  meusLivros.fim = NULL;
  meusLivros.qtd = 0;

  int index, sindex;
  Livro removido;
  while(1){
    do {
      printf("\n>>> Menu Principal <<<\nDigite uma opção: \n");
      printf("1 - Adicionar;\n2 - Remover;\n3 - Consultar;\n4 - Sair\n-> ");
      scanf("%d", &index);
      getchar();
    } while(index < 1 || index > 4);
    switch(index){
      case 1:
        do {
          printf("\n+++ Menu Adicionar +++\nEscolha uma das opções: \n");
          printf("1 - Adicionar no início;\n2 - Adicionar no meio;\n3 - Adicionar no fim;\n4 - Voltar\n-> ");
          scanf("%d", &sindex);
        } while(sindex < 1 || sindex > 4);
        getchar();
        switch(sindex) {
          case 1:
            if(adicionaLivroNoInicio(&meusLivros, criarLivro()) == 0)
              printf("!!!!!!!!!ERRO AO ADICIONAR!!!!!!!!!\n");
          break;
          case 2:
            printf("\nQual posição?\n-> ");
            int poa;
            scanf("%d", &poa);
            getchar();
            if(poa > meusLivros.qtd + 1) {
              printf("A posição é maior que o indíce atual de livros.\n");
              printf("O Livro será adicionado ao final da lista na posição %d\n", meusLivros.qtd + 1);
              printf("Continuar? S para confirmar\n-> ");
              unsigned char conf;
              scanf("%c", &conf);
              getchar();
              if(conf == 'S' || conf == 's') {
                if(adicionaLivroNoFinal(&meusLivros, criarLivro()) == 0)
                  printf("!!!!!!!!!ERRO AO ADICIONAR!!!!!!!!!\n");
              }
              else
                  printf("Retornando ao menu.\n");
            }
            else if(adicionarNoMeio(&meusLivros, criarLivro(), poa) == 0)
              printf("!!!!!!!!!ERRO AO ADICIONAR!!!!!!!!!\n");
          break;
          case 3:
            if(adicionaLivroNoFinal(&meusLivros, criarLivro()) == 0)
              printf("!!!!!!!!!ERRO AO ADICIONAR!!!!!!!!!\n");
          break;
          default:
          break;
        }
      break;
      case 2:
        if(meusLivros.qtd == 0)
          printf("Não há livros para serem removidos!\n");
        else {
          do {
            printf("\n--- Menu Remoção ---\nEscolha uma das opções: \n");
            printf("1 - Remover no início;\n2 - Remover no meio;\n3 - Remover no fim\n4+ - Voltar\n-> ");
            scanf("%d", &sindex);
          } while(sindex < 1);
          getchar();
          switch(sindex) {
            case 1:
              removido = removerNoInicio(&meusLivros);
              printf("\nLivro Removido: \nLivro 1\n");
              printLivro(removido);
            break;
            case 2:
              printf("\nQual posição?\n-> ");
              int por;
              do {
                scanf("%d", &por);
                getchar();
                if(por < 1)
                  printf("Valor inválido!\nDigite novamente a posição: ");
              } while (por < 1 || por > meusLivros.qtd);
              removido = removerNoMeio(&meusLivros, por);
              printf("\nLivro Removido: \nLivro %d\n",por);
              printLivro(removido);
            break;
            case 3:
              removido = removerNoFinal(&meusLivros);
              printf("Livro Removido: \n");
              printLivro(removido);
            break;
            default:
            break;
          }
        }
      break;
      case 3:
        if(meusLivros.inicio == NULL)
          printf("A lista não possui livros!\n");
        else {
          do {
            printf("\n<><> Menu de Visualização <><>\nEscolha uma das opções: \n");
            printf("1 - Ver lista completa;\n2 - Ver livro inicial;\n3 - Ver livro final\n4 - Ver livro específico\n5 - Voltar\n-> ");
            scanf("%d", &sindex);
          } while(sindex < 1 || sindex > 5);
          getchar();
          switch(sindex) {
            case 1:
              printLista(meusLivros);
            break;
            case 2:
              printLivro(meusLivros.inicio->info);
            break;
            case 3:
              printLivro(meusLivros.fim->info);
            break;
            case 4:
              printf("Qual posição?\n-> ");
              int pov;
              do {
                scanf("%d", &pov);
                getchar();
                if(pov > meusLivros.qtd)
                  printf("A quantidade de livros é menor que a posição\nDigite Novamente: ");
                else if (pov < 1)
                  printf("O indice não existe.\nDigite Novamente: ");
              } while (pov > meusLivros.qtd || pov < 1);
              if(pov == 1)
                printLivro(meusLivros.inicio->info);
              else if (pov == meusLivros.qtd)
                printLivro(meusLivros.fim->info);
              else {
                No* a;
                a = meusLivros.inicio;
                for(int i = 1; i < pov; i++)
                  a = a -> prox;
                printLivro(a->info);
              }
            break;
            default:
            break;
          }
        }
      break;
      default:
        return 0;
      break; 
  }
  }
  return 1;
}