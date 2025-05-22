#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

#define MAX_Servicos 30

Servico servicos[MAX_Servicos];
int contagemServicos = 0;
int contagemIdServicos = 0;

void menuServicos() {
    printf("1. Cadastrar serviço\n");
    printf("2. Editar serviço\n");
    printf("3. Excluir serviço\n");
    printf("4. Listar serviços\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuServicos() {
    if (contagemServicos == 0) {
        carregarClientes(clientes, &contagemClientes, &contagemIdServicos);
    }

    int opcao = 0;

    menuServicos();
    scanf("%d", &opcao);
    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            cadastrarServico(servicos, &contagemServicos, &contagemIdServicos);
            break;
        case 2:
            editarCadastroServico();
            break;
        case 3:
            excluirServicoPorId();
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

void cadastrarServico(Servico servicos[], int *contagemServicos, int *contagemIdServicos) {
    printf("\n\n------------Cadastro de servicos------------\n\n");
    if (*contagemServicos >= MAX_Servicos) {
        printf("Erro: Limite de servicos atingido.\n");
        return;
    }

    Servico servico;
    
    servico.id = (*contagemIdServicos)++;

    printf("\nInsira o nome do servico: ");
    scanf("%s", servico.nome);
    printf("\nInsira a duração esperada do servico: ");
    scanf("%d", &servico.duracao);
    printf("\nInsira o preço do servico: ");
    scanf("%f", &servico.preco);

    servico.pontosGerados = servico.preco / 2;
    servico.pontosNecessariosDesconto25 = servico.preco;
    servico.pontosNecessariosDesconto50 = servico.preco * 2;

    servicos[(*contagemServicos)++] = servico;

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
    Servico* servico = buscaServicoPorId();
    if(servico == NULL){
        printf("\nId não encontrado:\n");
    }else{
        int opcao = 0;
        printf("\nServiço encontrado. Id: %d\n", servico->id);
        printf("\nDados do serviço:\n");
        printf("Id: %d\n", servico->id);
        printf("Nome: %s\n", servico->nome);
        printf("Duração prevista: %d\n", servico->duracao);
        printf("Preço: %.2f\n", servico->preco);
        printf("Pontos que o serviço gerará: %d\n", &servico->pontosGerados);
        printf("Pontos necessários para desconto de 25%%: %d\n", servico->pontosNecessariosDesconto25);
        printf("Pontos necessários para desconto de 50%%: %d\n", servico->pontosNecessariosDesconto50);
        
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
                executarMenuServicos();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    }
    executarMenuServicos();
}

void printServicos() {
    for (int i = 0; i < contagemServicos; i++) {
        printf("Serviço %d: Nome = %s, duração estimada = %d, preço = %.2f\n", servicos[i].id, servicos[i].nome, servicos[i].duracao, servicos[i].preco);
    }
}

Servico* buscaServicoPorId() {
    int idBusca = 0;
    printf("Digite o Id do serviço: ");
    scanf("%d", &idBusca);
    while (getchar() != '\n');

    for (int i = 0; i < contagemServicos; i++) {
        if (servicos[i].id == idBusca) {
            return &servicos[i];
        }
    }

    return NULL;
}

void excluirServicoPorId() {
    printf("\n\n----- Excluir serviço -----\n\n");
    Servico* servico = buscaServicoPorId();

    if (servico == NULL) {
        printf("\nId não encontrado.\n");
        executarMenuServicos();
        return;
    }

    int indice = -1;
    for (int i = 0; i < contagemServicos; i++) {
        if (&servicos[i] == servico) {
            indice = i;
            break;
        }
    }
    
    for (int j = indice; j < contagemServicos - 1; j++) {
        servicos[j] = servicos[j + 1];
    }
    contagemServicos--;

    printf("Serviço com Id %d excluido com sucesso.\n", servico->id);
    executarMenuServicos();
}

void listarServicos() {
    printf("\n\n----- Lista de Serviços Cadastrados -----\n\n");
    if (contagemServicos == 0) {
        printf("\nNenhum Serviço cadastrado.\n");
    }else{
        for (int i = 0; i < contagemServicos; i++) {
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
    executarMenuServicos();
}