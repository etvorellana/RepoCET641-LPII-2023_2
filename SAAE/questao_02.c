#include <stdio.h>
#include <stdlib.h>
 
struct notas{
    int pont;
    struct notas* prox;
};

typedef struct notas Notas;

int contNotasV1(Notas* lista, int* max, int* min)
{   
    int cont = 0;
    if (lista != NULL)
    {
        *max = *min = lista->pont;
        cont = 1;
        Notas* aux = lista->prox;
        while(aux != NULL)
        {
            if(*min > aux->pont)
                *min = aux->pont;
            else if(*max < aux->pont)
                *max = aux->pont;
            aux = aux->prox;
            cont++;
        }
    }
    return cont;
}

int contNotasV2(Notas* lista, int* max, int* min)
{
    if (lista == NULL)
        return 0;
    if (lista->prox == NULL)
    {
        *max = *min = lista->pont;
        return 1;
    }
    int cont = contNotasV2(lista->prox, max, min);
    if(*min > lista->pont)
        *min = lista->pont;
    else if(*max < lista->pont)
        *max = lista->pont;
    return cont + 1;
}

Notas* array2list_V1(int notas[], int tam)
{
    Notas* lista = NULL;
    for(int i = 0; i < tam; i++)
    {
        Notas* novo = (Notas*)malloc(sizeof(Notas));
        novo->pont = notas[i];
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}

Notas* array2list_V2(int notas[], int tam)
{
    Notas* lista = NULL;
    if (tam != 0)
    {
        lista = (Notas*)malloc(sizeof(Notas));
        lista->pont = notas[0];
        lista->prox = array2list_V2(notas + 1, tam - 1);
    }
    return lista;
}

Notas* array2list(int notas[], int tam);
int contNotas(Notas* lista, int* max, int* min);

int main(int argc, char const *argv[])
{
    int pontuacao[300];
    //Apenas para testar
    for(int i = 0; i < 300; i++)
        pontuacao[i] = 45 + rand() % 150;
    int tam = 300;
    Notas* lista = array2list(pontuacao, tam);
    int max, min;
    int cont = contNotas(lista, &max, &min);
    return 0;
}


