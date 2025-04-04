#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>


#define TAM 50
#define VETOR 10


struct conta{
    char nome[TAM];
    char senha[TAM];
    float saldo;
};

typedef struct conta Conta;

void login(struct conta contas[])
{
    char aux_nome[TAM];
    char aux_senha[TAM];
    printf("----------Bem-vindo ao Dbank---------- \n");

    printf("Digite seu nome: ");
    fgets(aux_nome, TAM, stdin);
    aux_nome[strcspn(aux_nome, "\n")] = 0;
    printf("Digite sua senha: ");
    fgets(aux_senha, TAM, stdin);
    aux_senha[strcspn(aux_senha, "\n")] = 0;

    system("cls");


    for(int i = 0; i < VETOR; i++){

        if(strcmp(aux_nome, contas[i].nome) == 0 && strcmp(aux_senha, contas[i].senha) == 0){
            printf("Login realizado com sucesso! \n");
            printf("Bem vindo, %s ! \n", contas[i].nome);
            return;
        }


        }
    printf("Nome ou senha incorretos! \n");
    

}

void cadastrarConta(Conta contas[], int *totalContas) {
    if (*totalContas >= VETOR) {
        printf("Limite de contas atingido! \n");
        return;
    }

    printf("---------- Seja nosso cliente ---------- \n");

    printf("Digite seu nome: ");
    fgets(contas[*totalContas].nome, TAM, stdin);
    contas[*totalContas].nome[strcspn(contas[*totalContas].nome, "\n")] = '\0';

    char aux[TAM];

    do {
        printf("Digite sua senha: ");
        fgets(contas[*totalContas].senha, TAM, stdin);
        contas[*totalContas].senha[strcspn(contas[*totalContas].senha, "\n")] = '\0'; 

        printf("Confirme sua senha: ");
        fgets(aux, TAM, stdin);
        aux[strcspn(aux, "\n")] = '\0';

        if (strcmp(contas[*totalContas].senha, aux) != 0) {
            printf("As senhas não correspondem! Tente novamente.\n");
        }
    } while (strcmp(contas[*totalContas].senha, aux) != 0);

    printf("Conta cadastrada com sucesso! \n");

    contas[*totalContas].saldo = 0.0;
    printf("Seu saldo inicial é: %.2f \n", contas[*totalContas].saldo);
    printf("Retornando a tela de login... \n");
    sleep(3);
    system("cls");
    


    
    
    (*totalContas)++;
}


int main(){

    setlocale(LC_ALL, "Portuguese");
    Conta contas[VETOR];
    int totalContas;

    int opcao;
    printf("----------Bem-vindo ao Dbank---------- \n");
    printf("O que deseja? \n1 - Login \n2 - Cadastrar conta \n3 - Sair \n");
    scanf("%d", &opcao);
    getchar();
    system("cls");

    switch (opcao)
    {
    case 1:
        login(contas);
        break;

    case 2:
        cadastrarConta(contas, &totalContas);
        login(contas);
        break;

    case 3:
        printf("Saindo do programa... \n");
        break;
    
    default:
        printf("Opção inválida! \n");
        break;
    }

 

return 0;    
}