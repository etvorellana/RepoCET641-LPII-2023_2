#include <stdio.h>
#include <stdlib.h>

 /* Questão 3. Faça 2 programas, um que leia o arquivo TEXTO criado no exercício 1 e outro que 
 leia o arquivo BINÁRIO criado no exercício 2. Exibir na tela os dados lidos dos respectivos 
 arquivos. */

int main(void) {
    FILE *arqBin; // ponteiro para o arquivo binário

    arqBin = fopen("dados.bin", "rb"); // abrir o arquivo binário para modo leitura
    
    if(arqBin == NULL) // verifica se o arquivo apresentou erro ao abrir
    {
        printf("Erro ao abrir o arquivo 'dados.bin'.\n");
        exit(1);
    }
   
    for(int i = 0; i <= 100; i++)
    { 
        int num = fread(&i, sizeof(int), 1, arqBin); // 'num' recebe a função que escreve no arquivo

        if(num != 1) // se 'num' for diferente do número máximo de itens a serem lidos, que é 1
        printf("Erro ao ler o arquivo 'dados.bin'.\n");
        else // caso não, o conteúdo será impresso na tela 
        printf("%d\n", i);
    }
    fclose(arqBin); // fechar o arquivo

    return 0;
}