#include <stdio.h>
#include <stdlib.h>

/*

*/

int main(void){
    FILE * fp = fopen("dados.txt", "r");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }

    while (1){
        char num;
        num = fgetc(fp);
        if (num == EOF) break;
        printf("%c", num);
    }

    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}

