/*Crie um programa C que:
Crie/abra um arquivo texto de nome "novo.txt". Se o arquivo já existir deve ser substituído pelo atual;
Permita que o usuário entre com diversos caracteres nesse arquivo, até que o o mesmo entre com o caractere ’>’, que indicara o fim da entrada de dados;
Feche o arquivo e abra novamente.
Lendo o arquivo caractere por caractere e armazenando numa string.
Escreva na tela com printf todos os caracteres armazenados.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  
  FILE *arq;
  arq = fopen("novo.txt","w");

  if(arq==NULL){
    printf("\nErro ao abrir o arquivo novo.txt\n");
    exit(1);
  }
  
  char c;
  while(1){
    printf("Entre com um caractere (Parar >): ");
    scanf("%c",&c);
    if(c == '>') break;
    fprintf(arq,"%c",c);
    getc(stdin);
  }

  if(ferror(arq)){
    printf("\nErro ao escrever no arquivo novo.txt\n");
  }

  if(fclose(arq)){
    printf("\nErro ao fechar o arquivo novo.txt\n");
  }

  FILE *arq2;
  arq2 = fopen("novo.txt","r");

  if(arq2==NULL){
    printf("\nErro ao abrir o arquivo novo.txt\n");
    exit(1);
  }

  int i = 0;
  char c2,lin[200] = {};
  while(1){
    c2 = fgetc(arq);
    if (c2 == EOF) break;
    lin[i] = c2;
    i++;
  }
  
  lin[i] = '\0';
  
  if(ferror(arq)){
    printf("\nErro no preenchimento da string\n");
  }

    printf("\nA string é: %s\n",lin);

  if(fclose(arq)){
    printf("\nErro ao fechar o arquivo novo.txt\n");
  }
  return 0;
}