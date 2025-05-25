#include <stdio.h>
#include <string.h>
#include "../includes/structs.h"
#include "../includes/functions.h"


extern Agendamento agendamentos[100];
extern int contagemAgendamentos;
Pagamento pagamentos[100];
int contagemPagamentos = 0;  

void menuPagamentos() {
    printf("1. Cadastrar pagamento\n");
    printf("2. Listar pagamentos\n");
    printf("3. Alterar status do pagamento\n");
    printf("4. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuPagamentos() {
    int opcao = 0;
    do {
        menuPagamentos();
        scanf("%d", &opcao);
        while (getchar() != '\n');
        switch (opcao) {
            case 1:
                cadastrarPagamento();
                break;
            case 2:
                listarPagamentos();
                break;
            case 3:
                alterarStatusPagamento();
                break;
            case 4:
                executarMenuPrincipal();
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 4);
}

void cadastrarPagamento() {
    if (contagemPagamentos >= 100) {
        printf("Limite de pagamentos atingido.\n");
        return;
    }

    Pagamento novoPagamento;
    novoPagamento.id = contagemPagamentos + 1;

    printf("Valor do pagamento: ");
    if (scanf("%f", &novoPagamento.valor) != 1 || novoPagamento.valor <= 0) {
        printf("Valor inválido!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int opcaoPagamento;
    printf("\nForma de pagamento: 1. Dinheiro 2. Cartão 3. Pix\nEscolha uma opção: ");
    if (scanf("%d", &opcaoPagamento) != 1) {
        printf("Opção inválida!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');
    switch (opcaoPagamento) {
        case 1: strcpy(novoPagamento.formaPagamento, "Dinheiro"); break;
        case 2: strcpy(novoPagamento.formaPagamento, "Cartão"); break;
        case 3: strcpy(novoPagamento.formaPagamento, "Pix"); break;
        default:
            printf("Opção inválida!\n\n");
            return;
    }

    int opcaoStatus;
    printf("Status do pagamento: 1. Pendente 2. Pago 3. Cancelado\nEscolha uma opção: ");
    
    if (scanf("%d", &opcaoStatus) != 1) {
        printf("Opção inválida!\n");
        while (getchar() != '\n');
        return;
    }

    while (getchar() != '\n');
    switch (opcaoStatus) {
        case 1: strcpy(novoPagamento.status, "Pendente"); break;
        case 2: strcpy(novoPagamento.status, "Pago"); break;
        case 3: strcpy(novoPagamento.status, "Cancelado"); break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    if (contagemAgendamentos == 0) {
        printf("\nNenhum agendamento cadastrado.\n");
        printf("Por favor, cadastre um agendamento antes de cadastrar um pagamento.\n");
        return;
    }

    printf("Insira o ID do agendamento relacionado: ");
    int idAgendamento;
    if (scanf("%d", &idAgendamento) != 1) {
        printf("ID inválido!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    Agendamento* ag = NULL;
    for (int i = 0; i < contagemAgendamentos; i++) {
        if (agendamentos[i].id == idAgendamento) {
            ag = &agendamentos[i];
            break;
        }
    }
    if (!ag) {
        printf("Agendamento não encontrado!\n");
        return;
    }
    novoPagamento.agendamento = *ag;
    preencherDataHora(&novoPagamento.agendamento.dataHora);
    printf("Agendamento encontrado: ID %d, Cliente %s\n", novoPagamento.agendamento.id, novoPagamento.agendamento.cliente.nome);
    printf("Data e hora do agendamento: %02d/%02d/%04d %s\n", 
           novoPagamento.agendamento.dataHora.dia, 
           novoPagamento.agendamento.dataHora.mes, 
           novoPagamento.agendamento.dataHora.ano, 
           novoPagamento.agendamento.dataHora.hora);
    printf("Status do agendamento: %s\n", novoPagamento.agendamento.status);
    
    pagamentos[contagemPagamentos++] = novoPagamento;
    printf("Pagamento cadastrado com sucesso!\n");
}

void listarPagamentos() {
    printf("\n\n----- Lista de Pagamentos -----\n\n");
    
    if (contagemPagamentos == 0) {
        printf("Nenhum pagamento cadastrado.\n");
        return;
    }

    for (int i = 0; i < contagemPagamentos; i++) {
        Pagamento p = pagamentos[i];
        printf("\nPagamento %d:\n", i + 1);
        printf("ID: %d\n", p.id);
        printf("Valor: %.2f\n", p.valor);
        printf("Forma de pagamento: %s\n", p.formaPagamento);
        printf("Status: %s\n", p.status);
        printf("Agendamento ID: %d\n", p.agendamento.id);
        printf("Cliente: %s\n", p.agendamento.cliente.nome);
        printf("Data do pagamento: %02d/%02d/%04d %s\n", p.data.dia, p.data.mes, p.data.ano, p.data.hora);
    }
}

void alterarStatusPagamento() {

    if (contagemPagamentos == 0) {
        printf("Nenhum pagamento cadastrado.\n");
        return;
    }
    
    printf("\nPara alterar o status do pagamento, insira o ID do pagamento:\n");
    int idBusca;
    scanf("%d", &idBusca);
    while (getchar() != '\n');

    Pagamento* pagamento = NULL;
    for (int i = 0; i < contagemPagamentos; i++) {
        if (pagamentos[i].id == idBusca) {
            pagamento = &pagamentos[i];
            break;
        }
    }

    if (!pagamento) {
        printf("Pagamento não encontrado.\n");
        return;
    }

    printf("Status atual: %s\n", pagamento->status);
    printf("Escolha o novo status:\n");
    printf("1. Pendente\n2. Pago\n3. Cancelado\nEscolha uma opção: ");
    int statusOpcao;
    scanf("%d", &statusOpcao);
    while (getchar() != '\n');

    switch (statusOpcao) {
        case 1: strcpy(pagamento->status, "Pendente"); break;
        case 2: strcpy(pagamento->status, "Pago"); break;
        case 3: strcpy(pagamento->status, "Cancelado"); break;
        default: printf("Opção inválida!\n"); return;
    }

    printf("Status do pagamento ID %d alterado para %s.\n", pagamento->id, pagamento->status);
}
