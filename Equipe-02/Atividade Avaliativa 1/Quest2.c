/*Crie uma fun��o que recebe uma string e dois caracteres (void trocaCaracteres(char ch1, char ch2, char str[])),
e substitua todas as ocorr�ncias na string do caractere ch1 pelo caractere ch2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void trocaCaracteres(char ch1, char ch2, char str[]);
void ajustaString(char str[]);

int main ()
{
    char ch1, ch2, str[10];
    printf("Digite uma string\n");
    fgets(str, 10, stdin);
    ajustaString(str);      //Retira o \n do FGETS e deixa todos os caracteres mai�sculos


    printf("Digite o primeiro caractere\n");
    scanf(" %c", &ch1);
    ch1=toupper(ch1);

    printf("Digite o segundo caractere\n");
    scanf(" %c", &ch2);
    ch2=toupper(ch2);

    system("cls||clear");
    printf("%s\n%c\n%c\n", str, ch1, ch2);  //String antes de modifica��o e os caracteres que ser�o alterados
    trocaCaracteres(ch1, ch2, str);
    printf("%s", str);        //Nova string
    return 0;
}

void ajustaString(char str[])
{
    int N = strlen(str)-1;
    if (str[N]=='\n')
        str[N]='\0';
    for (int i=0; i<10; i++)
         str[i]=toupper(str[i]);
}
void trocaCaracteres(char ch1, char ch2, char str[])
{
    for (int i=0; i<10; i++)
        str[i]==ch1 ? str[i]=ch2 : str[i];

    return;
}
