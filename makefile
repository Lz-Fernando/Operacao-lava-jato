CC = gcc
SRC = ./src/main.c ./src/menuPrincipal.c ./src/clientes.c ./src/funcionarios.c ./src/veiculos.c
OUT = programa.exe

all: 
	$(CC) $(SRC) -o $(OUT)
	@echo "Compilado com sucesso!"

run: all
	$(OUT)
	@echo "Executando o programa..."
	