#include <stdio.h>

int ordenaA(int a, int b);
//void ordenaB(int a, int b);  
//void ordenaC(int *a, int *b);
int ordenaD(int *a, int *b);



int main(void)
{
    int a = 5, b = 3;
    printf("Testando a função ordenaA\n");
    printf("Testando na função main.\nAntes de ordenar: ");
    printf("a = %d, b = %d\n", a, b);
    if (ordenaA(a, b))
        printf("Foi necessário ordenar\n");
    printf("Testando na função main.\nApós ordenar: ");
    printf("a = %d, b = %d\n", a, b);
    printf("Testando a função ordenaD\n");
    printf("Testando na função main.\nAntes de ordenar: ");
    printf("a = %d, b = %d\n", a, b);
    if (ordenaD(&a, &b))
        printf("Foi necessário ordenar\n");
    printf("Testando na função main.\nApós ordenar: ");
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

int ordenaA(int a, int b){
    int aux, ordenou = 0;
    //Para debugar o códig. Comente o printf após testar
    printf("Testando na função orenaA.\nAntes de ordenar: ");
    printf("a = %d, b = %d\n", a, b);
    if (a > b){
        ordenou = 1;
        aux = a;
        a = b;
        b = aux;
    }
    //Para debugar o códig. Comente o printf após testar
    printf("Testando na função orenaA.\nApós ordenar: ");
    printf("a = %d, b = %d\n", a, b);
    return ordenou; // Retorna se foi necessário ordenar ou não   
}

int ordenaD(int *a, int *b)
{
    int aux, ordenou = 0;
    //Para debugar o códig. Comente o printf após testar
    printf("Testando na função orenaD.\nAntes de ordenar: ");
    printf("a = %d, b = %d\n", *a, *b);
    if (*a > *b){
        ordenou = 1;
        aux = *a;
        *a = *b;
        *b = aux;
    }
    //Para debugar o códig. Comente o printf após testar
    printf("Testando na função orenaB.\nApós ordenar: ");
    printf("a = %d, b = %d\n", *a, *b);
    return ordenou; // Retorna se foi necessário ordenar ou não  
}

int ordenaA_(int a, int b)
{
    int aux, ordenou = 0;
    if (a > b){
        ordenou = 1;
        aux = a;
        a = b;
        b = aux;
    }
    return ordenou; // Retorna se foi necessário ordenar ou não   
}

int ordenaD_(int *a, int *b)
{
    int aux, ordenou = 0;
    if (*a > *b){
        ordenou = 1;
        aux = *a;
        *a = *b;
        *b = aux;
    }
    return ordenou; // Retorna se foi necessário ordenar ou não  
}

