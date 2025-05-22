#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

#define MAX_SERVICOS 100

Servico servicos[MAX_SERVICOS];
int contagemservicos = 0;
int contagemIdservicos = 0;

void menuServicos() {
    printf("1. Cadastrar serviço\n");
    printf("2. Editar serviço\n");
    printf("3. Excluir serviço\n");
    printf("4. Listar serviços\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuServicos() {
    int opcao = 0;

    menuServicos();
    scanf("%d", &opcao);
    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            cadastrarServico(servicos, &contagemservicos, &contagemIdservicos);
            break;
        case 2:
            editarCadastroServico();
            break;
        case 3:
            excluirServicosPorId();
            break;
        case 4:
            listarServicos();
            break;
        case 5:
            executarMenuPrincipal();
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuServicos();
    }
}

void cadastrarServico(Servico servicos[], int *contagemservicos, int *contagemIdservicos) {
    printf("\n\n------------Cadastro de servicos------------\n\n");
    if (*contagemservicos >= MAX_SERVICOS) {
        printf("Erro: Limite de servicos atingido.\n");
        return;
    }

    Servico servico;
    
    servico.id = (*contagemIdservicos)++;

    printf("\nInsira o nome do servico: ");
    fgets(servico.nome, sizeof(servico.nome), stdin);
    servico.nome[strcspn(servico.nome, "\n")] = '\0';
    printf("\nInsira a duração esperada do servico: ");
    scanf("%d", &servico.duracao);
    while (getchar() != '\n');
    printf("\nInsira o preço do servico: ");
    scanf("%f", &servico.preco);
    while (getchar() != '\n');

    servico.pontosGerados = (int)(servico.preco / 2);
    servico.pontosNecessariosDesconto25 = (int)servico.preco;
    servico.pontosNecessariosDesconto50 = (int)(servico.preco * 2);

    servicos[(*contagemservicos)++] = servico;

    printf("\nServiço cadastrado com sucesso!\n");
    printf("\nDados do serviço:\n");
    printf("Id: %d\n", servico.id);
    printf("Nome: %s\n", servico.nome);
    printf("Duração prevista: %d\n", servico.duracao);
    printf("Preço: %.2f\n", servico.preco);
    printf("Pontos que o serviço gerará: %d\n", servico.pontosGerados);
    printf("Pontos necessários para desconto de 25%%: %d\n", servico.pontosNecessariosDesconto25);
    printf("Pontos necessários para desconto de 50%%: %d\n", servico.pontosNecessariosDesconto50);
    
    executarMenuServicos();
}

void editarCadastroServico() {
    printf("\n\n----- Editar Cadastro de serviços -----\n\n");
    Servico* servicoPtr = buscaServicoPorId();
    if(servicoPtr == NULL){
        printf("\nId não encontrado:\n");
    }else{
        int opcao = 0;
        printf("\nServiço encontrado. Id: %d\n", servicoPtr->id);
        printf("\nDados do serviço:\n");
        printf("Id: %d\n", servicoPtr->id);
        printf("Nome: %s\n", servicoPtr->nome);
        printf("Duração prevista: %d\n", servicoPtr->duracao);
        printf("Preço: %.2f\n", servicoPtr->preco);
        printf("Pontos que o serviço gerará: %d\n", servicoPtr->pontosGerados);
        printf("Pontos necessários para desconto de 25%%: %d\n", servicoPtr->pontosNecessariosDesconto25);
        printf("Pontos necessários para desconto de 50%%: %d\n", servicoPtr->pontosNecessariosDesconto50);

        printf("1. Alterar Nome\n");
        printf("2. Alterar duração estimada\n");
        printf("3. Alterar preço\n");
        printf("0. Voltar para o menu do serviço\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        while (getchar() != '\n');
        switch (opcao) {
            case 1:
                printf("\nNovo nome: ");
                fgets(servicoPtr->nome, sizeof(servicoPtr->nome), stdin);
                servicoPtr->nome[strcspn(servicoPtr->nome, "\n")] = '\0';
                break;
            case 2:
                printf("\nNova duração estimada: ");
                scanf("%d", &servicoPtr->duracao);
                while (getchar() != '\n');
                break;
            case 3:
                printf("\nNovo preço: ");
                scanf("%f", &servicoPtr->preco);
                while (getchar() != '\n');
                servicoPtr->pontosGerados = (int)(servicoPtr->preco / 2);
                servicoPtr->pontosNecessariosDesconto25 = (int)servicoPtr->preco;
                servicoPtr->pontosNecessariosDesconto50 = (int)(servicoPtr->preco * 2);
                break;
            case 0:
                executarMenuServicos();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    }
    executarMenuServicos();
}

void printServicos() {
    for (int i = 0; i < contagemservicos; i++) {
        printf("Serviço %d: Nome = %s, duração estimada = %d, preço = %.2f\n", servicos[i].id, servicos[i].nome, servicos[i].duracao, servicos[i].preco);
    }
}

Servico* buscaServicoPorId() {
    int idBusca = 0;
    printf("Digite o Id do serviço: ");
    scanf("%d", &idBusca);
    while (getchar() != '\n');

    for (int i = 0; i < contagemservicos; i++) {
        if (servicos[i].id == idBusca) {
            return &servicos[i];
        }
    }

    return NULL;
}

void excluirServicosPorId() {
    printf("\n\n----- Excluir serviço -----\n\n");
    Servico* servicoParaExcluir = buscaServicoPorId();

    if (servicoParaExcluir == NULL) {
        printf("\nId não encontrado.\n");
        executarMenuServicos();
        return;
    }

    int indice = -1;
    for (int i = 0; i < contagemservicos; i++) {
        if (servicos[i].id == servicoParaExcluir->id) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        printf("Erro interno: serviço não encontrado na lista.\n");
        executarMenuServicos();
        return;
    }

    for (int j = indice; j < contagemservicos - 1; j++) {
        servicos[j] = servicos[j + 1];
    }
    contagemservicos--;

    printf("Serviço com Id %d excluido com sucesso.\n", servicoParaExcluir->id);
    executarMenuServicos();
}

void listarServicos() {
    printf("\n\n----- Lista de Serviços Cadastrados -----\n\n");
    if (contagemservicos == 0) {
        printf("\nNenhum Serviço cadastrado.\n");
    } else {
        for (int i = 0; i < contagemservicos; i++) {
            Servico currentServico = servicos[i];
            printf("Id: %d\n", currentServico.id);
            printf("Nome: %s\n", currentServico.nome);
            printf("Duração prevista: %d\n", currentServico.duracao);
            printf("Preço: %.2f\n", currentServico.preco);
            printf("Pontos que o serviço gerará: %d\n", currentServico.pontosGerados);
            printf("Pontos necessários para desconto de 25%%: %d\n", currentServico.pontosNecessariosDesconto25);
            printf("Pontos necessários para desconto de 50%%: %d\n", currentServico.pontosNecessariosDesconto50);
            printf("----------------------------------------\n");
        }
    }
    executarMenuServicos();
}