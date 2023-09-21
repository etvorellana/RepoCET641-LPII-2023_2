#include <stdio.h>

#include "headers_Aula04.h"


int main(void)
{
    int inter_S; // variável local
    Horario inter_HMS; // variável local

    // entrada de dados
    printf("Digite um valor inteiro que represente um período de tempo em segundos: ");
    scanf("%d", &inter_S);

    inter_HMS = seg2hms_(inter_S); // chamada da função

    // saída de dados
    printf("%d segundos correspondem a %dh:%dm:%ds \n", inter_S, inter_HMS.horas, inter_HMS.minutos, inter_HMS.segundos);

    return 0;
}

void seg2hms(int tempo)
{
    horas = tempo / 3600;
    minutos = (tempo % 3600) / 60;
    segundos = (tempo % 3600) % 60;
}


Horario seg2hms_(int tempo)
{
    Horario horario;

    horario.horas = tempo / 3600;
    horario.minutos = (tempo % 3600) / 60;
    horario.segundos = (tempo % 3600) % 60;

    return horario;
}


int hms2seg(int horas, int minutos, int segundos)
{
    return horas * 3600 + minutos * 60 + segundos;
}

int hms2seg_(Horario horario)
{
    return horario.horas * 3600 + horario.minutos * 60 + horario.segundos;
}   

