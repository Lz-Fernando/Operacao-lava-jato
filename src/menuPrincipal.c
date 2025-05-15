#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"


Veiculo veiculos[100];
Servico servicos[100];
PlanoFidelidade planosFidelidade[100];
Funcionario funcionarios[100];
Agendamento agendamento[100];
Pagamento pagamentos[100];
RegistroServico registros[100];

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