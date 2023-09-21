#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 100

void preencher(int lista[], int n);
int busca(int lista[], int n, int elemento);

int main(void)
{
    srand(time(NULL));
    printf("Procurando um elemento numa lista...\n");
    int lista[N];
    preencher(lista, N);
    int elemento = rand() % 5 * N; // 0 a 499
    printf("Elemento a ser procurado: %d\n", elemento);
    int posicao = busca(lista, N, elemento);
    if (posicao == -1)
        printf("Elemento nao encontrado\n");
    else
        printf("Elemento encontrado na posicao %d\n", posicao);
    return 0;
}

void preencher(int lista[], int n)
{
    if (n == 0)
        return;
    lista[n - 1] = rand() % 500;
    preencher(lista, n - 1);
}

void preencherOrdenado(int lista[], int n, int elemento)
{
    if (n == 0)
        return;
    int caraCoroa = rand() % 2;
    if (caraCoroa)
    {
        lista[0] = elemento++;
        preencherOrdenado(&lista[1], n - 1, elemento);
    }else
        preencherOrdenado(lista, n, ++elemento);
}

int busca(int lista[], int n, int elemento)
{
    if (n == 0)
        return n - 1;
    if (lista[n - 1] == elemento)
        return n - 1;
    return busca(lista, n - 1, elemento);
}

int buscabinaria(int lista[], int n, int elemento)
{
    if (n == 0)
        return -1;
    int meio = n / 2;
    if (lista[meio] == elemento)
        return meio;
    if (lista[meio] > elemento)
        return buscabinaria(lista, meio, elemento);
    return meio + 1 + buscabinaria(&lista[meio + 1], meio, elemento);  
}
