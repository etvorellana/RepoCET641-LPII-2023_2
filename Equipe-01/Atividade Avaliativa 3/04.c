#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *arquivo;
  char nome[100]; 
  printf("Digite o nome do seu arquivo de texto: ");
  fgets(nome, 100, stdin);
  nome[strlen(nome)-1] = '\0';
  arquivo = fopen(nome, "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  char *linha;
  fseek(arquivo, 0, SEEK_END);
  int tam = ftell(arquivo);
  rewind(arquivo);
  linha = (char*) malloc(tam);
  int numeroLinha = 1;

  while (fgets(linha, tam, arquivo) != NULL)
    printf("%d. %s", numeroLinha++, linha);
  fclose(arquivo);
  free(linha);

  return 0;
}
