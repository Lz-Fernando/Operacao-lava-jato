#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

#define MAX_CLIENTES 100

Cliente clientes[MAX_CLIENTES];
int contagemClientes = 0;

void menuClientes() {
    printf("1. Cadastrar cliente\n");
    printf("2. Editar cliente\n");
    printf("3. Excluir cliente\n");
    printf("4. Listar clientes\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuClientes() {
    if (contagemClientes == 0) {
        carregarClientes(clientes, &contagemClientes);
    }

    int opcao = 0;

    menuClientes();
    scanf("%d", &opcao);

    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            cadastrarCliente(clientes, &contagemClientes);
            break;
        case 2:
            editarCadastroCliente();
            break;
        case 3:
            excluirClientePorCPF();
            break;
        case 4:
            listarClientes();
            break;
        case 5:
            executarMenuPrincipal();
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuClientes();
    }
}

void cadastrarCliente(Cliente clientes[], int *contagemClientes) {
    printf("\n\n------------Cadastro do cliente------------\n\n");
    if (*contagemClientes >= 100) {
        printf("Erro: Limite de clientes atingido.\n");
        return;
    }

    Cliente cliente;
    Endereco endereco;
    
    printf("\nInsira o CPF do cliente: ");
    scanf("%s", cliente.cpf);

    printf("\nInsira o nome do cliente: ");
    scanf("%s", cliente.nome);

    printf("\nInsira o email do cliente: ");
    scanf("%s", cliente.email);

    printf("\nInsira o telefone do cliente: ");
    scanf("%s", cliente.telefone);

    printf("\nInsira o endereco do cliente:");
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

void editarCadastroCliente() {
    printf("\n\n----- Editar Cadastro de Clientes -----\n\n");
    printf("\nPara editar o cadastro do cliente insira o CPF.\n");
    Cliente* cliente = buscaClientePorCPF();
    printClientes(); //Retirar após o teste
    if(cliente == NULL){
        printf("\nCPF não encontrado:\n");
    }else{
        int opcao = 0;
        printf("\nCliente encontrado. CPF: %s\n", cliente->cpf);
        printf("\nDados do cliente:\n");
        printf("CPF: %s\n", cliente->cpf);
        printf("Nome: %s\n", cliente->nome);
        printf("Email: %s\n", cliente->email);
        printf("Telefone: %s\n", cliente->telefone);
        printf("Endereço: %s, %s, %s, %s, %s, %d\n", 
        cliente->endereco.rua, cliente->endereco.bairro, cliente->endereco.cidade, 
        cliente->endereco.estado, cliente->endereco.cep, cliente->endereco.numero);
        printf("Plano: %s\n", cliente->plano);
        
        printf("1. Alterar Nome\n");
        printf("2. Alterar Email\n");
        printf("3. Alterar Telefone\n");
        printf("4. Alterar Endereço\n");
        printf("0. Voltar para o menu do cliente\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        while (getchar() != '\n');
        switch (opcao) {
            case 1:
                printf("\nNovo nome: ");
                fgets(cliente->nome, sizeof(cliente->nome), stdin);
                cliente->nome[strcspn(cliente->nome, "\n")] = '\0'; // remove o \n
                break;
            case 2:
                printf("\nNovo email: ");
                fgets(cliente->email, sizeof(cliente->email), stdin);
                cliente->email[strcspn(cliente->email, "\n")] = '\0';
                break;
            case 3:
                printf("\nNovo telefone: ");
                fgets(cliente->telefone, sizeof(cliente->telefone), stdin);
                cliente->telefone[strcspn(cliente->telefone, "\n")] = '\0';
                break;
            case 4:
                printf("\n--- Novo endereço ---\n");
                printf("Rua: ");
                fgets(cliente->endereco.rua, sizeof(cliente->endereco.rua), stdin);
                cliente->endereco.rua[strcspn(cliente->endereco.rua, "\n")] = '\0';

                printf("Bairro: ");
                fgets(cliente->endereco.bairro, sizeof(cliente->endereco.bairro), stdin);
                cliente->endereco.bairro[strcspn(cliente->endereco.bairro, "\n")] = '\0';

                printf("Cidade: ");
                fgets(cliente->endereco.cidade, sizeof(cliente->endereco.cidade), stdin);
                cliente->endereco.cidade[strcspn(cliente->endereco.cidade, "\n")] = '\0';

                printf("Estado: ");
                fgets(cliente->endereco.estado, sizeof(cliente->endereco.estado), stdin);
                cliente->endereco.estado[strcspn(cliente->endereco.estado, "\n")] = '\0';

                printf("CEP: ");
                fgets(cliente->endereco.cep, sizeof(cliente->endereco.cep), stdin);
                cliente->endereco.cep[strcspn(cliente->endereco.cep, "\n")] = '\0';

                printf("Número: ");
                scanf("%d", &cliente->endereco.numero);
                while (getchar() != '\n'); 
                break;
            case 0:
                break;
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    }
    executarMenuClientes();
}

void printClientes() {
    for (int i = 0; i < contagemClientes; i++) {
        printf("Cliente %d: CPF = %s, Nome = %s\n", i + 1, clientes[i].cpf, clientes[i].nome);
    }
}

Cliente* buscaClientePorCPF() {
    char cpfBusca[15];
    scanf("%14s", cpfBusca);

    for (int i = 0; i < contagemClientes; i++) {
        if (strcmp(clientes[i].cpf, cpfBusca) == 0) {
            return &clientes[i];
        }
    }

    return NULL;
}

void excluirClientePorCPF() {
    printf("\n\n----- Excluir Cliente Cadastrado -----\n\n");
    printf("\nPara excluir o cadastro do cliente, insira o CPF:\n");
    Cliente* cliente = buscaClientePorCPF();

    if (cliente == NULL) {
        printf("\nCPF não encontrado.\n");
    }

    int indice = -1;
    for (int i = 0; i < contagemClientes; i++) {
        if (&clientes[i] == cliente) {
            indice = i;
            break;
        }
    }
    
    for (int j = indice; j < contagemClientes - 1; j++) {
        clientes[j] = clientes[j + 1];
    }
    contagemClientes--;

    printf("Cliente com CPF %s excluído com sucesso.\n", cliente->cpf);
    executarMenuClientes();
}

void listarClientes() {
    printf("\n\n----- Lista de Clientes Cadastrados -----\n\n");
    if (contagemClientes == 0) {
        printf("\nNenhum cliente cadastrado.\n");
    }else{
        for (int i = 0; i < contagemClientes; i++) {
            Cliente cliente = clientes[i];
            printf("\nCliente %d:\n", i + 1);
            printf("CPF: %s\n", cliente.cpf);
            printf("Nome: %s\n", cliente.nome);
            printf("Email: %s\n", cliente.email);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Endereço: %s, %s, %s, %s, %s, %d\n", 
                cliente.endereco.rua, cliente.endereco.bairro, cliente.endereco.cidade,
                cliente.endereco.estado, cliente.endereco.cep, cliente.endereco.numero);
            printf("Plano: %s\n", cliente.plano);
        }
    }
    executarMenuClientes();
}
