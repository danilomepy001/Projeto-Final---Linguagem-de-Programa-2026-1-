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
    printf("\nLendo o arquivo das tarefas\n");

    FILE *f = fopen("tarefas.bin", "rb");
    if (f == NULL) {
        return; 
    }

    Tarefas t_temp;
    while (fread(&t_temp, sizeof(Tarefas), 1, f) == 1) {
        No *novo = malloc(sizeof(No));
        novo->tarefas = t_temp;
        novo->proximaTarefa = listaEncadeada;
        listaEncadeada = novo;
    }

    fclose(f);
}

void salvarArquivo(){

    FILE *f = fopen("tarefas.bin", "wb");
    if (f == NULL) {
        printf("\nErro ao criar o arquivo de salvamento\n");
        return;
    }

    No *atual = listaEncadeada;
    while (atual != NULL) {
        fwrite(&atual->tarefas, sizeof(Tarefas), 1, f);
        atual = atual->proximaTarefa;
    }

    fclose(f);
    printf("Arquivo tarefas.bin salvo com sucesso\n");
}

// essa função imprime todas as tarefas (opção 1 do menu)
void imprimirTarefas(){
    printf("\n ----- Lista de Tarefas ----- \n");

    No *atual = listaEncadeada;

    // Verifica se a lista está vazia, se for true, retorna ao menu principal 
    if (atual == NULL) {
        printf("Nao existe nenhuma tarefa cadastrada\n");
        return;
    }
    // Utilização do while para mostrar todas as tarefas 
    while (atual != NULL) {
        printf("ID: %d | Nome: %s | Prioridade: %d\n", atual->tarefas.id, atual->tarefas.nome, atual->tarefas.prioridade);
        printf("Descricao: %s\n", atual->tarefas.descricao);
        printf("Data de Conclusao: %s\n", atual->tarefas.data_conclusao);

        atual = atual->proximaTarefa;
    }

}

// essa função adiciona uma nova tarefa na lista (opção 2 do menu)
void registrarNovaTarefa(){
    printf("\n----- Adicionar Novar Tarefa na Lista -----\n");

    No *novo = malloc(sizeof(No));

    printf("\nDigite o ID: ");
    scanf("%d", &novo->tarefas.id);

    printf("\nDigite o nome: ");
    scanf(" %[^\n]", novo->tarefas.nome);

    printf("\nDigite a descrição: ");
    scanf(" %[^\n]", novo->tarefas.descricao);

    printf("\nDigite a data de conclusao: ");
    scanf(" %[^\n]", novo->tarefas.data_conclusao);

    printf("\nPrioridades: 1 - Urgente; 2 - Alta; 3 - Media; 4 - Baixa");
    printf("\nDigite a prioridade de 1 a 4: ");
    scanf("%d", &novo->tarefas.prioridade);

    novo->proximaTarefa = listaEncadeada;
    listaEncadeada = novo;
}

// essa função excluir uma tarefa por meio do id dela (opção 3 do menu)
void excluirTarefa(){

    int id_busca;

    if (listaEncadeada == NULL) {
        printf("A lista esta vazia\n");
        return;
    }

    printf("Digite o ID da tarefa que deseja remover: ");
    scanf("%d", &id_busca);

    No *atual = listaEncadeada;
    No *anterior = NULL;

    // aqui procura o id da tarefa
    while (atual != NULL && atual->tarefas.id != id_busca) {
        anterior = atual;       
        atual = atual->proximaTarefa;
    }

    // se não encontra o id no loop, ele encerra a busca
    if (atual == NULL) {
        printf("Tarefa com ID %d nao encontrada.\n", id_busca);
        return;
    }

    // se o id removido for o primeiro, ele passa a primeira posição para o segundo
    if (anterior == NULL) {
        listaEncadeada = atual->proximaTarefa;
    } else {
        // se o id for o do meio, ele junta 
        anterior->proximaTarefa = atual->proximaTarefa;
    }

    // libera a memoria
    free(atual); 
    printf("Tarefa removida com sucesso!\n");
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
        scanf("%d", &opcao);

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
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção Invalida!\n");
        }
    } while (opcao != 0);
}

int main(){
    lerArquivo(); // primeiro item a ser iniciado
    opcaoTarefas(); // pergunta ao usuario o que ele quer fazer
    salvarArquivo(); // salva tudo no final

    return 0;
}