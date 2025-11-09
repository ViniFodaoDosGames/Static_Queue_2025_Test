#include "Static_Queue.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int validacaoPonteiro(void* p);
void validacaoFila(FilaCircular* p);
void adicionarPessoa(FilaCircular* p);
void lista_elementos(FilaCircular* fila);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FilaCircular Atendimento;
    FilaCircular* p_Atendimento = &Atendimento;
    FilaCircular_inicializar(p_Atendimento);
    if(!validacaoPonteiro(p_Atendimento))
    {
        return 1;
    }

//    lista_elementos(p_Atendimento);
    int controle;
    do
    {
        printf("\n\t|============== Sistema bobinho de Atendimento ==============|\n\n");
        printf("(1)Adicionar pessoa à fila\n");
        printf("(2)Atender proxima pessoa\n");
        printf("(3)Ver pessoa atual\n");
        printf("(0)Sair do programa\n");
        printf("\n");
        scanf("%d", &controle);
        switch (controle)
        {
        case 1:
            if(!FilaCircular_estaCheia(p_Atendimento))
            {
                adicionarPessoa(p_Atendimento);
            }
            else
            {
                system("cls");
            }
            break;
        case 2:
            if(!FilaCircular_estaVazia(p_Atendimento))
            {
                system("cls");
                FilaCircular_dequeue(p_Atendimento);
            }
            else
            {
                system("cls");
            }

            break;
        case 3:
            system("cls");
            printf("\nPessoa atual: %d\n", FilaCircular_peek(p_Atendimento));
            break;
        default:
            break;
        }
        //lista_elementos(p_Atendimento);
    }
    while(controle!=0);
    return 0;
}

int validacaoPonteiro(void* p)
{
    if(p!=NULL)
        return 1;
    else
        return 0;
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
void adicionarPessoa(FilaCircular* p)
{
    int id_num;
    system("cls");
    printf("\t|============== Sistema bobinho de Atendimento ==============|\n\n");
    printf("Informe o número de identificação: ");
    scanf("%d",&id_num);
    FilaCircular_enqueue(p, id_num);
    system("cls");
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
