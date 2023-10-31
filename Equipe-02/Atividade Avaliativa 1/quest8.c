#include <stdio.h>
#include <stdlib.h>

int calcular_resto(int x, int y) {
    // se |x| < |y|, o resto é x
    if (abs(x) < abs(y)) {
        return abs(x);
    }

    // se |x| = |y|, o resto é 0
    if (abs(x) == abs(y)) {
        return 0;
    }

    // calcula o resto com a definição fornecida
    return calcular_resto(abs(x) - abs(y), abs(y));
}

int main() {
    int x, y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    int resto = calcular_resto(x, y);

    printf("O resto da divisao de %d por %d e %d\n", x, y, resto);

    return 0;
}