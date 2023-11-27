#!/bin/bash

echo Criando arquivos

for (( c = 1; c <= 12; c++ ))
    do
    if [ $c -lt 10 ]; then
	    echo Ex0$c.c
	    echo '#include <stdio.h>
#include <stdlib.h>

/*

*/

int main(void){
    FILE * fp = fopen("dados.txt", "w");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }



    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}
' >> Ex0$c.c
    else
        echo Ex$c.c
	    echo '#include <stdio.h>
#include <stdlib.h>

/*

*/

int main(void){
    FILE * fp = fopen("dados.txt", "w");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }



    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}
' >> Ex$c.c
    fi
done

echo Finalizado!

