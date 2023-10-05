#include <stdio.h>

// Função recursiva para calcular o MDC
int calcularMDC(int x, int y) {
    if (y == x) 
        return x;
    else {
        if(x > y)
        x -= y; 
        return calcularMDC(y, x);
    }
}

int main() {
    int x, y;
    
    // Solicita que insira os dois valores inteiros
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &x);
    
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &y);
    
    // Chamada da função para calcular o MDC
    int mdc = calcularMDC(x, y);
    
    // Imprime o resultado
    printf("O MDC de %d e %d e: %d\n", x, y, mdc);
    
    return 0;
}