#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"

Cliente clientes[100];
Veiculo veiculos[100];
Servico servicos[100];
PlanoFidelidade planosFidelidade[100];
Funcionario funcionarios[100];
Agendamento agendamento[100];
Pagamento pagamentos[100];
RegistroServico registros[100];


int contagemClientes = 0;
int contagemIdEndereco = 1;

// MENU PRINCIPAL
void menuPrincipal() {
    printf("1. Gerenciamento de clientes\n");
    printf("2. Gerenciamento de veículos\n");
    printf("3. Gerenciamento de Funcionários\n");
    printf("4. Gerenciamento de serviços\n");
    printf("5. Relatórios\n");
    printf("6. Exit\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuPrincipal() {
    int opcao = 0;

    menuPrincipal();
    scanf("%d", &opcao);

    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            executarMenuClientes();
            break;
        case 2:
            menuVeiculos();
            break;
        case 3:
            menuFuncionarios();
            break;
        case 4:
            menuServicos();
            break;
        case 5:
            menuRelatorios();
            break;
        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuPrincipal();
    }
}

// CLIENTES
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
        case 2:
            printf("Saindo do programa...\n");
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
    scanf(" %[^\n]", cliente.nome);

    printf("\nInsira o email do cliente: ");
    scanf("%s", cliente.email);

    printf("\nInsira o telefone do cliente: ");
    scanf("%s", cliente.telefone);

    printf("\nInsira o endereco do cliente:");
    endereco.id = *contagemIdEndereco;
    (*contagemIdEndereco)++;
    printf("\nRua: ");
    scanf(" %[^\n]", endereco.rua);
    printf("\nBairro: ");
    scanf(" %[^\n]", endereco.bairro);
    printf("\nCidade: ");
    scanf(" %[^\n]", endereco.cidade);
    printf("\nEstado: ");
    scanf(" %[^\n]", endereco.estado);
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
}

void menuVeiculos() {
    printf("1. Cadastrar veículo\n");
    printf("2. Editar veículo\n");
    printf("3. Excluir veículo\n");
    printf("4. Listar veículos\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void menuFuncionarios() {
    printf("1. Cadastrar funcionário\n");
    printf("2. Editar funcionário\n");
    printf("3. Excluir funcionário\n");
    printf("4. Listar funcionários\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void menuServicos() {
    printf("1. Cadastrar serviço\n");
    printf("2. Editar serviço\n");
    printf("3. Excluir serviço\n");
    printf("4. Listar serviços\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void menuRelatorios() {
    printf("1. Relatório de serviços realizados\n");
    printf("2. Relatório de clientes\n");
    printf("3. Relatório de funcionários\n");
    printf("4. Relatório de pagamentos\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

/*cadastro e gerenciamento de
clientes, registro e controle de veículos, agendamento de serviços, execução e
acompanhamento de serviços, gestão de funcionários, organização de pagamentos,
gerenciamento de um plano de fidelidade e por fim a geração de relatórios e
histórico de serviços*/