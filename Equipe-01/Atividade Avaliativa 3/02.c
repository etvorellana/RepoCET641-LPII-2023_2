#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
  FILE *arquivo = fopen("dados.bin", "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  for (int i = 1; i <= 100; i++){
    char c[5];
    sprintf(c, "%d\n", i);
    fwrite(&c, sizeof(char), strlen(c), arquivo);
  }
  fclose(arquivo);
  printf("Arquivo binário criado com sucesso: dados.bin\n");

  return 0;
}