#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char vet[50][1000];
  int i;

  printf("\n Insira o texto (digite 'FIM' para encerrar): \n");
  for(i = 0; i < 50; i ++){
    printf("\nLinha %d: ", i+1); 
    fgets(vet[i], 50, stdin);

    if(strcmp(vet[i], "FIM\n") == 0){
      printf("\n\n Texto salvo e programa finalizado com sucesso :)");
      break; 
    }
  }

  FILE *arq = fopen("textos.txt", "w");
  if(arq){
    for(int j = 0; j < i; j++){
      fprintf(arq, "%s", vet[j]);
    }
    fclose(arq);
  }else{
  printf("Erro: não foi possível abrir o arquivo.");
  }
  return 0;
}
