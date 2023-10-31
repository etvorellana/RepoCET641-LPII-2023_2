// Questão 9. Implemente uma função recursiva que, dados dois números inteiros x e n, calcula o valor de xn.
#include <stdio.h>

int potencia(int x, int n);

int main() {
    int x; // Base
    int n; // Expoente

    printf("Digite um numero (Base): ");
    scanf("%d", &x);
    printf("Digite um numero (Expoente): ");
    scanf("%d", &n);
    
    int resultado = potencia(x, n);

    printf("%d elevado a %d e igual a: %d\n", x, n, resultado);

    return 0;
}

int potencia(int x, int n) {
    // Caso base: se n é igual a 0, o resultado é 1 (qualquer número elevado a 0 é 1)
    if (n == 0) {
        return 1;
    }

    // Aqui, chamamos a função recursivamente com n-1 e multiplicamos o resultado por x
    return x * potencia(x, n - 1);
}


