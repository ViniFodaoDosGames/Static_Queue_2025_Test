#include "Static_Queue.h"
#include <stdio.h>

void FilaCircular_inicializar(FilaCircular* fila)
{
    for(int i = 0; i< TAMANHO_MAXIMO; i++)
    {
        fila->itens[i] = 0;
    }
    fila->inicio=0;
    fila->fim=0;
    fila->quantidade=0;
}

int FilaCircular_estaVazia(FilaCircular* fila)
{
    if(fila->quantidade==0)
        return 1;
    else
        return 0;
}

int FilaCircular_estaCheia(FilaCircular* fila)
{
    if(fila->quantidade==TAMANHO_MAXIMO)
        return 1;
    else
        return 0;
}

void FilaCircular_enqueue(FilaCircular* fila, int valor)
{
    if(!FilaCircular_estaCheia(fila))
    {
        fila->itens[fila->fim]=valor;
        fila->fim = (fila->fim+1)%TAMANHO_MAXIMO;
        fila->quantidade+=1;
    }else
        return;
}

int FilaCircular_dequeue(FilaCircular* fila)
{
    if(!FilaCircular_estaVazia(fila))
    {
        int retorno = fila->itens[fila->inicio];
        fila->itens[fila->inicio]=0;
        fila->inicio = (fila->inicio+1)%TAMANHO_MAXIMO;
        fila->quantidade-=1;
        return retorno;
    }
    else
        return 0;
}

int FilaCircular_peek(FilaCircular* fila)
{
    if(!FilaCircular_estaVazia(fila))
    {
        return fila->itens[fila->inicio];
    }
    else
    {
        return 0;
    }
}
