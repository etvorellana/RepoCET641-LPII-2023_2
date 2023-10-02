#include <stdio.h>

/*
O máximo divisor comum (MDC) de dois números inteiros x e y pode ser calculado 
usando-se uma definição recursiva:
MDC(x, y) = MDC(x − y, y), se x > y . 
Além disso, sabe-se que:
MDC(x, y) = MDC( y, x) 
MDC(x, x) = x
Exemplo:
		MDC(10,6) 	= MDC(4,6) 
                    = MDC(6,4) 
                    = MDC(2,4) 
                    = MDC(4,2) 
                    = MDC(2,2) = 2

Crie uma função recursiva para descrever tal definição. 
Crie, também, um algoritmo que leia os dois valores inteiros e utilize a função 
criada para calcular o MDC de x e y, e imprima o valor computado.

*/

int mdccalc(int x, int y){
    printf("%d, %d\n", x, y);
    /*if (x == y){
        return x;
    } else */if (x > y){
        x = mdccalc(x - y, y);
    } else if (x < y){
        x = mdccalc (y, x);
    }
    return x;
}


int main(void){
    int a, b;
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &b);

    printf("\nO mdc desses dois números é: %d\n", mdccalc(a, b));

    return 0;
}
