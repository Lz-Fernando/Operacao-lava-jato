#include <stdio.h>
#include <string.h>
#include "../includes/structs.h"
#include "../includes/functions.h"

extern Cliente clientes[];
extern int contagemClientes;
extern Agendamento agendamentos[];
extern int contagemAgendamentos;

void menuRelatorios() {
  printf("\n===== Menu de Relatórios =====\n");
  printf("1. Relatório por CPF do cliente\n");
  printf("2. Voltar ao menu principal\n");
  printf("Escolha uma opção: ");   
}

void executarMenuRelatorios() {
  int opcao;
  do {
    menuRelatorios();
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        relatorioCliente(clientes, contagemClientes, agendamentos, contagemAgendamentos);
        break;
      case 2:
        executarMenuPrincipal();
        break;
      default:
        printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao != 2);
}

// Relatório detalhado do cliente e seus agendamentos realizados
void relatorioCliente(Cliente clientes[], int contagemClientes, Agendamento agendamentos[], int contagemAgendamentos) {
  char cpfBusca[15];
  int encontrou = 0;
  printf("\nDigite o CPF do cliente: ");
  scanf("%s", cpfBusca);

  for (int i = 0; i < contagemClientes; i++) {
    if (strcmp(clientes[i].cpf, cpfBusca) == 0) {
      encontrou = 1;
      printf("\n===== Dados do Cliente =====\n");
      printf("CPF: %s\n", clientes[i].cpf);
      printf("Nome: %s\n", clientes[i].nome);
      printf("Telefone: %s\n", clientes[i].telefone);
      printf("Email: %s\n", clientes[i].email);
      printf("Plano: %s\n", clientes[i].plano);
      printf("Endereço: %s, %s, %s, %s, %s, %d\n",
        clientes[i].endereco.rua,
        clientes[i].endereco.bairro,
        clientes[i].endereco.cidade,
        clientes[i].endereco.estado,
        clientes[i].endereco.cep,
        clientes[i].endereco.numero
      );

      printf("\n--- Agendamentos realizados pelo cliente ---\n");
      int agendamentosEncontrados = 0;
      for (int j = 0; j < contagemAgendamentos; j++) {
        if (strcmp(agendamentos[j].cliente.cpf, cpfBusca) == 0) {
          agendamentosEncontrados = 1;
          printf("Data: %02d/%02d/%04d %02d:%02d\n",
            agendamentos[j].dataHora.dia,
            agendamentos[j].dataHora.mes,
            agendamentos[j].dataHora.ano
          );
          printf("Serviço: %s\n", agendamentos[j].servico.nome);
          printf("Funcionário responsável: %s\n", agendamentos[j].funcionario.nome);
          printf("Veículo: %s (%s)\n", agendamentos[j].veiculo.modelo, agendamentos[j].veiculo.placa);
          printf("Status: %s\n", agendamentos[j].status);
          printf("-----------------------------\n");
        }
      }
      if (!agendamentosEncontrados) {
        printf("Nenhum agendamento realizado por este cliente.\n");
      }
      break;
    }
  }
  if (!encontrou) {
    printf("Cliente não encontrado.\n");
  }
}