#include <stdio.h>
#include <stdlib.h>

/* Questão 2. Faça um programa que crie um arquivo BINÁRIO em disco, com o nome “dados.bin”, e 
escreva neste arquivo em disco uma contagem de números inteiros que vá de 1 até 100, com um 
número em cada linha. Abra este arquivo em um editor de textos e observe como ficou o seu 
conteúdo. Compare o tamanho do arquivo criado com o do arquivo criado no exercício anterior. */

int main(void) {
    FILE *arqBin;

    arqBin = fopen("dados.bin", "wb");

    if(arqBin == NULL)
    {
      printf("Erro ao abrir o arquivo 'dados.bin'.\n");
      exit(1);
    }

    for(int i = 0; i <= 100; i++) 
    {
      fwrite(&i, sizeof(int), 1, arqBin); 
      /* fwrite escreve no arquivo e recebe o ponteiro para os dados serem gravados, o tamanho 
      do item em bytes, o máximo de itens a serem gravados e o ponteiro para o arquivo. */
    }
    fclose(arqBin); // fechar o arquivo

    printf("Arquivo 'dados.txt' gerado com sucesso.\n"); // imprimir a mensagem se o arquivo foi gerado com sucesso

    return 0;
}

/* int num = fwrite(&i, sizeof(int), 1, arqBin);
      if(num != 1)
      printf("Problemas na escrita.\n"); */