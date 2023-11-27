#include <stdio.h>
#include <stdlib.h>

/*

*/

int main(void){
    FILE * fp = fopen("dados.bin", "rb");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }

    //Número de bytes do arquivo
    //char num[296];
    while (!feof(fp)){
        char num;
        fread(&num ,sizeof(char), 1, fp);
        printf("%c", num);
    }

    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}

