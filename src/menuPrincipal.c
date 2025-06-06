#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

// MENU PRINCIPAL
void menuPrincipal() {
    printf("1. Gerenciamento de Clientes\n");
    printf("2. Gerenciamento de Veículos\n");
    printf("3. Gerenciamento de Funcionários\n");
    printf("4. Gerenciamento de Serviços\n");
    printf("5. Gerenciamento de Agendamentos\n");
    printf("6. Gerenciamento de Pagamentos\n");
    printf("7. Obter Relatórios\n");
    printf("8. Exit\n\n");
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
            executarMenuPagamentos();
            break;
        case 7:
            executarMenuRelatorios();
            break;
        case 8:
            printf("Saindo do programa...\n");
            return;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuPrincipal();
    }
}