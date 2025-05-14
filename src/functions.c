#include <stdio.h>
#include "structs.h"
#include "functions.h"

void menuPrincipal() {
    printf("1. Gerenciamento de clientes\n");
    printf("2. Gerenciamento de veículos\n");
    printf("3. Gerenciamento de Funcionários\n");
    printf("4. Gerenciamento de serviços\n");
    printf("5. Relatórios\n");
    printf("0. Exit\n\n");
    printf("Escolha uma opção: ");
}

void menuClientes() {
    printf("1. Cadastrar cliente\n");
    printf("2. Editar cliente\n");
    printf("3. Excluir cliente\n");
    printf("4. Listar clientes\n");
    printf("0. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void menuVeiculos() {
    printf("1. Cadastrar veículo\n");
    printf("2. Editar veículo\n");
    printf("3. Excluir veículo\n");
    printf("4. Listar veículos\n");
    printf("0. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void menuFuncionarios() {
    printf("1. Cadastrar funcionário\n");
    printf("2. Editar funcionário\n");
    printf("3. Excluir funcionário\n");
    printf("4. Listar funcionários\n");
    printf("0. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void menuServicos() {
    printf("1. Cadastrar serviço\n");
    printf("2. Editar serviço\n");
    printf("3. Excluir serviço\n");
    printf("4. Listar serviços\n");
    printf("0. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void menuRelatorios() {
    printf("1. Relatório de serviços realizados\n");
    printf("2. Relatório de clientes\n");
    printf("3. Relatório de funcionários\n");
    printf("4. Relatório de pagamentos\n");
    printf("0. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

/*cadastro e gerenciamento de
clientes, registro e controle de veículos, agendamento de serviços, execução e
acompanhamento de serviços, gestão de funcionários, organização de pagamentos,
gerenciamento de um plano de fidelidade e por fim a geração de relatórios e
histórico de serviços*/