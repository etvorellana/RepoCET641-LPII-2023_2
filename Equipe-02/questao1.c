/* QUESTAO 1 Crie uma função que recebe uma string e um caractere 
(void apagaCaractere(char ch, char str[])), e apague todas
 as ocorrências desse caractere na string. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void apagaCaractere(char ch, char str[]); 

int main(void){

char ch, str[150];

printf("\nDigite a string: ");
fgets(str,150,stdin);
printf("\nDigite o caractere: ");
scanf("%c", &ch);

apagaCaractere(ch, str);

printf("\nPalavra sem o caractere: %s", str);
    return 0;
 }

void apagaCaractere(char ch, char str[]){
int i=0;
if(str[i]=='\0') return; 
else for(;str[i]!='\0';i++) if(str[i]==ch) for(int j=i;str[j]!='\0';j++) str[j]=str[j+1];

return;
}