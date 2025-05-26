# Operação Lava Jato - Sistema de Gerenciamento

Este projeto é um sistema de gerenciamento para um lava jato, desenvolvido em C, com foco em modularidade, organização e facilidade de manutenção. Ele permite o cadastro, edição, exclusão, listagem e busca de clientes, veículos, funcionários, serviços, agendamentos, pagamentos e geração de relatórios.

---

## 📁 Estrutura do Projeto

```
Operacao-lava-jato/
│
├── includes/           # Arquivos de cabeçalho (.h)
│   ├── structs.h       # Definições de structs usadas em todo o sistema
│   └── functions.h     # Declaração de todas as funções globais
│
├── src/                # Arquivos de implementação (.c)
│   ├── main.c                  # Função principal e início do programa
│   ├── menuPrincipal.c         # Menus principais e navegação
│   ├── clientes.c              # Gerenciamento de clientes
│   ├── veiculos.c              # Gerenciamento de veículos
│   ├── funcionarios.c          # Gerenciamento de funcionários
│   ├── servicos.c              # Gerenciamento de serviços
│   ├── agendamentos.c          # Gerenciamento de agendamentos
│   ├── pagamentos.c            # Gerenciamento de pagamentos
│   ├── relatorios.c            # Geração de relatórios
│   └── ... (outros módulos)
│
├── Makefile            # Script para compilação automatizada
├── README.md           # Documentação do projeto
└── arquivos.txt/bin    # (opcional) Arquivos de dados para persistência
```

---

## 🚀 Como compilar e executar

O projeto utiliza um Makefile para facilitar a compilação.

**Pré-requisitos:**
- [GCC](https://www.mingw-w64.org/) instalado (no Windows, use MinGW ou WSL)
- [make](https://www.mingw-w64.org/) instalado (no Windows, use MinGW ou Git Bash)

**Para compilar e executar:**

No terminal, dentro da pasta do projeto, execute:
```sh
mingw32-make run
```
Isso irá compilar todos os arquivos, gerar o executável `programa.exe` e executá-lo.

**Para compilar apenas:**
```sh
mingw32-make
```

**Para limpar os arquivos gerados:**
```sh
mingw32-make clean
```

---

## 🧩 Organização dos Arquivos

- **includes/structs.h**  
  Contém todas as definições de structs usadas no sistema, como `Cliente`, `Funcionario`, `Veiculo`, `Servico`, `Endereco`, etc.

- **includes/functions.h**  
  Declaração de todas as funções globais do sistema. Sempre que criar uma nova função que será usada em mais de um arquivo, declare aqui.

- **src/main.c**  
  Função principal (`main`). Responsável por iniciar o programa e chamar o menu principal.

- **src/menuPrincipal.c**  
  Implementação do menu principal e navegação entre os módulos do sistema.

- **src/clientes.c**  
  Funções para cadastro, edição, exclusão, busca e listagem de clientes.

- **src/veiculos.c**  
  Funções para cadastro, edição, exclusão, busca e listagem de veículos.

- **src/funcionarios.c**  
  Funções para cadastro, edição, promoção, demissão, busca e listagem de funcionários.

- **src/servicos.c**  
  Funções para cadastro, edição, execução, busca e listagem de serviços.

- **src/agendamentos.c**  
  Funções para agendar, editar, cancelar e listar agendamentos.

- **src/pagamentos.c**  
  Funções para registrar, editar e listar pagamentos.

- **src/relatorios.c**  
  Funções para geração de relatórios do sistema.

- **Makefile**  
  Script para automatizar a compilação e execução do projeto.

---

## 🔄 Fluxo de Funcionamento

1. **Inicialização:**  
   O programa inicia em `main.c` e chama o menu principal.

2. **Navegação:**  
   O usuário escolhe entre os módulos: clientes, veículos, funcionários, serviços, agendamentos, pagamentos ou relatórios.

3. **Operações em cada módulo:**  
   - **Cadastrar:** Adiciona um novo registro ao array correspondente e salva no arquivo.
   - **Editar:** Busca um registro pelo identificador (CPF, placa, ID, etc.), permite alteração e salva a atualização.
   - **Excluir:** Remove um registro do array e atualiza o arquivo.
   - **Listar:** Exibe todos os registros do módulo.
   - **Buscar:** Localiza um registro específico para edição ou exclusão.

4. **Relatórios:**  
   Geração de relatórios de clientes, funcionários, serviços realizados, agendamentos e pagamentos.

---

## 💾 Persistência de Dados

- O sistema utiliza arquivos para armazenar os dados de clientes, veículos, funcionários, serviços, agendamentos e pagamentos.
- Ao iniciar, o programa lê os arquivos e carrega os dados para os arrays em memória.

---

## ➕ Adicionando Novos Arquivos/Funções

1. Crie o novo arquivo `.c` na pasta `src/`.
2. Adicione o nome do novo arquivo na variável `SRC` do `Makefile`.
3. Se criar um novo `.h`, coloque na pasta `includes/` e inclua nos arquivos `.c` necessários.
4. Declare novas funções em `functions.h` e implemente no `.c` correspondente.

---

## 📝 Dicas e Boas Práticas

- **Sempre compile usando o `make`** para garantir que todas as dependências sejam atualizadas.
- **Declare novas structs e funções nos arquivos `.h`** para facilitar a reutilização e modularização.
- **Mantenha o código organizado** em módulos, cada um responsável por uma parte do sistema.
- **Comente o código** para facilitar a manutenção e entendimento por outros desenvolvedores.

---