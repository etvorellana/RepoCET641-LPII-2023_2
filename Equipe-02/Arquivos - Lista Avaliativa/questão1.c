#include <stdio.h>
#include <stdlib.h>

/* Questão 1. Faça um programa que crie um arquivo TEXTO em disco, com o nome “dados.txt”, e 
escreva neste arquivo em disco uma contagem que vá de 1 até 100, com um número em cada linha. 
Abra este arquivo em um editor de textos e verifique se o mesmo foi criado corretamente. */

int main(void) {
    FILE *arq; // ponteiro para o arquivo
    
    arq  = fopen("dados.txt", "w"); // abrir o arquivo para o modo leitura
    
    if(arq == NULL) // verificação para saber se o arquivo apresentou erro ao abrir
    {
       printf("Erro ao abrir o arquivo 'dados.txt'.\n");
       exit(1);
    }
    
    // contagem de 1 até 100, cada número em cada linha
    for (int i = 0; i <= 100; i++) 
    {
      fprintf(arq,"%d\n", i); // recebe o arquivo e o que será 'impresso' nele
    } 
    fclose(arq); // fechar o arquivo

    printf("Arquivo 'dados.txt' gerado com sucesso.\n"); // imprimir a mensagem se o arquivo foi gerado com sucesso

    return 0;
}

/* int num = fprintf(arq,"%d\n", i);
      if(num == EOF)
      printf("Erro na gravação.\n"); */