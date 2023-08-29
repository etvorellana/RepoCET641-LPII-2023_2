/*
    A sua impressora foi infectada por um vírus e está imprimindo de forma    |
    incorreta. Depois de olhar para várias páginas impressas por um tempo,    |
    você percebe que ele está imprimindo cada linha de dentro para fora. Em   |
    outras palavras, a metade esquerda de cada linha está sendo impressa a    |
    partir do meio da página até a margem esquerda. Do mesmo modo, a metade   |
    direita de cada linha está sendo impressa a partir da margem direita e    |
    prosseguindo em direção ao centro da página.                              |
    Por exemplo a linha:                                                      |
    THIS LINE IS GIBBERISH                                                    |
    está sendo impressa como:                                                 |
    I ENIL SIHTHSIREBBIG S                                                    |
    Da mesma foma, a linha " MANGOS " está sendo impressa incorretamente como |
    "NAM  SOG". Sua tarefa é desembaralhar (decifrar) a string a partir da    |
    forma como ela foi impressa para a sua forma original. Você pode assumir  |
    que cada linha conterá um número par de caracteres.                       |
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];
    // Primeiro vamos simular o virus
    printf("Digite uma string    : ");
    fgets(string, 100, stdin);
    // Agora vamos embaralhar
    int N = strlen(string) - 1;
    int halfN = N / 2;
    string[N] = '\0';
    for(int i = 0 ; i < halfN / 2 ; i++)
    {
        char aux = string[i];
        string[i] = string[halfN - i - 1];
        string[halfN - i - 1] = aux;
        aux = string[halfN + i];
        string[halfN + i] = string[N - i - 1];
        string[N - i - 1] = aux;
    }
    printf("String embaralhada   : %s\n", string);
    // Agora vamos desembaralhar
    for(int i = 0 ; i < halfN / 2 ; i++)
    {
        char aux = string[i];
        string[i] = string[halfN - i - 1];
        string[halfN - i - 1] = aux;
        aux = string[halfN + i];
        string[halfN + i] = string[N - i - 1];
        string[N - i - 1] = aux;
    }
    printf("String desembaralhada: %s\n", string);
    return 0;
}

// O mesmo algoritmo que serve para embaralhar serve para desembaralhar (;-)
