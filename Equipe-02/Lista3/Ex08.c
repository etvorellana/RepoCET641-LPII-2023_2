#include <stdio.h>
#include <stdlib.h>

/*
Pode-se calcular o resto da divisão, MOD, de x por y, dois números inteiros, 
usando-se a seguinte definição:
MOD(|x|−|y|,|y|), se|x|>|y| 
| x | se | x | < | y |  
0 se | x | = | y |
Então, crie uma função recursiva para descrever tal definição.
Crie também um algoritmo que leia os dois valores inteiros e utilize a função
criada para calcular o resto da divisão de x por y, e imprima o valor computado.

*/

int mod(int x,int y){
    if(abs(x) > abs(y)){
        return mod(abs(x)-abs(y),abs(y));
    }
    else if(abs(x) < abs(y)){
        return x;
    } else{
        return 0;
    }
}


int main(void){
    int x,y;
    printf("\nEntre com o valor de x: ");
    scanf("%d",&x);
    printf("\nEntre com o valor de y: ");
    scanf("%d",&y);

    printf("O valor do resto da divisão é: %d\n", mod(x,y));
    return 0;
}
