#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(void){
  FILE * arq;
  char texto[250], textoC[250];

  arq = fopen("7.txt", "w+");

  if(arq == NULL)
    printf("Erro no txt\n");

  printf("Digite o texto a ser criptografado: \n");
  fgets(texto, 250, stdin);
  for(int i = 0; texto[i] != '\0'; i++) {
    if(texto[i] == '\n')
      textoC[i] = texto[i];
    else
      fprintf(arq, "%c%c", texto[i] + 3, texto[i] - 3);
  }
  if(fclose(arq))
    printf("Erro ao fechar o arq");

  return 0;
}