#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

// MENU PRINCIPAL
void menuPrincipal() {
    printf("1. Gerenciamento de clientes\n");
    printf("2. Gerenciamento de veículos\n");
    printf("3. Gerenciamento de Funcionários\n");
    printf("4. Gerenciamento de serviços\n");
    printf("5. Gerenciamento de Agendamentos\n");
    printf("6. Obter Relatórios\n");
    printf("7. Exit\n\n");
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
            executarMenuVeiculos();
            break;
        case 3:
            executarMenuFuncionarios();
            break;
        case 4:
            executarMenuServicos();
            break;
        case 5:
            executarMenuAgendamentos();
            break;
        case 6:
            menuRelatorios();
            break;
        case 7:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuPrincipal();
    }
}



void menuRelatorios() {
    printf("1. Relatório de serviços realizados\n");
    printf("2. Relatório de clientes\n");
    printf("3. Relatório de funcionários\n");
    printf("4. Relatório de pagamentos\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}
