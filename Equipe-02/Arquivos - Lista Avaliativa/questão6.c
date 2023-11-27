#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Questão 6. Faça um programa que leia (do teclado) um cadastro de 10 alunos, indicando o nome, 
nota1, nota2. Calcule a média aritmética simples de cada aluno e depois escreva em um arquivo 
texto os dados: nome, nota1, nota2 e média. Lembre-se de que as notas e médias deverão ser 
apresentadas como valores que possuem até 2 casas após a vírgula. */

// criar uma struct com as variáveis necessárias para o Cadastro do aluno
typedef struct {
    char nome[100];
    float nota1;
    float nota2;
    float media;
} Cadastro;

int main(void){
    Cadastro aluno[10]; // ler o cadastro de 10 alunos
    
    FILE *arq; //  ponteiro para o arquivo que será criado

    arq = fopen("cadastroAlunos.txt", "w"); // abrir um arquivo texto para escrita do cadastro
    if(arq == NULL) // verificação para saber se o arquivo apresentou erro ao abrir
    {
        printf("Erro ao abrir 'cadastroAlunos.txt'.\n");
        exit(1);
    }

    //  em um só 'for' coletei do usuário as informações e já escrevi no arquivo texto criado
    for(int i = 0; i < 10; i++)
    {
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(aluno[i].nome, 50, stdin); // usar fgets para coletar o nome completo
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';

        printf("Digite a nota 1 do aluno %d: ", i+1);
        scanf("%f", &aluno[i].nota1);
        printf("Digite a nota 2 do aluno %d: ", i+1);
        scanf("%f", &aluno[i].nota2);
        getchar(); // para limpar o '\n' do buffer antes da próxima chamada de um fgets

        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2)/2; // média aritmética das notas

        // salvando os dados no arquivo texto
        fprintf(arq, "Nome: %s, Nota 1: %.2f, Nota 2: %.2f, Média: %.2f\n", 
        aluno[i].nome, aluno[i].nota1, aluno[i].nota2, aluno[i].media);
    }
    fclose(arq); // fechar o arquivo
    printf("Arquivo 'cadastroAlunos.txt' criado com sucesso.\n"); // se chegamos até aqui é provável que o arquivo tenha sido criado

    return 0;
}

/* Passos:
1. Criar uma struct com os dados de 10 alunos - nome, nota1, nota2.
2. Abrir um arquivo texto para escrita.
3. Fazer a verificação para saber se o arquivo foi aberto com sucesso.
4. Ler do teclado o cadastro.
  4.1 Esta etapa estava apresentando um problema ao ler com scanf, pois só conseguia ler apenas 
  um nome.
  4.2 Razão:  para string, scanf() não lê além do primeiro espaço em branco.
  4.3 A solução encontrada foi usar a função fgets() que lê até uma nova linha ou até o número 
  máximo de caracteres lidos.
  4.4 Nesse caso, fgets() lê até 49 caracteres já que o último caractere é reservado para o \0 
  ou até um caractere de nova linha.
  4.5 Já que o caractere nova linha é incluído na string, fiz 
  aluno[i].nome[strcspn(aluno[i].nome, "\n")] = 0 para substitui-lo pelo caractere nulo.
  4.6 Usa-se getchar() para evitar que fgets() retorne uma string vazia se for chamada depois de
   scanf(), pois getchar() limpa o '\n' do buffer para que fgets() comece a ler a partir da 
   próxima linha de entrada.
5. Calcular a média aritmética simples de cada aluno.
6. Escrever um arquivo contendo os dados - nome, nota1, nota2 e média. Floats com duas casas 
decimais após a vírgula. 
7. Fechar aquivo.
8. Printar na tela que o arquivo foi aberto com sucesso. */