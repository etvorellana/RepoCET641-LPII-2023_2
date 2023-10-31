#include <stdio.h>
#include <stdlib.h>

int somaAlgarismos(int num);

int main() {
    int num;
    printf("Digite um numero:\n");
    scanf("%d", &num);

    num = abs(num); //Caso o usuario digite um numero negativo

    int somaAlg = somaAlgarismos(num);
    printf("Soma dos algarismos de %d: %d\n", num, somaAlg);

    return 0;
}

int somaAlgarismos(int num) {
    int soma = 0;
    if (num < 10)
        return num;  // Caso base: retorna o pr�prio n�mero

    soma += num % 10; // Adiciona o �ltimo d�gito � soma
    return soma + somaAlgarismos(num / 10); // Chama a fun��o recursivamente com o n�mero sem o �ltimo d�gito
}
