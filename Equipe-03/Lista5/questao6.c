/*Faça um programa que leia (do teclado) um cadastro de 10 alunos, indicando o nome, nota1, nota2. Calcule a média aritmética simples de cada aluno e depois escreva em um arquivo texto os dados: nome, nota1, nota2 e média. Lembre-se de que as notas e médias deverão ser apresentadas como valores que possuem até 2 casas após a vírgula.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void retiraBarraN(char nome[]);

typedef struct Aluno{
  char nome[100];
  float nota1,nota2,media;
}aluno;

int main(void){
  
  aluno turma[10];
  for(int i = 0;i<10;i++){
    printf("\nNome: ");
    fgets(turma[i].nome,100,stdin);
    printf("\nNota1: ");
    scanf("%f",&turma[i].nota1);
    printf("\nNota2: ");
    scanf("%f",&turma[i].nota2);
    scanf("%*c");
    turma[i].media = (turma[i].nota1+turma[i].nota2)/2.0;
    retiraBarraN(turma[i].nome);
    printf("\n---------------\n");
  }

  FILE *arq;
  arq = fopen("notas.txt","w");
  
  if(arq==NULL){
    printf("\nErro ao abrir o arquivo notas.txt!!!\n");
    exit(1);
  }

  for(int i = 0;i<10;i++){
    fprintf(arq,"%s,%.2f,%.2f,%.2f\n",turma[i].nome,turma[i].nota1,turma[i].nota2,turma[i].media);
  }

  if(ferror(arq)){
    printf("\nErro ao escrever no arquivo notas.txt\n");
  }

  if(fclose(arq)){
    printf("\nErro ao fechar o arquivo notas.txt\n");
  }
  return 0;
}

void retiraBarraN(char nome[]){
  
  int tam = strlen(nome);
  nome[tam-1] = '\0';
}