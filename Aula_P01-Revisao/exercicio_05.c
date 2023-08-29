/*
    Textos podem conter mensagens ocultas. Neste problema a mensagem oculta em| 
    um texto é composta pelas primeiras letras de cada palavra do texto, na   |
    ordem em que aparecem. Para este exercício será fornecido um texto        |
    composto apenas por letras minúsculas ou espaços. Pode haver mais de um   |
    espaço entre as palavras. O texto pode iniciar ou terminar em espaços, ou |
    mesmo conter somente espaços. Para cada caso de teste imprima a mensagem  |
    oculta no texto de entrada.                                               |
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100], msg[100];
    printf("Digite uma string    : ");
    fgets(string, 100, stdin);
    int N = strlen(string) - 1;
    int i = 0, j = 0;
    char aux;
    string[N] = '\0';
    if (string[i] != ' ')
    {
        aux = msg[j++] = string[i++];
    }else{
        aux = string[i++];
    }
    for(;string[i] != '\0';)
    {
        if (string[i] != ' ' && aux == ' ')
        {
            aux = msg[j++] = string[i++];
        }else{
            aux = string[i++];
        }
    }
    msg[j] = '\0';
    printf("Mensagem oculta      : %s\n", msg);
    return 0;
}    

// testar com:Boa oportunidade mantendo duvidas importantes ativas
// tem que retornar Bomdia
