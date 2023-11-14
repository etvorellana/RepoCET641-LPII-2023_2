#include <stdio.h>
#include <stdlib.h>

struct notas{
    int pont;
    struct notas* prox;
};

typedef struct notas Notas;

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









