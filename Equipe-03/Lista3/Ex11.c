#include <stdio.h>

/*
Dado n e uma sequência de n números inteiros, fornecidos pelo usuários, 
imprimir a sequência na ordem inversa a que foi lida, sem usar um array. (spoiler: use recursividade (;-))
*/


void ImprimirInverso(int n) {
    if (n == 0) {
        return;
    } else {
        int num;
        scanf("%d", &num);
        ImprimirInverso(n - 1);
        printf("%d ", num);
    }
}

int main() {
    int n;

    printf("Digite a quantidade de números que deseja inserir: ");
    scanf("%d", &n);

    printf("Digite a sequência de %d números:\n", n);
    ImprimirInverso(n);

    return 0;
}