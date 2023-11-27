#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

  FILE *arq = fopen("alunos_cadastro.txt", "w");
  char nome[50];
  float nota1, nota2, media;


  if(arq){
    for(int i = 0; i < 10; i++){
      printf("\n -- Cadastro do %dº aluno ---\n\n", i+1);
      printf("Nome: ");
      fgets(nome, 50 , stdin);
      printf("Nota 1: ");
      scanf("%f", &nota1);
      printf("Nota 2: ");
      scanf("%f", &nota2);
      media = (nota1 + nota2) / 2;
      fprintf(arq, "Nome: %s", nome);
      fprintf(arq, "Nota 1: %.2f\n", nota1);
      fprintf(arq, "Nota 2: %.2f\n", nota2);
      fprintf(arq, "Média: %.2f\n\n", media);

    }
    printf("\nCampos preenchidos. Dados dos alunos gravados no arquivo.");
    fclose(arq);
  }else{
    printf("Erro: não foi possível abrir o arquivo");
  }

  return 0;
}
