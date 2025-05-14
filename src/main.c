#include <stdio.h>
#include "structs.h"
#include "functions.h"

int main() {
    int opcao = 0;

    do {
        menuPrincipal();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                menuClientes();
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
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    } while (opcao != 0);

    return 0;
}