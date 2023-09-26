

#include "hanoi.h"


int cnt = 0; // Contador de movimentos

int get_n(void);

int main(void)
{
    int n;
    n = get_n();
    mobe(n, 'A', 'B', 'C');
    return 0;
}   

int get_n(void)
{
    int n;
    printf("Torre de Hanoi\n");
    printf("==============\n");
    printf("Temos três torres (A, B e C) e n discos na torre A.\n");
    printf("O objetivo é mover todos os discos da torre A para a torre C.\n");
    printf("Regras:\n");
    printf("1. Só é possível mover um disco por vez.\n");
    printf("2. Um disco maior não pode ficar em cima de um disco menor.\n");
    printf("3. Só é possível mover o disco do topo de uma torre.\n");
    printf("Digite o número de discos: ");
    do{
        scanf("%d", &n);
        if(n < 1)
            printf("Digite um número maior ou igual a 1: ");    
    }while(n < 1);
    return n;
}

void move(int n, char origem, char auxiliar, char destino)
{
    if(n == 1){
        cnt++;
        printf("Move disco %d  %d\n", cnt);
    }
        printf("Move o disco 1 de %c para %c\n", origem, destino);
    else
    {
        move(n - 1, origem, destino, auxiliar);
        printf("Move o disco %d de %c para %c\n", n, origem, destino);
        move(n - 1, auxiliar, origem, destino);
    }
}