#ifndef STRUCTS_H
#define STRUCTS_H

// STRUCTS
typedef struct {
    int dia;
    int mes;
    int ano;
    char hora[6];
} DataHora;

typedef struct {
    int id;
    char rua[50];
    char bairro[30];
    char cidade[30];
    char estado[30];
    char cep[10];
    int numero;
} Endereco;

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float desconto;
    int pontosAcumulados;
    int pontosResgatados;
    int pontosAtuais;
} PlanoFidelidade;

typedef struct {
    char cpf[15];
    char nome[50];
    char telefone[15];
    char email[50];
    Endereco endereco;
    char plano[15];
} Cliente;

typedef struct {
    char placa[10];
    char modelo[30];
    char marca[30];
    char tipo[20];
    int ano;
    char cor[20];
    Cliente cliente;
} Veiculo;

typedef struct {
    int id;
    char tipo[30];
    int duracao;
    float preco;
    int pontosGerados;
    int pontosNecessarios;
} Servico;

typedef struct {
    int id;
    char nome[50];
    char cargo[30];
    char telefone[15];
    float salario;
} Funcionario;

typedef struct {
    int id;
    Cliente cliente;
    Veiculo veiculo;
    Servico servico;
    DataHora dataHora;
    char status[20];
} Agendamento;

typedef struct {
    float valor;
    char formaPagamento[20];
    char status[20];
    Agendamento agendamento;
} Pagamento;

typedef struct {
    int id;
    Funcionario funcionario;
    Servico servico;
    Veiculo veiculo;
    DataHora data;
    char observacoes[100];
} RegistroServico;

#endif // STRUCTS_H