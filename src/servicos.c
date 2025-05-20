#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

#define MAX_servicoS 30

servico servicos[MAX_servicoS];
int contagemservicos = 0;
int contagemIdservicos = 0;

void menuservicos() {
    printf("1. Cadastrar serviço\n");
    printf("2. Editar serviço\n");
    printf("3. Excluir serviço\n");
    printf("4. Listar serviços\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuservicos() {
    int opcao = 0;

    menuservicos();
    scanf("%d", &opcao);
    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            cadastrarservico(servicos, &contagemservicos, &contagemIdservicos);
            break;
        case 2:
            editarCadastroservico();
            break;
        case 3:
            excluirservicoPorId();
            break;
        case 4:
            listarservicos();
            break;
        case 5:
            executarMenuPrincipal();
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuservicos();
    }
}

void cadastrarservico(servico servicos[], int *contagemservicos, int *contagemIdservicos) {
    printf("\n\n------------Cadastro de servicos------------\n\n");
    if (*contagemservicos >= MAX_servicoS) {
        printf("Erro: Limite de servicos atingido.\n");
        return;
    }

    servico servico;
    
    servico.id = (*contagemIdservicos)++;

    printf("\nInsira o nome do servico: ");
    scanf("%s", servico.nome);
    printf("\nInsira a duração esperada do servico: ");
    scanf("%d", &servico.duracao);
    printf("\nInsira o preço do servico: ");
    scanf("%f", &servico.preco);

    servico.pontosGerados = servico.preco / 2;
    servico.pontosNecessariosDesconto25 = servico.preco;
    servico.pontosNecessariosDesconto50 = servico.preco * 2;

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
    
    executarMenuservicos();
}

void editarCadastroservico() {
    printf("\n\n----- Editar Cadastro de serviços -----\n\n");
    servico* servico = buscaservicoPorId();
    if(servico == NULL){
        printf("\nId não encontrado:\n");
    }else{
        int opcao = 0;
        printf("\nServiço encontrado. Id: %d\n", servico->id);
        printf("\nDados do serviço:\n");
        printf("Id: %d\n", servico.id);
        printf("Nome: %s\n", servico.nome);
        printf("Duração prevista: %d\n", servico.duracao);
        printf("Preço: %.2f\n", servico.preco);
        printf("Pontos que o serviço gerará: %d\n", servico.pontosGerados);
        printf("Pontos necessários para desconto de 25%%: %d\n", servico.pontosNecessariosDesconto25);
        printf("Pontos necessários para desconto de 50%%: %d\n", servico.pontosNecessariosDesconto50);
        
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
                fgets(servico->nome, sizeof(servico->nome), stdin);
                servico->nome[strcspn(servico->nome, "\n")] = '\0'; // remove o \n
                break;
            case 2:
                printf("\nNova duração estimada: ");
                scanf("%d", &servico->duracao);
                while (getchar() != '\n');
                break;
            case 3:
                printf("\nNovo preço: ");
                scanf("%f", &servico->preco);
                while (getchar() != '\n');
                servico->pontosGerados = servico->preco / 2;
                servico->pontosNecessariosDesconto25 = servico->preco;
                servico->pontosNecessariosDesconto50 = servico->preco * 2;
                break;
            case 0:
                executarMenuservicos();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    }
    executarMenuservicos();
}

void printservicos() {
    for (int i = 0; i < contagemservicos; i++) {
        printf("Serviço %d: Nome = %s, duração estimada = %d, preço = %.2f\n", servicos[i].id, servicos[i].nome, servicos[i].duracao, servicos[i].preco);
    }
}

servico* buscaservicoPorId() {
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

void excluirServiçoPorId() {
    printf("\n\n----- Excluir serviço -----\n\n");
    Servico* servico = buscaServicoPorId();

    if (servico == NULL) {
        printf("\nId não encontrado.\n");
        executarMenuServicos();
        return;
    }

    int indice = -1;
    for (int i = 0; i < contagemservicos; i++) {
        if (&servicos[i] == servico) {
            indice = i;
            break;
        }
    }
    
    for (int j = indice; j < contagemservicos - 1; j++) {
        servicos[j] = servicos[j + 1];
    }
    contagemservicos--;

    printf("Serviço com Id %d excluido com sucesso.\n", servico->id);
    executarMenuservicos();
}

void listarServicos() {
    printf("\n\n----- Lista de Serviços Cadastrados -----\n\n");
    if (contagemservicos == 0) {
        printf("\nNenhum Serviço cadastrado.\n");
    }else{
        for (int i = 0; i < contagemservicos; i++) {
            Servico servico = servicos[i];
            printf("Id: %d\n", servico.id);
            printf("Nome: %s\n", servico.nome);
            printf("Duração prevista: %d\n", servico.duracao);
            printf("Preço: %.2f\n", servico.preco);
            printf("Pontos que o serviço gerará: %d\n", servico.pontosGerados);
            printf("Pontos necessários para desconto de 25%%: %d\n", servico.pontosNecessariosDesconto25);
            printf("Pontos necessários para desconto de 50%%: %d\n", servico.pontosNecessariosDesconto50);
        }
    }
    executarMenuservicos();
}