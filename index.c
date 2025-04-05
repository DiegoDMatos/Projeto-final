#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 50
#define VETOR 10

struct conta {
    char nome[TAM];
    char senha[TAM];
    float saldo;
};

typedef struct conta Conta;

void login(Conta contas[], int *id, int totalContas) {
    char aux_nome[TAM];
    char aux_senha[TAM];

    printf("---------- Bem-vindo ao Dbank ----------\n");
    printf("Digite seu nome: ");
    fgets(aux_nome, TAM, stdin);
    aux_nome[strcspn(aux_nome, "\n")] = 0;

    printf("Digite sua senha: ");
    fgets(aux_senha, TAM, stdin);
    aux_senha[strcspn(aux_senha, "\n")] = 0;

    system("cls");

    for (int i = 0; i < totalContas; i++) {
        if (strcmp(aux_nome, contas[i].nome) == 0 && strcmp(aux_senha, contas[i].senha) == 0) {
            printf("Login realizado com sucesso!\n");
            printf("Bem-vindo, %s!\n", contas[i].nome);
            *id = i;
            sleep(2);
            system("cls");
            return;
        }
    }

    printf("Nome ou senha incorretos!\n");
    sleep(2);
    system("cls");
    *id = -1;
}

void cadastrarConta(Conta contas[], int *totalContas) {
    if (*totalContas >= VETOR) {
        printf("Limite de contas atingido!\n");
        return;
    }

    printf("---------- Seja nosso cliente ----------\n");
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

    contas[*totalContas].saldo = 0.0;
    printf("Conta cadastrada com sucesso!\n");
    printf("Seu saldo inicial é: R$ %.2f\n", contas[*totalContas].saldo);
    (*totalContas)++;

    printf("Retornando à tela inicial...\n");
    sleep(3);
    system("cls");
}

void exibirMenu(Conta contas[], int id) {
    int opcao;

    do {
        printf("---------- Menu ----------\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                float valorDeposito;
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valorDeposito);
                getchar();

                if (valorDeposito <= 0) {
                    printf("Valor inválido!\n");
                } else {
                    contas[id].saldo += valorDeposito;
                    printf("Depósito realizado com sucesso! Seu novo saldo é: R$ %.2f\n", contas[id].saldo);
                }
                break;
            }

            case 2: {
                char senhaDigitada[TAM];
                printf("Confirme sua senha para continuar: ");
                fgets(senhaDigitada, TAM, stdin);
                senhaDigitada[strcspn(senhaDigitada, "\n")] = '\0';

                if (strcmp(senhaDigitada, contas[id].senha) != 0) {
                    printf("Senha incorreta! Operação cancelada.\n");
                    break;
                }

                float valorSaque;
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valorSaque);
                getchar();

                if (valorSaque <= 0) {
                    printf("Valor inválido!\n");
                } else if (valorSaque > contas[id].saldo) {
                    printf("Saldo insuficiente! Seu saldo atual é: R$ %.2f\n", contas[id].saldo);
                } else {
                    contas[id].saldo -= valorSaque;
                    printf("Saque realizado com sucesso! Seu novo saldo é: R$ %.2f\n", contas[id].saldo);
                }
                break;
            }

            case 3:
                printf("Saindo do menu...\n");
                sleep(2);
                system("cls");
                return;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        system("cls");

    } while (1);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Conta contas[VETOR];
    int totalContas = 0;
    int id;

    int opcao;
    while (1) {
        printf("---------- Bem-vindo ao Dbank ----------\n");
        printf("O que deseja?\n1 - Login\n2 - Cadastrar conta\n3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();
        system("cls");

        switch (opcao) {
            case 1:
                login(contas, &id, totalContas);
                if (id != -1) {
                    exibirMenu(contas, id);
                }
                break;

            case 2:
                cadastrarConta(contas, &totalContas);
                break;

            case 3:
                printf("Saindo do programa...\n");
                return 0;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
