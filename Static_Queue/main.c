#include "Static_Queue.h"
#include <stdio.h>
#include <locale.h>

void lista_elementos(FilaCircular* fila);
void validacaoPonteiro(void* p);
void validacaoFila(FilaCircular* p);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    FilaCircular estrutura;
    FilaCircular* ponteiro_estrutura=&estrutura;
    validacaoPonteiro(ponteiro_estrutura);

    FilaCircular_inicializar(ponteiro_estrutura);
    lista_elementos(ponteiro_estrutura);
    validacaoFila(ponteiro_estrutura);


    for(int i=0; i<TAMANHO_MAXIMO; i++)
    {
        FilaCircular_enqueue(ponteiro_estrutura, i+1);
    }
    lista_elementos(ponteiro_estrutura);
    validacaoFila(ponteiro_estrutura);

    for(int i=0; i<5; i++)
    {
        FilaCircular_dequeue(ponteiro_estrutura);
    }
    lista_elementos(ponteiro_estrutura);
    validacaoFila(ponteiro_estrutura);

    for(int i=0; i<TAMANHO_MAXIMO; i++)
    {
        FilaCircular_enqueue(ponteiro_estrutura, i+5);
    }
    lista_elementos(ponteiro_estrutura);
    validacaoFila(ponteiro_estrutura);

    return 0;
}

void validacaoPonteiro(void* p)
{
    if(p==NULL)
        printf("\n\tPointer = NULL\n\n");
    else
        printf("\n\tPointer = NOT NULL\n\n");
}

void validacaoFila(FilaCircular* p)
{
    if(FilaCircular_estaVazia(p))
        printf("\n\tEstá VAZIA\n");
    else
        printf("\n\tNÃO está VAZIA\n");

    if(FilaCircular_estaCheia(p))
        printf("\n\tEstá CHEIA\n");
    else
        printf("\n\tNÃO está CHEIA\n");

    printf("\n\tValor no Peek: %d\n\n",FilaCircular_peek(p));
}

void lista_elementos(FilaCircular* fila)
{
    printf("\n==========Fila Atual==========\n");
    for(int i = 0; i < TAMANHO_MAXIMO; i++)
    {
        printf("-");
        printf("|%d|", fila->itens[i]);
        printf("-");
    }
    printf("\nInicio: %d", fila->inicio);
    printf("\nFim: %d", fila->fim);
    printf("\nQuantidade: %d", fila->quantidade);
    printf("\n\n");
}
