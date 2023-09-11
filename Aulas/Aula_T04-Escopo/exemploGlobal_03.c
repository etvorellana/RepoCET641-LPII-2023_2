#include <stdio.h>
#include <string.h>

int incremento = 1;

int incrementa(int valor);

int main(void)
{
    int cont = 0;
    printf("Exemplo de sobreposição de variáveis Locais e Global: \n");
    printf("No escopo da função main: incremento = %d\n", incremento);
    int incremento;
    printf("Selecione um valor de incremento: ");
    scanf("%d", &incremento);
    printf("No escopo da função main: incremento = %d\n", incremento);
    for(int i = 0; i < 3; i++)
    {   
        int incremento = 2;
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
    printf("No escopo da função incrementa: incremento = %d\n", incremento); 
    return valor + incremento;
}






