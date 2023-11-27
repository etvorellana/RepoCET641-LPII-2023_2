#include <stdio.h>
/*Faça um programa que leia um arquivo texto do disco, lendo linha a linha, e exibindo
cada uma das linhas numeradas na tela. A ideia é podermos pegar um arquivo de
texto qualquer e mostrar na tela com as linhas numeradas.*/
int main() {
    
    FILE *arquivo;
    char linha[100];
    int nLinhas = 1;
    /*Abre o arquivo para leitura*/
    arquivo = fopen("alunos.txt", "r");
    /*Verifica se o arquivo foi aberto corretamente*/
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    /*Le o arquivo linha por linha e imprime o numero da linha e seu conteudo*/
    while (fgets(linha, sizeof(linha), arquivo) != NULL) /*o loop sera realizado ate que retorne NULL, ou seja, o arquivo chegou ao fim*/ 
    {
        printf("%d: %s", nLinhas, linha);
        nLinhas++;
    }
    /*Fecha o arquivo*/
    fclose(arquivo);

    return 0;
}
