/*Faça um programa que peça para o usuário entrar um texto que deseja procurar (uma palavra) e que em seguida leia um arquivo texto do disco e procure por esta palavra no arquivo. 
Caso seja encontrada a palavra digitada pelo usuário em alguma das linhas do arquivo texto lido do disco, 
o programa deverá exibir na tela o número da linha do arquivo onde encontrou esta ocorrência da palavra, bem como o conteúdo da linha onde se encontra a palavra procurada.*/

/*Link da Noticia: https://www.cnnbrasil.com.br/tecnologia/chatgpt-robo-de-inteligencia-artificial-domina-redes-com-redacoes-de-qualidade/*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeBarraN(char *c);

int main(void){
  
  char palavra[100] = {};
  printf("\nEntre com a palavra: ");
  fgets(palavra,100,stdin);
  removeBarraN(palavra);

 
  int i;
  char *lin,*c;
  char linha[1000];
  FILE *arq;
  arq = fopen("questao9.txt","r");
  
  if(arq==NULL){
    printf("\nErro ao abrir o arquivo questao9.txt\n");
    exit(1);
  }

  i = 1;
  while(!feof(arq)){
    lin = fgets(linha,1000,arq);
    removeBarraN(lin);
    c = strstr(lin,palavra);
    if(c!=NULL){
      printf("\nLinha %d: %s\n",i,lin);
    }
    i++;
  }

  if(ferror(arq)){
    printf("\nErro ao ler o arquivo questao9.txt\n");
  }

  if(fclose(arq)){
    printf("\nErro ao fechar o arquivo questao9.txt\n");
  }
  return 0;
}

void removeBarraN(char *c){
  int tam = strlen(c);
  c[tam-1] = '\0';
}
