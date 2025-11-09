#pragma once
#define TAMANHO_MAXIMO 10

typedef struct
{
    int itens[TAMANHO_MAXIMO];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

void FilaCircular_inicializar(FilaCircular* fila);
int FilaCircular_estaVazia(FilaCircular* fila);
int FilaCircular_estaCheia(FilaCircular* fila);
void FilaCircular_enqueue(FilaCircular* fila, int valor);
int FilaCircular_dequeue(FilaCircular* fila);
int FilaCircular_peek(FilaCircular* fila);
