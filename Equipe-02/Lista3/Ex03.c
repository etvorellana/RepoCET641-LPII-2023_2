#include <stdio.h>
#include <ctype.h>

/*
Crie uma função que recebe uma string e um array de inteiros 
(void contaCaracteres(char str[ ], int con [ ])) e 
retorna, no array de inteiros, quantas vezes aparece na string cada uma das letras do alfabeto. 
A função não deve fazer distinção entre maiúsculas e minúsculas.
*/


void contaCaracteres(char str[], int con[]){
    char ch = 'A';
    while (ch != ('Z' + 1)){
        for (int c = 0; str[c] != '\0';c ++){
            if (ch == toupper(str[c])) {
                con[ch - 'A']++;
            }
        }
        ch++;
    }
}


int main(void){
    char str[] = "Hello word Im linux";
    int con[27] = {0};

    printf("String: %s\n\n", str);

    contaCaracteres(str, con);
    for (int c = 0; c < 26; c++){
        printf("Letra %c: %d\n", 'A' + c, con[c]);
    }

    return 0;
}


