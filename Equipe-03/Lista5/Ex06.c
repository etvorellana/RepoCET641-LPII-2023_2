#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

*/

int main(void){
    FILE * fp = fopen("alunos.txt", "w");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }

    for (int c = 0; c < 10; c++){
        char nome[50];
        float nota1;
        float nota2;
        float media;

        printf("\nDigite o nome do aluno %d: ", c + 1);
        fgets(nome, 50, stdin); 
        nome[strlen(nome) - 1] = '\0';

        printf("Digite a nota 1: ");
        scanf("%f", &nota1);
        getc(stdin);

        printf("Digite a nota 2: ");
        scanf("%f", &nota2);
        media = (nota1 + nota2) / 2;
        getc(stdin);

        fprintf(fp, "Nome: %s, nota1: %.2f, nota2: %.2f, media: %.2f\n", nome, nota1, nota2, media);
    }


    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}

