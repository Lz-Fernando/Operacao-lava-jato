#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// FUNCTIONS

// MENU PRINCIPAL
void menuPrincipal();
void executarMenuPrincipal();

// CLIENTES
void menuClientes();
void executarMenuClientes();
void cadastrarCliente(Cliente clientes[], int *contagemClientes);
void editarCadastroCliente();
void printClientes();
Cliente* buscaClientePorCPF(void);
void excluirClientePorCPF();
void listarClientes();

// VEICULOS
void menuVeiculos();
void executarMenuVeiculos();
void cadastrarVeiculo(Veiculo veiculos[], int *contagemVeiculos);
void editarCadastroVeiculo();
void printVeiculos();
Veiculo* buscaVeiculoPorPlaca(void);
void excluirVeiculoPorPlaca();
void listarVeiculos();

// FUNCIONARIOS
void menuFuncionarios();
void executarMenuFuncionarios();
void cadastrarFuncionario(Funcionario funcionarios[], int *contagemFuncionarios);
void editarCadastroFuncionario();
void printFuncionarios();
Funcionario* buscaFuncionarioPorCPF(void);
void demitirFuncionarioPorCPF();
void listarFuncionarios();
void aplicarPromocaoFuncionario();

// SERVIÇOS
void menuServicos();
void executarMenuServicos();
void cadastrarServico(Servico servicos[], int *contagemServicos, int *contagemIdServicos);
void editarCadastroServico();
void printServicos();
Servico* buscaServicoPorId(void);
void excluirServicoPorId();
void listarServicos();

// DATA E HORA
void preencherDataHora(DataHora *dataHora);

// AGENDAMENTOS
void menuAgendamentos();
void executarMenuAgendamentos();
void cadastrarAgendamento(Agendamento agendamentos[], int *contagemAgendamentos);
void editarCadastroAgendamento();
void excluirAgendamentoPorID();
void listarAgendamentos();
void alterarStatusAgendamento();
Agendamento* buscaAgendamentoPorId(void);

// RELATORIOS
void menuRelatorios();
void executarMenuRelatorios();
void relatorioCliente(Cliente clientes[], int qtdClientes, Agendamento agendamentos[], int qtdAgendamentos);

// CARREGAR DADOS
int carregarClientes(Cliente clientes[], int *contagemClientes);
int carregarVeiculos(Veiculo veiculos[], int *contagemVeiculos, Cliente clientes[], int *contagemClientes);
int carregarFuncionarios(Funcionario Funcionarios[], int *contagemFuncionarios);
int carregarServicos(Servico servicos[], int *contagemServicos, int *contagemIdServicos);

// PAGAMENTOS
void menuPagamentos();
void executarMenuPagamentos();
void cadastrarPagamento(void);
void listarPagamentos(void);
void alterarStatusPagamento(void);

#endif // FUNCTIONS_H
