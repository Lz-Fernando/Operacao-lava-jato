# Operação Lava Jato - Sistema de Gerenciamento

## Estrutura do Projeto

```
Operacao-lava-jato/
│
├── includes/           # Arquivos de cabeçalho (.h)
│   ├── structs.h
│   └── functions.h
│
├── src/                # Arquivos de implementação (.c)
│   ├── main.c
│   ├── menuPrincipal.c
│   └── clientes.c
│   └── ... (outros arquivos .c)
│
├── Makefile            # Script de compilação automatizada
└── README.md           # Este arquivo de documentação
```

## Como compilar e executar

O projeto utiliza um Makefile para facilitar a compilação.  
**Pré-requisito:** Ter o `make` e o `gcc` instalados (no Windows, use o [MinGW](https://www.mingw-w64.org/)).

No terminal, dentro da pasta do projeto, execute:

```sh
mingw32-make run
```

Isso irá compilar todos os arquivos, gerar o executável `programa.exe` e o executar.


## Adicionando novos arquivos

1. Crie o novo arquivo `.c` na pasta `src/`.
2. Adicione o nome do novo arquivo na variável `SRC` do `Makefile`.
3. Se criar um novo `.h`, coloque na pasta `includes/` e inclua nos arquivos `.c` necessários.

## Estrutura dos arquivos

- **includes/structs.h**: Define todas as structs usadas no sistema (ex: `Cliente`, `Endereco`, etc).
- **includes/functions.h**: Declaração das funções globais. Inclua todas as funções aqui.
- **src/main.c**: Função principal do programa.
- **src/menuPrincipal.c**: Implementação do menu principal e menus auxiliares.
- **src/clientes.c**: Funções relacionadas ao gerenciamento de clientes.

## Fluxo básico do sistema

1. O programa inicia em `main.c` e chama o menu principal.
2. O usuário escolhe uma opção e navega pelos menus (clientes, veículos, funcionários, etc).
3. Cada módulo possui funções para cadastrar, editar, excluir e listar registros.

## Dicas

- Sempre compile usando o `make` para garantir que todas as dependências sejam atualizadas.
- Se adicionar novas structs ou funções, lembre-se de declarar no `.h` correspondente.
- Para limpar o executável gerado, use:
  ```sh
  mingw32-make clean
  ```

---