#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 50

struct conta{
    char nome[TAM];
    char senha[TAM];
};

typedef struct conta Conta;

void cadastrarConta(struct conta Conta)
{
    printf("----------Seja nosso cliente---------- \n");

    printf("Digite seu nome: ");
    fgets(Conta.nome, TAM, stdin);
    Conta.nome[strcspn(Conta.nome, "\n")] = 0;
    printf("Digite sua senha: ");
    fgets(Conta.senha, TAM, stdin);
    printf("Confirme sua senha: ");
    char aux[TAM];
    fgets(aux, TAM, stdin);
    while(Conta.senha != aux){
        printf("As senhas não correspondem! \n");

        printf("Digite sua senha: ");
        fgets(Conta.senha, TAM, stdin);
        printf("Confirme sua senha: ");
        char aux[TAM];
        fgets(aux, TAM, stdin);
    }
    getchar();
    printf("Conta cadastrada com sucesso! \n");
}

int main(){
struct conta Conta;
setlocale(LC_ALL, "Portuguese"); 
cadastrarConta(Conta);

return 0;    
}