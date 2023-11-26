#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
    Queremos guardar uma lista de valores de temperatura
    de um conjunto de estações meteorológicas.
*/
struct tempList
{
    char *estID; // Identificador da estação
    double val;  // valor de temperatura
    struct tempList *prox;
};

typedef struct tempList TList;

TList *adicionaTemp(TList *lista, TList reg);
list2array(TList* lista, char** estID, double** temp, int qTemp[]);

int main(int argc, char const *argv[])
{
    /*
        Obtemos os dados de alguma fonte
        - Identificador da estação
        - Temperatura
        e guardamos numa lista encadeada
    */
    TList dataTemp, *listaTemp = NULL;

    char ch;
    do
    {
        printf("Digite o identificador da estação: ");
        scanf("%s", dataTemp.estID);
        printf("Digite o valor da temperatura: ");
        scanf("%lf", &dataTemp.val);
        listaTemp = adicionaTemp(listaTemp, dataTemp);
        printf("Deseja continuar? (s/n): ");
        ch = getchar();
        ch = tolower(ch);
    } while (ch != 'n');

    /*
        Agora queremos agrupar os dados de cada estação num
        array. Suponha que vamos guardar no máximo 100 valores
        de cada estação e que teresmos, no máximo, 100 estações.
    */

    char **estID = (char **)malloc(100 * sizeof(char *));
    double **temp = (double **)malloc(100 * sizeof(double *));
    int qTemp[100] = {0}; // Quantidade de temperaturas de cada estação

    /*
        Como podemos fazer isso?
        - Percorremos a lista de temperaturas
        - Para cada elemento da lista, verificamos se o
          identificador da estação já está no array estID
        - Se não estiver, adicionamos o identificador no array
          e criamos um array para guardar os valores de temperatura
          daquela estação
        - Se já estiver, adicionamos o valor de temperatura no array
          correspondente
    */
    list2array(listaTemp, estID, temp, qTemp);
    /*
        Agora queremos guardar os dados de cada estação num arquivo
        separado. O nome do arquivo será o identificador da estação
    */
}

TList *adicionaTemp(TList *lista, TList reg)
{
    TList *aux = lista;
    TList *novo = (TList *)malloc(sizeof(TList));
    novo->estID = reg.estID;
    novo->val = reg.val;
    novo->prox = NULL;
    if (lista == NULL)
        lista = novo;
    else
    {
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}

list2array(TList* lista, char** estID, double** temp, int qTemp[]){
    TList *aux = lista;
    int i = 0;
    while(aux != NULL){
        int j = 0;
        while(j < i && strcmp(estID[j], aux->estID) != 0)
            j++;
        if(j == i){
            estID[i] = aux->estID;
            temp[i] = (double*) malloc(100 * sizeof(double));
            qTemp[i] = 0;
            i++;
        }
        temp[j][qTemp[j]] = aux->val;
        qTemp[j]++;
        aux = aux->prox;
    }
}

