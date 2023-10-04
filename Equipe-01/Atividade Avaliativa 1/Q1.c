#include <stdio.h>
#include <ctype.h>

void apagaCaractere(char ch, char str[]);

int main(void){
    char string1[100], ch;

    printf("Escreva a string: ");
    fgets(string1, 100, stdin);

    printf("Escreva o caractere que será removido: ");
    scanf("%c",&ch);

    apagaCaractere(ch, string1);

    printf("%s", string1);

    return 0;
}

void apagaCaractere(char ch, char str[]){
  int i, j = 0;

  for(i = 0; str[i] != '\0'; i++){ // "i" percorre a string 
    if(str[i] != ch){
      str[j] = str[i]; // "j" guarda os caracteres que não precisam ser removidos
      j++; 
    }
  }
  str[j] = '\0'; // indica o final da string, agora sem o caractere "ch"
}

