CC = gcc
SRC = ./src/main.c ./src/menuPrincipal.c ./src/clientes.c ./src/funcionarios.c ./src/veiculos.c ./src/servicos.c ./src/agendamentos.c ./src/datahora.c ./src/carregarDados.c ./src/pagamentos.c
OUT = programa.exe

all: 
	$(CC) $(SRC) -o $(OUT)
	@echo "Compilado com sucesso!"

run: all
	$(OUT)
	@echo "Executando o programa..."
	
