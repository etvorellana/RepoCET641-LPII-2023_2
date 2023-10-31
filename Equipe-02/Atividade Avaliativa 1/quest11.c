#include <stdio.h>

void imprimirInverso() {
    int num;
    scanf("%d", &num);
    
    if (num != 0) {
        imprimirInverso(); // Chama a função recursivamente até que 0 seja inserido.
        printf("%d ", num); // Imprime o número após a chamada recursiva.
    }
}

int main() {
    printf("Digite uma sequencia de numeros inteiros (0 para terminar): ");
    imprimirInverso();
    printf("\n");
    
    return 0;
}