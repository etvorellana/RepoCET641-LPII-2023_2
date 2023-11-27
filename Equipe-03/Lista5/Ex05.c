#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

*/

int main(void){
    FILE * fp = fopen("editor_de_texto", "w");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }

    char linha[300];
    
    printf("Editor de texto:\n");
    for (int c = 0; c < 50; c++){
        printf("Linha %d: ", c + 1);
        fgets(linha, 300, stdin);
        if (strcmp(linha, "FIM\n") == 0) break;
        fputs(linha, fp);
    }

    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}

