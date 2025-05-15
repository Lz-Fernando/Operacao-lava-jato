#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"

Cliente clientes[100];

int contagemClientes = 0;
int contagemIdEndereco = 1;

void menuClientes() {
    printf("1. Cadastrar cliente\n");
    printf("2. Editar cliente\n");
    printf("3. Excluir cliente\n");
    printf("4. Listar clientes\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuClientes() {
    int opcao = 0;

    menuClientes();
    scanf("%d", &opcao);

    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            cadastrarCliente(clientes, &contagemIdEndereco, &contagemClientes);
            break;
        case 5:
            executarMenuPrincipal();
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuClientes();
    }
}

void cadastrarCliente(Cliente clientes[], int *contagemIdEndereco, int *contagemClientes) {
    if (*contagemClientes >= 100) {
        printf("Erro: Limite de clientes atingido.\n");
        return;
    }

    Cliente cliente;
    Endereco endereco;

    printf("\n\n------------Cadastro do cliente------------\n");
    printf("\nInsira o CPF do cliente: ");
    scanf("%s", cliente.cpf);

    printf("\nInsira o nome do cliente: ");
    scanf("%s", cliente.nome);

    printf("\nInsira o email do cliente: ");
    scanf("%s", cliente.email);

    printf("\nInsira o telefone do cliente: ");
    scanf("%s", cliente.telefone);

    printf("\nInsira o endereco do cliente:");
    endereco.id = *contagemIdEndereco;
    (*contagemIdEndereco)++;
    printf("\nRua: ");
    scanf("%s", endereco.rua);
    printf("\nBairro: ");
    scanf("%s", endereco.bairro);
    printf("\nCidade: ");
    scanf("%s", endereco.cidade);
    printf("\nEstado: ");
    scanf("%s", endereco.estado);
    printf("\nCEP: ");
    scanf("%s", endereco.cep);
    printf("\nNúmero: ");
    scanf("%d", &endereco.numero);

    cliente.endereco = endereco;

    printf("\nInsira o plano do cliente: ");
    scanf("%s", cliente.plano);

    clientes[*contagemClientes] = cliente;
    (*contagemClientes)++;

    printf("\nCliente cadastrado com sucesso!\n");
    printf("\nDados do cliente:\n");
    printf("CPF: %s\n", cliente.cpf);
    printf("Nome: %s\n", cliente.nome);
    printf("Email: %s\n", cliente.email);
    printf("Telefone: %s\n", cliente.telefone);
    printf("Endereço: %s, %s, %s, %s, %s, %d\n", 
           cliente.endereco.rua, cliente.endereco.bairro, cliente.endereco.cidade, 
           cliente.endereco.estado, cliente.endereco.cep, cliente.endereco.numero);
    printf("Plano: %s\n", cliente.plano);

    executarMenuClientes();
}