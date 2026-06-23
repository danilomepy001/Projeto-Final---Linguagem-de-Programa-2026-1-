#ifndef TAREFAS_H
#define TAREFAS_H

typedef struct Tarefas {
    int id;
    char nome[50];
    char descricao[100];
    char data_conclusao[10];
    int prioridade;
} Tarefas;
#endif