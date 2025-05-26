#include <stdio.h>
#include <string.h>
#include "../includes/structs.h"
#include "../includes/functions.h"

Agendamento agendamentos[100];
int contagemAgendamentos = 0;

Agendamento* buscaAgendamentoPorID(int id) {

    printf("Agendamentos cadastrados:\n");
        for (int i = 0; i < contagemAgendamentos; i++) {
            printf("ID: %d\n", agendamentos[i].id);
        }

    for (int i = 0; i < contagemAgendamentos; i++) {
        if (agendamentos[i].id == id) {
            return &agendamentos[i];
        }
    }
    return NULL;
}

void menuAgendamentos() {
    printf("1. Cadastrar agendamento\n");
    printf("2. Editar agendamento\n");
    printf("3. Alterar status do agendamento\n");
    printf("4. Excluir agendamento\n");
    printf("5. Listar agendamentos\n");
    printf("6. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuAgendamentos() {
    int opcao = 0;
    do {
        menuAgendamentos();
        scanf("%d", &opcao);
        while (getchar() != '\n');
        switch (opcao) {
            case 1: cadastrarAgendamento(agendamentos, &contagemAgendamentos);
                break;
            case 2: editarCadastroAgendamento();
                break;
            case 3: alterarStatusAgendamento();
                break;
            case 4: excluirAgendamentoPorID();
                break;
            case 5: listarAgendamentos();
                break;
            case 6: executarMenuClientes();
                break;
            default: printf("Opção inválida! Tente novamente.\n\n");
        }
    } while (opcao != 5);
}

void cadastrarAgendamento(Agendamento agendamentos[], int *contagemAgendamentos) {
    if (*contagemAgendamentos >= 100) {
        printf("Erro: Limite de agendamentos atingido.\n");
        return;
    }

    DataHora dataHora;

    printf("\nInsira o CPF do cliente: ");
    Cliente* clienteSelecionado = buscaClientePorCPF();
    if (!clienteSelecionado) { printf("\nCliente não encontrado.\n"); return; }

    printf("\nInsira a placa do veiculo: ");
    //Tive problemas com a função de buscaVeiculoPorPlaca
    Veiculo* veiculoSelecionado = buscaVeiculoPorPlaca();
    if (!veiculoSelecionado) { printf("\nVeículo não encontrado.\n"); return; }

    printf("\nInsira o Id do serviço: ");
    Servico* servicoSelecionado = buscaServicoPorId();
    if (!servicoSelecionado) { printf("\nServiço não encontrado.\n"); return; }

    // Adicionei funcionário, percebi que estava sem
    printf("\nInsira o CPF do funcionário responsável: ");
    Funcionario* funcionarioSelecionado = buscaFuncionarioPorCPF();
    if (!funcionarioSelecionado) { printf("\nFuncionário não encontrado.\n"); return; }

    preencherDataHora(&dataHora);

    printf("\nInsira o status do agendamento: 1. Pendente 2. Confirmado 3. Cancelado\nEscolha uma opção: ");
    int opcaoStatus;
    scanf("%d", &opcaoStatus);
    while (getchar() != '\n');

    int idx = *contagemAgendamentos;
    agendamentos[idx].id = idx + 1;
    agendamentos[idx].cliente = *clienteSelecionado;
    agendamentos[idx].veiculo = *veiculoSelecionado;
    agendamentos[idx].servico = *servicoSelecionado;
    agendamentos[idx].funcionario = *funcionarioSelecionado;
    agendamentos[idx].dataHora = dataHora;
    switch (opcaoStatus) {
        case 1: strcpy(agendamentos[idx].status, "Pendente"); break;
        case 2: strcpy(agendamentos[idx].status, "Confirmado"); break;
        case 3: strcpy(agendamentos[idx].status, "Cancelado"); break;
        default: printf("Opção inválida!\n"); return;
    }
    (*contagemAgendamentos)++;
    printf("Agendamento cadastrado com sucesso!\n");
}

void editarCadastroAgendamento() {
    printf("\nPara editar o agendamento, insira o CPF do cliente:\n");
    char cpfBusca[15];
    scanf("%14s", cpfBusca);
    while (getchar() != '\n');

    Agendamento* agendamento = NULL;
    for (int i = 0; i < contagemAgendamentos; i++)
        if (strcmp(agendamentos[i].cliente.cpf, cpfBusca) == 0)
            { agendamento = &agendamentos[i]; break; }
    if (!agendamento) { printf("\nNenhum agendamento encontrado para este CPF.\n"); return; }

    printf("\nAgendamento encontrado. ID: %d\n", agendamento->id);
    printf("Cliente: %s\n", agendamento->cliente.nome);
    printf("Veículo: %s\n", agendamento->veiculo.placa);
    printf("Serviço: %s\n", agendamento->servico.nome);
    printf("Data: %02d/%02d/%04d\n", agendamento->dataHora.dia, agendamento->dataHora.mes, agendamento->dataHora.ano);
    printf("Hora: %s\n", agendamento->dataHora.hora);
    printf("Status: %s\n", agendamento->status);

    printf("\n1. Alterar Cliente\n2. Alterar Veículo\n3. Alterar Serviço\n4. Alterar Data e Hora\n5. Alterar Status\n0. Voltar\nEscolha uma opção: ");
    int opcao;
    scanf("%d", &opcao);
    while (getchar() != '\n');
    switch (opcao) {
        case 1:
            listarClientes();
            printf("\nInsira o CPF do novo cliente: ");
            { Cliente* novoCliente = buscaClientePorCPF();
              if (novoCliente) agendamento->cliente = *novoCliente;
              else printf("Cliente não encontrado.\n"); }
            break;
        case 2:
            listarVeiculos();
            printf("\nInsira a placa do novo veículo: ");
            { Veiculo* novoVeiculo = buscaVeiculoPorPlaca();
              if (novoVeiculo) agendamento->veiculo = *novoVeiculo;
              else printf("Veículo não encontrado.\n"); }
            break;
        case 3:
            listarServicos();
            printf("\nInsira o Id do novo serviço: ");
            { Servico* novoServico = buscaServicoPorId();
              if (novoServico) agendamento->servico = *novoServico;
              else printf("Serviço não encontrado.\n"); }
            break;
        case 4:
            preencherDataHora(&agendamento->dataHora);
            break;
        case 5:
            printf("\nNovo status: 1. Pendente 2. Confirmado 3. Cancelado\nEscolha uma opção: ");
            int statusOpcao;
            scanf("%d", &statusOpcao);
            while (getchar() != '\n');
            switch (statusOpcao) {
                case 1: strcpy(agendamento->status, "Pendente"); break;
                case 2: strcpy(agendamento->status, "Confirmado"); break;
                case 3: strcpy(agendamento->status, "Cancelado"); break;
                default: printf("Opção inválida!\n");
            }
            break;
        case 0: break;
        default: printf("Opção inválida!\n");
    }
}

void alterarStatusAgendamento() {
    
    printf("\n\n----- Alterar Status do Agendamento -----\n\n");
    printf("Para alterar o status, insira o ID do agendamento:\n");
    int idBusca;
    scanf("%d", &idBusca);
    while (getchar() != '\n');

    Agendamento* agendamento = buscaAgendamentoPorID(idBusca);

    if (!agendamento) {
        printf("\nID não encontrado.\n");
        printf("Veja a lista de agendamentos cadastrados:\n");
        listarAgendamentos();
        return;
    }

    printf("Status atual: %s\n", agendamento->status);
    printf("Escolha o novo status:\n");
    printf("1. Pendente\n2. Confirmado\n3. Cancelado\nEscolha uma opção: ");
    int statusOpcao;
    scanf("%d", &statusOpcao);
    while (getchar() != '\n');

    switch (statusOpcao) {
        case 1: strcpy(agendamento->status, "Pendente"); break;
        case 2: strcpy(agendamento->status, "Confirmado"); break;
        case 3: strcpy(agendamento->status, "Cancelado"); break;
        default: printf("Opção inválida!\n"); return;
    }

    printf("Status do agendamento ID %d alterado para %s.\n", agendamento->id, agendamento->status);
}

void excluirAgendamentoPorID() {
    printf("Insira o ID do agendamento para excluir: ");
    int idBusca;
    scanf("%d", &idBusca);
    while (getchar() != '\n');

    Agendamento* agendamento = buscaAgendamentoPorID(idBusca);

    if (!agendamento) {
        printf("\nAgendamento não encontrado.\n");
        listarAgendamentos();
        return;
    }

    int indice = -1;
    for (int i = 0; i < contagemAgendamentos; i++)
        if (agendamentos[i].id == agendamento->id) { indice = i; break; }
    if (indice == -1) { printf("\nID não encontrado.\n"); return; }
    for (int j = indice; j < contagemAgendamentos - 1; j++)
        agendamentos[j] = agendamentos[j + 1];
    contagemAgendamentos--;
    printf("Agendamento com ID %d excluído com sucesso.\n", agendamento->id);
}

void listarAgendamentos() {
    printf("\n\n----- Lista de Agendamentos Cadastrados -----\n\n");
    if (contagemAgendamentos == 0) {
        printf("\nNenhum agendamento cadastrado.\n");
    } else {
        for (int i = 0; i < contagemAgendamentos; i++) {

            Agendamento agendamento = agendamentos[i];
            printf("\nAgendamento %d:\n", i + 1);
            printf("ID: %d\n", agendamento.id);
            printf("Cliente: %s (CPF: %s)\n", agendamento.cliente.nome, agendamento.cliente.cpf);
            printf("Veículo: %s\n", agendamento.veiculo.placa);
            printf("Serviço: %s\n", agendamento.servico.nome);
            printf("Data: %02d/%02d/%04d\n", agendamento.dataHora.dia, agendamento.dataHora.mes, agendamento.dataHora.ano);
            printf("Hora: %s\n", agendamento.dataHora.hora);
            printf("Status: %s\n", agendamento.status);
        }
    }
    executarMenuAgendamentos();
}
