#include <stdio.h>
#include "../includes/structs.h"

int carregarClientes(Cliente clientes[], int *contagemClientes) {
  FILE *file = fopen("./dados/clientes.txt", "r");
  if (!file) {
    printf("Arquivo de clientes não encontrado.\n");
    return 0;
  }
  *contagemClientes = 0;
  while (fscanf(file, "%14[^;];%49[^;];%14[^;];%49[^;];%49[^;];%29[^;];%29[^;];%29[^;];%9[^;];%d;%14[^\n]\n",
    clientes[*contagemClientes].cpf,
    clientes[*contagemClientes].nome,
    clientes[*contagemClientes].telefone,
    clientes[*contagemClientes].email,
    clientes[*contagemClientes].endereco.rua,
    clientes[*contagemClientes].endereco.bairro,
    clientes[*contagemClientes].endereco.cidade,
    clientes[*contagemClientes].endereco.estado,
    clientes[*contagemClientes].endereco.cep,
    &clientes[*contagemClientes].endereco.numero,
    clientes[*contagemClientes].plano
  ) == 11) {
    (*contagemClientes)++;
  }
  fclose(file);
  return *contagemClientes;
}

int carregarVeiculos(Veiculo veiculos[], int *contagemVeiculos) {
  FILE *file = fopen("./dados/veiculos.txt", "r");
  if (!file) {
    printf("Arquivo de veiculos não encontrado.\n");
    return 0;
  }
  *contagemVeiculos = 0;
  while (fscanf(file, "%9[^;];%29[^;];%29[^;];%19[^;];%d14[^;];%19[^;];%14[^\n]\n",
    veiculos[*contagemVeiculos].placa,
    veiculos[*contagemVeiculos].modelo,
    veiculos[*contagemVeiculos].marca,
    veiculos[*contagemVeiculos].tipo,
    veiculos[*contagemVeiculos].ano,
    veiculos[*contagemVeiculos].cor,
    veiculos[*contagemVeiculos].cliente
  ) == 7) {
    (*contagemVeiculos)++;
  }
  fclose(file);
  return *contagemVeiculos;
}

int carregarFuncionarios(Funcionario Funcionarios[], int *contagemFuncionarios) {
  FILE *file = fopen("./dados/funcionarios.txt", "r");
  if (!file) {
    printf("Arquivo de funcionarios não encontrado.\n");
    return 0;
  }
  *contagemFuncionarioss = 0;
  while (fscanf(file, "%14[^;];%49[^;];%49[^;];%14[^;];%49[^;];%29[^;];%29[^;];%29[^;];%9[^;];%d;%14[^\n];%49[^\n];%f20[^\n];%19[^\n]\n",
    Funcionarios[*contagemFuncionarios].cpf,
    Funcionarios[*contagemFuncionarios].nome,
    Funcionarios[*contagemFuncionarios].email,
    Funcionarios[*contagemFuncionarios].telefone,
    Funcionarios[*contagemFuncionarios].endereco.rua,
    Funcionarios[*contagemFuncionarios].endereco.bairro,
    Funcionarios[*contagemFuncionarios].endereco.cidade,
    Funcionarios[*contagemFuncionarios].endereco.estado,
    Funcionarios[*contagemFuncionarios].endereco.cep,
    &Funcionarios[*contagemFuncionarios].endereco.numero,
    Funcionarios[*contagemFuncionarios].cargo.nome,
    &Funcionarios[*contagemFuncionarios].cargo.salario,
    Funcionarios[*contagemFuncionarios].cargo.cargaHoraria
  ) == 13) {
    (*contagemFuncionarios)++;
  }
  fclose(file);
  return *contagemFuncionarios;
}

int carregarServicos(Servico servicos[], int *contagemServicos, int *contagemIdServicos) {
  FILE *file = fopen("./dados/servicos.txt", "r");
  if (!file) {
    printf("Arquivo de servicos não encontrado.\n");
    return 0;
  }
  *contagemServicos = 0;
  *contagemIdServicos = 0;
  while (fscanf(file, "%d14[^;];%49[^;];%d14[^;];%f19[^;];%d14[^;];%d14[^;];%d14[^;][^\n]\n",
    &servicos[*contagemServicos].id,
    servicos[*contagemServicos].nome,
    &servicos[*contagemServicos].duracao,
    &servicos[*contagemServicos].preco,
    &servicos[*contagemServicos].pontosGerados,
    &servicos[*contagemServicos].pontosNecessariosDesconto25,
    &servicos[*contagemServicos].pontosNecessariosDesconto50,
  ) == 7) {
    (*contagemServicos)++;
    if (servicos[*contagemServicos - 1].id >= *contagemIdServicos) {
      *contagemIdServicos = servicos[*contagemServicos - 1].id + 1;
    }
  }
  fclose(file);
  return *contagemServicos *contagemIdServicos;
}