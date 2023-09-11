#include <stdio.h>

#include "headers_Aula03.h"

int main(void)
{
    int tempo; // variável local

    // entrada de dados
    printf("Digite um valor inteiro que represente um período de tempo em segundos: ");
    scanf("%d", &tempo);

    seg2hms(65432); // chamada da função
    tempo = 65432;

    // saída de dados
    printf("%d segundos correspondem a %dh:%dm:%ds\n", tempo, horas, minutos, segundos);

    return 0;
}

void seg2hms(int tempo)
{
    horas = tempo / 3600;
    minutos = (tempo % 3600) / 60;
    segundos = (tempo % 3600) % 60;
}

int hms2seg(int horas, int minutos, int segundos)
{
    return horas * 3600 + minutos * 60 + segundos;
}

