#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(){
  FILE *arquivo = fopen("dados.bin", "wb");
  
  if(arquivo){
    for (int i = 1; i <= 100; i++){
      char c[5];
      sprintf(c, "%d\n", i);
      fwrite(&c, sizeof(char), strlen(c), arquivo);
    }
    fclose(arquivo);
    printf("Arquivo binário criado com sucesso: dados.bin\n");
    return 0;
  }
  /*
  if(arquivo){
    for(int i = 1; i <= 100; i++){
      char c = (i == 100) ? '\0' : '\n';
      fwrite(&i, sizeof(int), 1, arquivo);
      fwrite(&c, sizeof(char), 1, arquivo);
    }
    fclose(arquivo);
    printf("Arquivo criado com sucesso.\n");
    return 0;
  }*/
  printf("Erro ao abrir o arquivo.\n");
  return 1;
}
