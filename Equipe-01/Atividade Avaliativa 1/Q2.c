#include <stdio.h>
#include <ctype.h>

//Crie uma função que recebe uma string e dois caracteres (void trocaCaracteres(char ch1, char ch2, char str[])), e substitua todas as ocorrências na string do caractere ch1 pelo caractere ch2.

void trocaCaractere(char ch1, char ch2, char str[]);


int main(void) {
  char string1[100], ch1, ch2;

  printf("Escreva a string: "); 
  fgets(string1, 100, stdin);

  printf("Escreva o caractere que deseja substituir: ");
  scanf(" %c", &ch1);

  printf("Escreva o caractere que deseja que substitua: ");
  scanf(" %c", &ch2);

  trocaCaractere(ch1, ch2, string1);

  printf("\n -- %s", string1);
  return 0;
}

void trocaCaractere(char ch1, char ch2, char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == ch1) { //ch1 representa o caractere original
        str[i] = ch2; // o caractere original vai ser substituido por ch2
      }
    }
}


