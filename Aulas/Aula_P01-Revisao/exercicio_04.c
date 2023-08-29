/*
    Matheus estava conversando com a sua noiva via mensagem de texto, quando  |
    ela lhe enviou a seguinte mensagem:                                       |
    1-4-3                                                                     |
    Ele não entendeu a mensagem, então ele perguntou o que isso significava, e| 
    ela respondeu que era 'I Love You" e logo ele percebeu que cada número    |
    separado por um ' - ' é a quantidade de caracteres de cada uma das        |
    palavras que compõem a frase. Com isso, ele teve a ideia de criar um      |
    programa que inserindo determinada frase, ele calcula a quantidade de     |
    caracteres de cada uma das palavras e separar os valores por ' - '.       |
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];
    printf("Digite uma string    : ");
    fgets(string, 100, stdin);
    int N = strlen(string) - 1;
    string[N] = '\0';
    int i = 0, cont = 0;
    while(string[i] != '\0')
    {
        if(string[i] == ' ')
        {
            printf("%d-", cont);
            cont = 0;
        }else{
            cont++;
        }
        i++;
    }
    printf("%d\n", cont);
    return 0;
}