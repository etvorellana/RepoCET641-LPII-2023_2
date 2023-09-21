#include <stdio.h>

#include "headers_Aula04.h"

int main(void)
{
    int tempo; // variável local
    int horas, minutos, segundos;

    // entrada de dados
    printf("Digite um valor inteiro que represente um período de tempo em segundos: ");
    scanf("%d", &tempo);

    //seg2hms(65432); // chamada da função
    //tempo = 65432;
    seg2hms__(tempo, &horas, &minutos, &segundos); // chamada da função

    // saída de dados
    printf("%d segundos correspondem a %dh:%dm:%ds\n", tempo, horas, minutos, segundos);
    int a = 8, b = 10;
    troca(&a, &b);
    return 0;
}

void seg2hms__(int tempo, int *horas, int *minutos, int *segundos)
{
    *horas = tempo / 3600;
    *minutos = (tempo % 3600) / 60;
    *segundos = (tempo % 3600) % 60;
    return;
}

void testestruct(Horario *h){
    printf("h.horas = %d\n", h->horas);
    printf("h.minutos = %d\n", h->minutos);
    printf("h.segundos = %d\n", h->segundos);
    return;
}

int hms2seg(int horas, int minutos, int segundos)
{
    return horas * 3600 + minutos * 60 + segundos;
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
    return;
}
