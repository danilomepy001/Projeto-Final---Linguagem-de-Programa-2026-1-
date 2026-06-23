#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefas.h"

// 16 - Cadastro de tarefas (nome, descrição, data de conclusão, prioridade (Adicionar campo id para remover tarefa))

// criaão da lista encadeada aqui, seguindo slide do maikon

typedef struct No {
    Tarefas tarefas;
    struct No *proximaTarefa;
} No;

// acessar a lista encadeada
No *listaEncadeada = NULL;

// essa função lê o arquivo salvo e joga na memoria ram
void lerArquivo(){
    printf("Lendo o arquivo das tarefas\n");
}

void salvarArquivo(){
    printf("Salvando o arquivo das tarefas\n");
}

// essa função imprime todas as tarefas (opção 1 do menu)
void imprimirTarefas(){
    printf("\n ----- Lista de Tarefas -----");
}

// essa função adiciona uma nova tarefa na lista (opção 2 do menu)
void registrarNovaTarefa(){
    printf("\nAdicionar Novar Tarefa na Lista\n");

    No *novo = malloc(sizeof(No));

    printf("Digite o ID: ");
    scanf("%d", &novo->tarefas.id);
}

// essa função excluir uma tarefa por meio do id dela (opção 3 do menu)
void excluirTarefa(){
    printf("Digite o id da tarefa para excluir");
}

void opcaoTarefas() { // Função para chamar o Menu Principal do Programa
    int opcao;

    do {
        printf("\n ----- Menu Principal ----- \n");
        printf("1. Imprimir Lista de Tarefas \n");
        printf("2. Registrar Nova Tarefa \n");
        printf("3. Excluir Tarefa \n");
        printf("0. Sair \n");
        printf("Escolha uma Opção: ");
        scanf("%d", opcao);

        switch(opcao) {
            case 1: 
                imprimirTarefas();
                break;
            
            case 2:
                registrarNovaTarefa();
                break;

            case 3: 
                excluirTarefa();
                break;

            case 0:
                printf("\nSaindo...");
                break;

            default:
                printf("\nOpção Invalida!");
        }
    } while (opcao != 0);
}

int main(){
    lerArquivo(); // primeiro item a ser iniciado
    opcaoTarefas(); // pergunta ao usuario o que ele quer fazer
    salvarArquivo(); // salva tudo no final
}