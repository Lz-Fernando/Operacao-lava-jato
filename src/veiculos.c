#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

#define MAX_VEICULOS 100

extern int contagemClientes;
extern Cliente clientes[];

Veiculo veiculos[MAX_VEICULOS];
int contagemVeiculos = 0;

void menuVeiculos() {
    printf("1. Cadastrar veículo\n");
    printf("2. Editar veículo\n");
    printf("3. Excluir veículo\n");
    printf("4. Listar veículos\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuVeiculos() {
    if (contagemVeiculos == 0) {
        carregarVeiculos(veiculos, &contagemVeiculos, clientes, &contagemClientes);
    }

    int opcao = 0;
    do {
        menuVeiculos();
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrarVeiculo(veiculos, &contagemVeiculos);
                break;
            case 2:
                editarCadastroVeiculo();
                break;
            case 3:
                excluirVeiculoPorPlaca();
                break;
            case 4:
                listarVeiculos();
                break;
            case 5:
                executarMenuPrincipal();
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    } while (opcao != 5);
}

void cadastrarVeiculo(Veiculo veiculos[], int *contagemVeiculos) {
    printf("\n\n------------Cadastro do veiculo------------\n\n");
    
    if (*contagemVeiculos >= 50) {
        printf("Erro: Limite de veiculos atingido.\n");
        return;
    }
    Veiculo veiculo;

    printf("\nInsira a placa do veiculo: ");
    scanf("%s", veiculo.placa);

    printf("\nInsira o modelo do veiculo: ");
    scanf("%s", veiculo.modelo);

    printf("\nInsira a marca do veiculo: ");
    scanf("%s", veiculo.marca);

    printf("\nInsira o tipo do veiculo: ");
    scanf("%s", veiculo.tipo);

    printf("\nInsira o ano do veiculo: ");
    scanf("%s", veiculo.ano);

    printf("\nInsira a cor do veiculo: ");
    scanf("%s", veiculo.cor);

    printf("\nInsira o CPF do cliente proprietário do veículo: ");
    Cliente* clienteAssociado = buscaClientePorCPF();

    if (clienteAssociado == NULL) {
        printf("Erro: Cliente não encontrado. Veículo não será cadastrado.\n");
        return;
    } else {
        veiculo.cliente = *clienteAssociado;
    }

    veiculos[*contagemVeiculos] = veiculo;
    (*contagemVeiculos)++;

    printf("\nVeículo cadastrado com sucesso!\n");
    printf("\nDados do Veículo:\n");
    printf("Placa: %s\n", veiculo.placa);
    printf("Modelo: %s\n", veiculo.modelo);
    printf("Marca: %s\n", veiculo.marca);
    printf("Tipo: %s\n", veiculo.tipo);
    printf("Ano: %s\n", veiculo.ano);
    printf("Cor: %s\n", veiculo.cor);
    printf("Cliente (proprietário): %s\n", veiculo.cliente.nome);
}

void editarCadastroVeiculo(){
    printf("\n\n----- Editar Cadastro de Veículos -----\n\n");
    printf("Para editar o cadastro do veículo, insira a placa:\n");

    printVeiculos(); //retirar apos o teste

    Veiculo* veiculo = buscaVeiculoPorPlaca();

    if (veiculo == NULL) {
        printf("\nPlaca não encontrada.\n");
    } else {
        int opcao;
            printf("\nVeículo encontrado. Dados atuais:\n");
            printf("1. Modelo: %s\n", veiculo->modelo);
            printf("2. Marca: %s\n", veiculo->marca);
            printf("3. Tipo: %s\n", veiculo->tipo);
            printf("4. Ano: %s\n", veiculo->ano);
            printf("5. Cor: %s\n", veiculo->cor);
            printf("6. Cliente (proprietário): %s\n", veiculo->cliente.nome);
            printf("7. Sair\n");

            printf("\nEscolha o que deseja editar: ");
            scanf("%d", &opcao);
            getchar(); // Limpa o buffer do enter

        switch (opcao) {
            case 1:
                printf("Novo modelo: ");
                scanf("%s", veiculo->modelo);
                break;
            case 2:
                printf("Nova marca: ");
                scanf("%s", veiculo->marca);
                break;
            case 3:
                printf("Novo tipo: ");
                scanf("%s", veiculo->tipo);
                break;
            case 4:
                printf("Novo ano: ");
                scanf("%s", veiculo->ano);
                break;
            case 5:
                printf("Nova cor: ");
                scanf("%s", veiculo->cor);
                break;
            case 6: {
                printf("Novo CPF do cliente: ");
                Cliente* novoCliente = buscaClientePorCPF();
                if (novoCliente != NULL) {
                    veiculo->cliente = *novoCliente;
                    printf("Cliente atualizado com sucesso.\n");
                } else {
                    printf("Cliente não encontrado. Nenhuma alteração feita.\n");
                }
                break;
            }
            case 7:
                printf("Saindo da edição...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}


void printVeiculos(){
    for (int i = 0; i < contagemVeiculos; i++) {
        printf("Veículo %d: placa = %s, Proprietário = %s, Modelo = %s\n", i+1, veiculos[i].placa, veiculos[i].cliente.nome, veiculos[i].modelo);
    }
}

Veiculo* buscaVeiculoPorPlaca(){
    char placaBusca[8];
    scanf("%14s", placaBusca);

    for (int i = 0; i < contagemVeiculos; i++) {
        if (strcmp(veiculos[i].placa, placaBusca) == 0) {
            return &veiculos[i];
        }
    }
    return NULL;
}

void excluirVeiculoPorPlaca() {
    printf("\n\n----- Excluir veiculo Cadastrado -----\n\n");
    printf("\nPara excluir o cadastro do veiculo, insira a placa:\n");
    Veiculo* veiculo = buscaVeiculoPorPlaca();

    if (veiculo == NULL) {
        printf("\nPlaca não encontrado.\n");
        return;
    }

    int indice = -1;
    for (int i = 0; i < contagemVeiculos; i++) {
        if (&veiculos[i] == veiculo) {
            indice = i;
            break;
        }
    }

    for (int j = indice; j < contagemVeiculos - 1; j++) {
        veiculos[j] = veiculos[j + 1];
    }
    contagemVeiculos--;

    printf("Veiculo com placa %s excluído com sucesso.\n", veiculo->placa);
}

void listarVeiculos() {
    printf("\n\n----- Lista de veiculos Cadastrados -----\n\n");
    if (contagemVeiculos == 0) {
        printf("\nNenhum veiculo cadastrado.\n");
    }else{
        for (int i = 0; i < contagemVeiculos; i++) {
            Veiculo veiculo = veiculos[i];
            printf("\nDados do Veículo:\n");
            printf("Placa: %s\n", veiculo.placa);
            printf("Modelo: %s\n", veiculo.modelo);
            printf("Marca: %s\n", veiculo.marca);
            printf("Tipo: %s\n", veiculo.tipo);
            printf("Ano: %s\n", veiculo.ano);
            printf("Cor: %s\n", veiculo.cor);
            printf("Cliente (proprietário): %s\n", veiculo.cliente.nome);
        }
    }
}