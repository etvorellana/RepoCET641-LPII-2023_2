#include <stdio.h>
#include <stdlib.h>

/*

*/

int main(void){
    FILE * fp = fopen("../Ex04.c", "r");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }

    while(!feof(fp)){
        char linha[100];
        fgets(linha, 100, fp);
        printf("%s", linha);
    }

    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}

