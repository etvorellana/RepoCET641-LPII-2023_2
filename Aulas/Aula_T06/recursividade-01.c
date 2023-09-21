#include <stdio.h>

int soma(int n)
{
    if (n == 1)
        return 1;
    return n + soma(n - 1);
}

unsigned long int fatorial(int n)
{
    if (n == 0)
        return 1;
    return n * fatorial(n - 1);
} 

void escreve(void)
{
    char c;
    if ((c = getchar()) != '\n')
        escreve();
    putchar(c);
}

int fibonacci(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("A soma dos numeros de 1 a %d eh %d\n", n, soma(n));
    printf("O fatorial de %d eh %lu\n", n, fatorial(n));
    fflush(stdin);
    printf("Digite uma frase: ");
    escreve();
    return 0;
}

