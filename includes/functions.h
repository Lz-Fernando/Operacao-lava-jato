#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// FUNCTIONS

// MENU PRINCIPAL
void menuPrincipal();
void executarMenuPrincipal();

// CLIENTES
void menuClientes();
void executarMenuClientes();
void cadastrarCliente(Cliente clientes[], int *contagemIdEndereco, int *contagemClientes);
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

// SERIVIÇOS
void menuServicos();

// RELATORIOS
void menuRelatorios();

#endif // FUNCTIONS_H