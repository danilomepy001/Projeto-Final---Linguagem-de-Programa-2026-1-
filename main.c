#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 16 - Cadastro de tarefas (nome, descrição, data de conclusão, prioridade (Adicionar campo id para remover tarefa))

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

                break;
            
            case 2:

                break;

            case 3: 

                break;

            case 0:
                printf("\nSaindo...");
                break;

            default:
                printf("\nOpção Invalida!");
        }
    } while (opcao != 0);
}