#include <stdio.h>
#include <stdlib.h>
int pot(int x, int n);


int main() {
    int x, n;
    
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    int resultado = pot(x, n);
    
    printf("%d elevado a %d é igual a %d\n", x, n, resultado);
    
    return 0;
}

int pot(int x, int n) {
  
    if (n == 0) {
        return 1;
    }
    
    return x * pot(x, n - 1);
}