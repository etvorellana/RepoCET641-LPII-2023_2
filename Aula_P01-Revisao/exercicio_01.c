/*
    Leia um valor inteiro, que representa o tempo de duração em segundos de um|
    determinado evento, e retorne expresso no formato horas:minutos:segundos. |
*/

#include <stdio.h>

int main(void)
{
    int tempo, horas, minutos, segundos;

    printf("Digite um valor inteiro que represente um período de tempo em segundos: ");
    scanf("%d", &tempo);

    horas = tempo / 3600;
    minutos = (tempo % 3600) / 60;
    segundos = (tempo % 3600) % 60;

    printf("%d:%d:%d\n", horas, minutos, segundos);

    return 0;
}