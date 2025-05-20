#include <stdio.h>
#include "../includes/structs.h"
#include "../includes/functions.h"
#include <string.h>

#define MAX_FUNCIONARIOS 100

Funcionario funcionarios[MAX_FUNCIONARIOS];
int contagemFuncionarios = 0;

void menuFuncionarios() {
    printf("1. Cadastrar funcionário\n");
    printf("2. Editar funcionário\n");
    printf("3. Aplicar promoção para funcionário\n");
    printf("4. Demitir funcionário\n");
    printf("5. Listar funcionários\n");
    printf("6. Voltar ao menu principal\n\n");
    printf("Escolha uma opção: ");
}

void executarMenuFuncionarios() {
    int opcao = 0;

    menuFuncionarios();
    scanf("%d", &opcao);
    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            cadastrarFuncionario(funcionarios, &contagemFuncionarios);
            break;
        case 2:
            editarCadastroFuncionario();
            break;
        case 3:
            aplicarPromocaoFuncionario(); 
            break;
        case 4:
            demitirFuncionarioPorCPF();
            break;
        case 5:
            listarFuncionarios();
            break;
        case 6:
            executarMenuPrincipal();
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            executarMenuFuncionarios();
    }
}

void cadastrarFuncionario(Funcionario funcionarios[], int *contagemFuncionarios) {
    printf("\n\n------------Cadastro do funcionarios------------\n\n");
    if (*contagemFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Erro: Limite de funcionarios atingido.\n");
        return;
    }

    Funcionario funcionario;
    Endereco endereco;
    cargoFuncao cargo;
    
    printf("\nInsira o CPF do funcionario: ");
    scanf("%s", funcionario.cpf);

    printf("\nInsira o nome do funcionario: ");
    scanf("%s", funcionario.nome);

    printf("\nInsira o email do funcionario: ");
    scanf("%s", funcionario.email);

    printf("\nInsira o telefone do funcionario: ");
    scanf("%s", funcionario.telefone);

    printf("\nInsira o endereco do funcionario:");
    printf("\nRua: ");
    scanf("%s", endereco.rua);
    printf("\nBairro: ");
    scanf("%s", endereco.bairro);
    printf("\nCidade: ");
    scanf("%s", endereco.cidade);
    printf("\nEstado: ");
    scanf("%s", endereco.estado);
    printf("\nCEP: ");
    scanf("%s", endereco.cep);
    printf("\nNúmero: ");
    scanf("%d", &endereco.numero);
    funcionario.endereco = endereco;

    printf("\nInsira o cargo do funcionario:");
    printf("\nNome do cargo: ");
    scanf("%s", cargo.nome);
    printf("\nSalario: ");
    scanf("%f", &cargo.salario);
    printf("\nCarga horária: ");
    scanf("%s", cargo.cargaHoraria);
    funcionario.cargo = cargo;

    funcionarios[*contagemFuncionarios] = funcionario;
    (*contagemFuncionarios)++;

    printf("\nFuncionário cadastrado com sucesso!\n");
    printf("\nDados do funcionário:\n");
    printf("CPF: %s\n", funcionario.cpf);
    printf("Nome: %s\n", funcionario.nome);
    printf("Email: %s\n", funcionario.email);
    printf("Telefone: %s\n", funcionario.telefone);
    printf("Endereço: %s, %s, %s, %s, %s, %d\n", 
           funcionario.endereco.rua, funcionario.endereco.bairro, funcionario.endereco.cidade, 
           funcionario.endereco.estado, funcionario.endereco.cep, funcionario.endereco.numero);
    printf("Cargo: %s, %.2f, %s\n", 
           funcionario.cargo.nome, funcionario.cargo.salario, funcionario.cargo.cargaHoraria);

    executarMenuFuncionarios();
}

void editarCadastroFuncionario() {
    printf("\n\n----- Editar Cadastro de funcionários -----\n\n");
    Funcionario* funcionario = buscaFuncionarioPorCPF();
    if(funcionario == NULL){
        printf("\nCPF não encontrado:\n");
    }else{
        int opcao = 0;
        printf("\nFuncionário encontrado. CPF: %s\n", funcionario->cpf);
        printf("\nDados do funcionário:\n");
        printf("CPF: %s\n", funcionario->cpf);
        printf("Nome: %s\n", funcionario->nome);
        printf("Email: %s\n", funcionario->email);
        printf("Telefone: %s\n", funcionario->telefone);
        printf("Endereço: %s, %s, %s, %s, %s, %d\n", 
        funcionario->endereco.rua, funcionario->endereco.bairro, funcionario->endereco.cidade, 
        funcionario->endereco.estado, funcionario->endereco.cep, funcionario->endereco.numero);
        
        printf("1. Alterar Nome\n");
        printf("2. Alterar Email\n");
        printf("3. Alterar Telefone\n");
        printf("4. Alterar Endereço\n");
        printf("0. Voltar para o menu do funcionário\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        while (getchar() != '\n');
        switch (opcao) {
            case 1:
                printf("\nNovo nome: ");
                fgets(funcionario->nome, sizeof(funcionario->nome), stdin);
                funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0'; // remove o \n
                break;
            case 2:
                printf("\nNovo email: ");
                fgets(funcionario->email, sizeof(funcionario->email), stdin);
                funcionario->email[strcspn(funcionario->email, "\n")] = '\0';
                break;
            case 3:
                printf("\nNovo telefone: ");
                fgets(funcionario->telefone, sizeof(funcionario->telefone), stdin);
                funcionario->telefone[strcspn(funcionario->telefone, "\n")] = '\0';
                break;
            case 4:
                printf("\n--- Novo endereço ---\n");
                printf("Rua: ");
                fgets(funcionario->endereco.rua, sizeof(funcionario->endereco.rua), stdin);
                funcionario->endereco.rua[strcspn(funcionario->endereco.rua, "\n")] = '\0';

                printf("Bairro: ");
                fgets(funcionario->endereco.bairro, sizeof(funcionario->endereco.bairro), stdin);
                funcionario->endereco.bairro[strcspn(funcionario->endereco.bairro, "\n")] = '\0';

                printf("Cidade: ");
                fgets(funcionario->endereco.cidade, sizeof(funcionario->endereco.cidade), stdin);
                funcionario->endereco.cidade[strcspn(funcionario->endereco.cidade, "\n")] = '\0';

                printf("Estado: ");
                fgets(funcionario->endereco.estado, sizeof(funcionario->endereco.estado), stdin);
                funcionario->endereco.estado[strcspn(funcionario->endereco.estado, "\n")] = '\0';

                printf("CEP: ");
                fgets(funcionario->endereco.cep, sizeof(funcionario->endereco.cep), stdin);
                funcionario->endereco.cep[strcspn(funcionario->endereco.cep, "\n")] = '\0';

                printf("Número: ");
                scanf("%d", &funcionario->endereco.numero);
                while (getchar() != '\n'); 
                break;
            case 0:
                executarMenuFuncionarios();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    }
    executarMenuFuncionarios();
}

void aplicarPromocaoFuncionario() {
    printf("\n\n----- Aplicar promoção para funcionário -----\n\n");
    Funcionario* funcionario = buscaFuncionarioPorCPF();
    if (funcionario == NULL) {
        printf("\nCPF não encontrado.\n");
    } else {
        printf("\nFuncionário encontrado. CPF: %s\n", funcionario->cpf);
        printf("\nDados do cargo do funcionário:\n");
        printf("Cargo: %s\n", funcionario->cargo.nome);
        printf("Salário: %.2f\n", funcionario->cargo.salario);
        printf("Carga horária: %s\n", funcionario->cargo.cargaHoraria);
        
        while (getchar() != '\n');
        printf("\nNovo cargo: ");
        fgets(funcionario->cargo.nome, sizeof(funcionario->cargo.nome), stdin);
        funcionario->cargo.nome[strcspn(funcionario->cargo.nome, "\n")] = '\0'; // remove o \n
        
        printf("\nNovo salário: ");
        scanf("%f", &funcionario->cargo.salario);
        while (getchar() != '\n');
        
        printf("\nNova carga horário: ");
        fgets(funcionario->cargo.cargaHoraria, sizeof(funcionario->cargo.cargaHoraria), stdin);
        funcionario->cargo.cargaHoraria[strcspn(funcionario->cargo.cargaHoraria, "\n")] = '\0';
        
        printf("Promoção aplicada com sucesso ao funcionário %s.\n", funcionario->nome);
    }
    executarMenuFuncionarios();
}

void printFuncionarios() {
    for (int i = 0; i < contagemFuncionarios; i++) {
        printf("Funcionário %d: CPF = %s, Nome = %s\n", i + 1, funcionarios[i].cpf, funcionarios[i].nome);
    }
}

Funcionario* buscaFuncionarioPorCPF() {
    char cpfBusca[15];
    printf("Digite o CPF do funcionário: ");
    scanf("%14s", cpfBusca);

    for (int i = 0; i < contagemFuncionarios; i++) {
        if (strcmp(funcionarios[i].cpf, cpfBusca) == 0) {
            return &funcionarios[i];
        }
    }

    return NULL;
}

void demitirFuncionarioPorCPF() {
    printf("\n\n----- Demitir funcionário -----\n\n");
    Funcionario* funcionario = buscaFuncionarioPorCPF();

    if (funcionario == NULL) {
        printf("\nCPF não encontrado.\n");
        executarMenuFuncionarios();
        return;
    }

    int indice = -1;
    for (int i = 0; i < contagemFuncionarios; i++) {
        if (&funcionarios[i] == funcionario) {
            indice = i;
            break;
        }
    }
    
    for (int j = indice; j < contagemFuncionarios - 1; j++) {
        funcionarios[j] = funcionarios[j + 1];
    }
    contagemFuncionarios--;

    printf("Funcionário com CPF %s demitido com sucesso.\n", funcionario->cpf);
    executarMenuFuncionarios();
}

void listarFuncionarios() {
    printf("\n\n----- Lista de Funcionários Cadastrados -----\n\n");
    if (contagemFuncionarios == 0) {
        printf("\nNenhum funcionário cadastrado.\n");
    }else{
        for (int i = 0; i < contagemFuncionarios; i++) {
            Funcionario funcionario = funcionarios[i];
            printf("\nFuncionário %d:\n", i + 1);
            printf("CPF: %s\n", funcionario.cpf);
            printf("Nome: %s\n", funcionario.nome);
            printf("Email: %s\n", funcionario.email);
            printf("Telefone: %s\n", funcionario.telefone);
            printf("Endereço: %s, %s, %s, %s, %s, %d\n", 
                funcionario.endereco.rua, funcionario.endereco.bairro, funcionario.endereco.cidade,
                funcionario.endereco.estado, funcionario.endereco.cep, funcionario.endereco.numero);
            printf("Cargo: %s, %.2f, %s\n", 
                funcionario.cargo.nome, funcionario.cargo.salario, funcionario.cargo.cargaHoraria);
        }
    }
    executarMenuFuncionarios();
}
