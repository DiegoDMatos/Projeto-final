#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 50
#define VETOR 10


struct conta{
    char nome[TAM];
    char senha[TAM];
    float saldo;
};

typedef struct conta Conta;

void login(struct conta contas[VETOR])
{
    char aux_nome[TAM];
    char aux_senha[TAM];
    printf("----------Bem-vindo ao Dbank---------- \n");

    printf("Digite seu nome: ");
    fgets(aux_nome, TAM, stdin);
    getchar();
    aux_nome[strcspn(aux_nome, "\n")] = 0;
    printf("Digite sua senha: ");
    fgets(aux_senha, TAM, stdin);
    getchar();
    aux_senha[strcspn(aux_senha, "\n")] = 0;

    for(int i = 0; i < VETOR; i++){

        if(strcmp(aux_nome, contas[i].nome) == 1 && strcmp(aux_senha, contas[i].senha) == 1){
            printf("Login realizado com sucesso! \n");
            printf("Bem vindo, %s ! \n", contas[i].nome);
            return;
        }


        }
    printf("Nome ou senha incorretos! \n");
    

}

void cadastrarConta(struct conta contas[VETOR], int totalContas)
{
    if(totalContas >= VETOR){
        printf("Limite de contas atingido! \n");
        return;
    }
    

    printf("---------- Seja nosso cliente ---------- \n");

    printf("Digite seu nome: ");
    fgets(contas[totalContas].nome, TAM, stdin);
    contas[totalContas].nome[strcspn(contas[totalContas].nome, "\n")] = 0; // Remove '\n'

    char aux[TAM];
    do {
        printf("Digite sua senha: ");
        fgets(contas[totalContas].senha, TAM, stdin);
        fflush(stdin);
        contas[totalContas].nome[strcspn(contas[totalContas].nome, "\n")] = '\0'; // Remove '\n'

        printf("Confirme sua senha: ");
        fgets(aux, TAM, stdin);
        aux[strcspn(aux, "\n")] = 0; // Remove '\n'

        if (strcmp(contas[totalContas].senha, aux) != 0) {
            printf("As senhas não correspondem! Tente novamente.\n");
        }
    } while (strcmp(contas[totalContas].senha, aux) != 0); // Repete até que as senhas sejam iguais

    printf("Conta cadastrada com sucesso! \n");
    totalContas++;
        
    
    
    
}

int main(){
    Conta contas[VETOR];
    int totalContas = 0;

    int opcao;
    printf("----------Bem-vindo ao Dbank---------- \n");
    printf("O que deseja? \n1 - Login \n2 - Cadastrar conta \n3 - Sair \n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        login(contas);
        break;

    case 2:
        cadastrarConta(contas, totalContas);
        break;
    
    default:
        break;
    }

setlocale(LC_ALL, "Portuguese"); 

return 0;    
}