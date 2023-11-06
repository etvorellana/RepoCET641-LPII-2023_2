#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct intlist{
    int val;
    struct intlist* prox;
} lista;


// Gera uma lista com base em um vetor
lista* geralista(int vet[], int n){
    lista *aux = (lista*) malloc(sizeof(lista));
    aux->val = vet[0];
    aux->prox = NULL;
    lista *first = aux;
    
    for (int c = 1; c < n; c++){
        aux->prox = (lista*) malloc(sizeof(lista));
        aux = aux->prox;
        aux->val = vet[c];
        aux->prox = NULL;
    }

    return first;

}

//Mostra na tela a lista encadeada
void printlista(lista* encad){

    while (encad != NULL){
        printf("%d -> ", encad->val);
        encad = encad->prox;
    }
    printf("\n");
}

 
// Adiciona um elemento no final da lista
lista *adicionanofinal(lista* encad, int x){
    lista *new = (lista*) malloc(sizeof(lista)), *aux = encad;
    new->val = x;
    new->prox = NULL;
    
    if (encad != NULL){
        while (encad->prox != NULL){
            encad = encad->prox;
        }
        encad->prox = new;
        return aux;
    }

    return new;
}

//Remove um elemento da lista no final
lista *removenofinal(lista* encad, int *x){
    lista *aux;

    if (encad == NULL){
        return NULL;
    } else if(encad->prox == NULL){
        *x = encad->val;
        free(encad);
        return NULL;
    }

    while(encad->prox != NULL){
        aux = encad;
        encad = encad->prox;
    }
    
    aux->prox = NULL;
    *x = encad->val;
    free(encad);

    return encad;
}

//Adiciona um novo elemento na lista considerando a posição 0 como a primeira
lista *addbyindex(lista* encad, int val, int pos){
    lista *new = (lista*) malloc(sizeof(lista));
    new->val = val;

    if (encad == NULL){
        new->prox = NULL;
        return new;
    }else if (encad->prox != NULL && pos != 0){

        int c = 0;
        lista *aux = NULL, *var = encad;

        while ((c < pos) && (var != NULL)){
            aux = var;
            var = var->prox;
            c++;
        }
        new->prox = var;
        aux->prox = new;
        return encad;
    } else{
        new->prox = encad;
        return new;
    }
}

//Remove um elemento na lista considerando a posição 0 como a primeira
lista *rmbyindex(lista* encad, int *val, int pos){
    if (encad == NULL){
        return NULL;
    }else if (encad->prox == NULL){
        *val = encad->val;
        free(encad);
        return NULL;
    }else if(pos != 0){
        int c = 0;
        lista *aux = NULL, *var = encad;

        while ((c < pos) && (var->prox != NULL)){
            aux = var;
            var = var->prox;
            c++;
        }
        aux->prox = var->prox;
        free(var);
        return encad;
    } else{
        lista *aux = encad->prox;
        free(encad);
        return aux;
    }
}


int main(void){
    int x[10];
    srand(time(NULL));

    printf("Array:\n");
    for(int i = 0; i < 10; i++){
        x[i] = rand() % 50;
        printf("%d -> ", x[i]);
    }
    printf("\n\n");

    lista *preenchido = NULL;
    lista *new = NULL;

    preenchido = geralista(x, 10);
    printf("Primeira lista:\n");
    printlista(preenchido);

    addbyindex(preenchido,10,30);
    printlista(preenchido);

    int *val = (int*) malloc(sizeof(int));
    
    new = adicionanofinal(new, 23);
    printf("\nSegunda lista:\n");
    printlista(new);

    //new = removenofinal(new, val);
    //printf("\nValor removido: %d\n", *val);

    new = addbyindex(new, 10, 0);
    new = addbyindex(new, 12, 1);
    printlista(new);
    new = rmbyindex(new,val,1);
    printlista(new);

}