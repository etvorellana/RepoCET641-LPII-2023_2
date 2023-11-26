#include <stdio.h>

int main(){
  FILE *arquivo;
  arquivo = fopen("dados.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  //VERSÃO USANDO INTEIROS
  {
    for (int i = 1; i <= 100; i++)
      fprintf(arquivo, "%d\n", i);
  }

  /*VERSÃO USANDO CHAR{
    int j = 1;
    while(j < 10){
      char c = j + '0';
      fprintf(arquivo, "%c\n", c);
      j++;
    }
    while(j < 100){
      char c[4];
      sprintf(c, "%d\n", j);
      fprintf(arquivo, "%s", c);
      j++;
    }
    fprintf(arquivo, "%s","100\n");
  }*/

  fclose(arquivo);
  printf("Arquivo de texto criado com sucesso: dados.txt\n");

  return 0;
}