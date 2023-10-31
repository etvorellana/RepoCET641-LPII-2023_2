/* Questão 3. Crie uma função que recebe uma string e um array de inteiros (void contaCaracteres(char str[ ], int con [ ])) e retorna, no array de inteiros, quantas vezes aparece na string cada uma das letras do alfabeto. A função não deve fazer distinção entre maiúsculas e minúsculas. */

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para usar isalpha e tolower


/* Antes de mais nada precisamos ter atenção a dois pontos: Primeiro, precisamos verificar se o dígito de fato é um caractere alfabético e, para isso, vou utilizar a função isalpha. Segundo, como a função não deve fazer distinção entre maiúsculas e minúsculas, optei por transformar todo caractere alfabético em minúsculo usando tolower. */

void contaCaracteres(char str[], int con[]) {
    
    // Vamos analisar cada caractere e verificar a frequência de cada letra do alfabeto!
  
    int converte; // precisaremos de uma variável para converter a letra em minúscula, caso ela seja maiúscula. Se não for, permanece inalterada
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (isalpha(str[i])) // se o dígito for uma caractere alfabético, o próximo passo é converter 
        {
          converte = tolower(str[i]) - 'a'; // subtrair - 'a' garante que tenhamos um índice no intervalo entre 0 e 25, ou seja, 'a' e 'z'
          con[converte]++; // conta os caracteres após conversão, caso sejam maiúsculos
        } 
    }
}

int main(void) {
    char str[200];
    int con[26] = {0}; // inicializar cada posição do contador com 0!!!

    // Vamos pedir ao usuário que forneça uma string
    printf("Digite uma string, por favor: ");
    fgets(str, 200, stdin);

    // Vamos chamar a função para contar as letras
    contaCaracteres(str, con);

    // Por último, mas não menos importante, vamos percorrer cada letra do alfabeto para exibir quantas vezes ela aparece na string fornecida
    for (int j = 0; j < 26; j++) 
    {
      printf("%c: %d\n", 'a' + j, con[j]);
    }

  return 0;
}