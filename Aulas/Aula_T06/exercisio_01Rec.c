#include <stdio.h>

int quantasVezes(char ch, char str[])
{
    int qVezes = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ch)
            qVezes++;
        i++;
    }
    return qVezes;
}

int quantasVezesR(char ch, char str[])
{
    if(str[0] == '\0')
        return 0;
    else
        return (str[0] == ch) + quantasVezesR(ch, str + 1);
}

int quantosNumeroPares(int array[], int n)
{
    int qPares = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i] % 2 == 0)
            qPares++;
    }
    return qPares;
}

int quantosNumeroParesR(int array[], int n)
{
    if(n == 0)
        return 0;
    else
        return (array[n - 1] % 2 == 0) + quantosNumeroParesR(array, n - 1);
}


int main(void)
{   

    char str[] = "abacate";
    printf("Quantas vezes o caractere 'a' aparece na string '%s'?\n", str);
    printf("Iterativo: %d\n", quantasVezes('a', str));
    printf("Recursivo: %d\n", quantasVezesR('a', str));

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("Quantos números pares tem no array {1, 2, 3, 4, 5, 6, 7, 8}?\n");
    printf("Iterativo: %d\n", quantosNumeroPares(array, 8));
    printf("Recursivo: %d\n", quantosNumeroParesR(array, 8));
    
    return 0;
}