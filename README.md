# minitalk

## Descrição

O **Minitalk** é um projeto que consiste na implementação de um sistema de comunicação entre processos em C, utilizando sinais Unix.'
O objetivo é enviar e receber mensagens de forma eficiente e entender melhor a comunicação entre processos, sinais, e conceitos como sincronização e manipulação de bits.

O projeto é dividido em dois programas:
- **Servidor**: Recebe mensagens do cliente e as exibe.
- **Cliente**: Envia mensagens para o servidor usando sinais.

## Estrutura do Projeto
Client.c # Código do cliente que envia a mensagem
Server.c # Código do servidor que recebe e exibe a mensagem
Minitalk.h # Cabeçalhos das funções utilizadas
Utils.c # Funções auxiliares (ex.: conversão de número para binário)
Makefile # Compila os executáveis do cliente e do servidor
README.md # Documentação do projeto

## Funcionalidades

- O **Cliente** converte cada caractere da mensagem em uma sequência de bits e envia ao **Servidor** usando os sinais `SIGUSR1` e `SIGUSR2`.
- O **Servidor** interpreta esses sinais, reconstrói a mensagem original e a exibe no terminal.
- A comunicação é feita de forma unidirecional, do cliente para o servidor.
  
## Requisitos

- O projeto deve ser implementado em C e funcionar no ambiente Unix.

## Instalação

Para compilar o projeto, clone o repositório e execute o comando `make`:

```bash
git clone https://github.com/Aurorasimao4/minitalk.git
cd minitalk
make
```
## Execução do server
```bash
./server
```
## Execução do client
```bash
./client PID "mensagem"
```


