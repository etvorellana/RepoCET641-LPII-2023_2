#include <stdio.h>

/*
Faça um programa (utilizando recursividade) que peça para o usuário digitar um número, 
em seguida, faça a soma de todos os algarismos do número.
*/

int somaalg(int num){
    if((num / 10) == 0){
        return num;
    }
    return somaalg(num / 10)  + num % 10;
}


int main(void){
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("\nA soma dos algarismos desse número é: %d\n", somaalg(num));    
    return 0;
}
