#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(void) {
  FILE * arq;
  char textoD[250];

  arq = fopen("7.txt", "r+");

  if(arq == NULL)
    printf("Erro no txt\n");

  if(!feof(arq)) {
    textoD[0] = '\0';
    int i = 0;
   while(!feof(arq)) {
    char a, b, c;
    fscanf(arq, "%c%c", &a, &b);
    c = (a + b)/2;
    textoD[i++] = c;
  }
    textoD[i-1] = '\0';
    printf("%s", textoD);
  }
  if(fclose(arq))
    printf("Erro ao fechar o arq");

  return 0;
}