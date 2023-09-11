#include <stdio.h>
#include <string.h>

int incremento = 1;

int incrementa(int valor);

int main(void)
{
    int cont = 0;
    printf("Exemplo de variável Global: \n");
    printf("Selecione um valor de incremento: ");
    scanf("%d", &incremento);
    printf("No escopo da função main: incremento = %d\n", incremento);
    for(int i = 0; i < 3; i++)
    {   
        printf("No escopo do bloco for: incremento = %d\n", incremento);
        cont = incrementa(cont);
        printf("cont = %d\n", cont);
    }
    printf("Ainda no escopo da função main: incremento = %d\n", incremento);
    return 0;
}

int incrementa(int valor)
{
    //Imprimindo apenas para exibir a variável global
    incremento = incremento >= 0 ? 1 : -1;
    printf("No escopo da função incrementa: incremento = %d\n", incremento); 
    return valor + incremento;
}






