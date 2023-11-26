#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *arquivo, *arquivo_2;
  arquivo = fopen("dados.txt", "r");
  arquivo_2 = fopen("dados.bin", "rb");
  if(arquivo == NULL) {
    printf("Erro ao abrir o arquivo de texto.\n");
    return 1;
  }
  if(arquivo_2 == NULL){
    printf("Erro ao abrir arquivo binário.\n");
    return 1;
  }

  int numero;
  char *linha;

  printf("Arquivo de texto: \n");
  while (fscanf(arquivo, "%d", &numero) == 1) 
    printf("%d\n", numero);

  printf("\n\n");

  fseek(arquivo_2, 0, SEEK_END);
  int tam = ftell(arquivo_2);
  rewind(arquivo_2);

  linha = (char*) malloc(tam);
  fread(linha, sizeof(char), tam, arquivo_2);
  printf("Arquivo binário: \n%s", linha);

  free(linha);
  fclose(arquivo);
  fclose(arquivo_2);

  return 0;
}
