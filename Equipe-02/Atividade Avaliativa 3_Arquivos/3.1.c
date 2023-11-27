 #include <stdio.h>
 #include <stdlib.h>

 /* Questão 3. Faça 2 programas, um que leia o arquivo TEXTO criado no exercício 1 e outro que 
 leia o arquivo BINÁRIO criado no exercício 2. Exibir na tela os dados lidos dos respectivos 
 arquivos. */

int main(void) {
    FILE *arq; // ponteiro para o arquivo

    arq = fopen("dados.txt", "r"); // abrir o arquivo texto para o momento leitura

    if(arq == NULL) // verificação para saber se o arquivo apresentou erro ao abrir
    {
        printf("Erro ao abrir o arquivo 'dados.txt'.\n");
        exit(1);
    } 

    char ch = fgetc(arq); // lê um caractere do arquivo
    while(!feof(arq)) // enquanto não chegar ao fim do arquivo
    {
        putchar(ch); // imprime o caractere (da primeira vez recebe o primeiro valor de 'ch') 
        ch = fgetc(arq); // lé um novo caractere do arquivo
    }

    int err = fclose(arq); // a variável recebe o fechamento do arquivo para saber se teve erro
    if(err) // err != 0
    {
        printf("Erro ao fechar o arquivo 'dados.txt.\n");
    }
    
    return 0;
}