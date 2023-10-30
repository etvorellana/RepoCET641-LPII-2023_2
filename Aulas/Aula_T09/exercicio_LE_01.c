#include <stdio.h>
#include <stdlib.h>

struct intList {
    int val;
    struct intList *prox;
};

typedef struct intList IList;

IList* geraLista(int vet[], int n);
IList* geraListaR(int vet[], int n);
void printLista(IList* lista);
void printArray(int x[], int n);
void printListaR(IList* lista);
void freeList(IList* lista);
void freeListR(IList* lista);
IList* adicionaNoFinal(IList* lista, int val);
IList* removeDoFinal(IList* lista, int* val);
IList* adicionaNoInicio(IList* lista, int val);
IList* removeDoInicio(IList* lista, int* val);

int main(int argc, char const *argv[])
{
    int x[10];
    for(int i = 0; i < 10; i++)
        x[i] = rand()%50;
    printArray(x, 10);
    IList *lista = NULL;
    lista = geraLista(x, 10);
    //lista = geraListaR(x, 10);
    printLista(lista);
    //printListaR(lista);
    int val = 0;
    lista = removeDoFinal(lista, &val);
    printf("Valor removido: %d\n", val);

    IList *outraLista = NULL;
    printLista(outraLista);
    outraLista = adicionaNoFinal(outraLista, 12345);
    printLista(outraLista);
    outraLista = removeDoFinal(outraLista, &val);
    printLista(outraLista);
    printf("Valor removido: %d\n", val);


    freeList(lista);
    freeList(outraLista);

    //freeListR(lista);
    return 0;
}

IList* geraLista(int vet[], int n)
{
    IList *lista = NULL;
    IList *aux = NULL;
    aux = (IList*) malloc(sizeof(IList));
    aux->val = vet[0];
    aux->prox = NULL;
    lista = aux;
    for(int i = 1; i < n; i++)
    {
        aux->prox = (IList*) malloc(sizeof(IList));
        aux = aux->prox;
        aux->val = vet[i];
        aux->prox = NULL;
    }
    return lista;
}

IList* geraListaR(int vet[], int n)
{
    if(n == 0)
        return NULL;
    else
    {
        IList *lista = NULL;
        lista = (IList*) malloc(sizeof(IList));
        lista->val = vet[0];
        lista->prox = geraListaR(vet+1, n-1);
        return lista;
    }
}

void printListaR(IList* lista)
{
    if(lista == NULL)
        printf("NULL\n");
    else
    {
        printf("%d -> ", lista->val);
        printListaR(lista->prox);
    }
}

void printArray(int x[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

void printLista(IList* aux)
{
    //IList *aux = lista;
    while(aux != NULL)
    {
        printf("%d -> ", aux->val);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void freeList(IList* lista)
{
    IList *aux = lista;
    while(aux != NULL)
    {
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}

void freeListR(IList* lista)
{
    if(lista != NULL)
    {
        freeListR(lista->prox);
        free(lista);
    }
}

IList* adicionaNoFinal(IList* lista, int val)
{
    IList *aux = lista;
    IList *novo = (IList*) malloc(sizeof(IList));
    novo->val = val;
    novo->prox = NULL;
    if (lista == NULL)
        return novo;
    else
    {
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        return lista;
    }
}

IList* adicionaNoFinalR(IList* lista, int val)
{
    if(lista == NULL)
    {
        IList *novo = (IList*) malloc(sizeof(IList));
        novo->val = val;
        novo->prox = NULL;
        return novo;
    }
    else
    {
        lista->prox = adicionaNoFinalR(lista->prox, val);
        return lista;
    }
}

IList* removeDoFinal(IList* lista, int* val)
{
    IList *aux = lista;
    if(lista == NULL)
        return NULL;
    else if(lista->prox == NULL)
    {
        *val = lista->val;
        free(lista);
        return NULL;
    }
    else
    {
        while(aux->prox->prox != NULL)
            aux = aux->prox;
        *val = aux->prox->val;
        free(aux->prox);
        aux->prox = NULL;
        return lista;
    }
}

IList* removeDoFinalR(IList* lista, int* val)
{
    if(lista == NULL)
        return NULL;
    else if(lista->prox == NULL)
    {
        *val = lista->val;
        free(lista);
        return NULL;
    }
    else
    {
        lista->prox = removeDoFinalR(lista->prox, val);
        return lista;
    }   
}

IList* adicionaNoInicio(IList* lista, int val)
{
    IList* aux = (IList*) malloc(sizeof(IList));
    aux->val = val;
    aux->prox = lista;
    return aux;
}


IList* removeDoInicio(IList* lista, int* val)
{
    IList* aux = lista;
    if(lista == NULL)
        return NULL;
    else
    {
        *val = lista->val;
        lista = lista->prox;
        free(aux);
        return lista;
    }
}