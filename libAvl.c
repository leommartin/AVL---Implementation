/* 
    Implementação de Árvore AVL, feito por : Leonardo Martin
    Data: 14/07/2022.
    Funções que implementam e mantém Árvore AVL.    
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "libAvl.h"

tNo* criaNo(int valor)
{
    tNo *no = malloc(sizeof(tNo));
    
    if(no)
    {
        no->chave = valor;
        no->esq = NULL;
        no->dir = NULL;
        no->altura = 0;
    }
    else
        printf("\nErro ao alocar novo nó");

    return no;
}

int maior(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int alturaNo(tNo *no)
{
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

int fatorDeBalancemento(tNo *no)
{
    if(no)
        return ( alturaNo(no->esq) - alturaNo(no->dir) );
    else
        return 0;
}

tNo* rotacaoEsquerda(tNo *no1)
{
    tNo *no2, *no3;

    no2 = no1->dir;
    no3 = no2->esq;

    no2->esq = no1;
    no1->dir = no3;

    no1->altura = maior(alturaNo(no1->esq), alturaNo(no1->dir)) + 1;
    no2->altura = maior(alturaNo(no2->esq), alturaNo(no2->dir)) + 1;

    return no2;
}

tNo* rotacaoDireita(tNo *no1)
{
    tNo *no2, *no3;

    no2 = no1->esq; 
    no3 = no2->dir; 

    no2->dir = no1; 
    no1->esq = no3;

    no1->altura = maior(alturaNo(no1->esq), alturaNo(no1->dir)) + 1;
    no2->altura = maior(alturaNo(no2->esq), alturaNo(no2->dir)) + 1;

    return no2;
}

tNo* rotacaoEsquerdaDireita(tNo *no)
{
    no->esq = rotacaoEsquerda(no->esq);
    return rotacaoDireita(no);
}

tNo* rotacaoDireitaEsquerda(tNo *no)
{
    no->dir = rotacaoDireita(no->dir);
    return rotacaoEsquerda(no);
}

tNo* balancear(tNo *raiz)
{
    int fb = fatorDeBalancemento(raiz);

    if(fb < -1 && fatorDeBalancemento(raiz->dir) <= 0)
        raiz = rotacaoEsquerda(raiz);
    
    else if(fb > 1 && fatorDeBalancemento(raiz->esq) >= 0)
        raiz = rotacaoDireita(raiz);

    else if(fb > 1 && fatorDeBalancemento(raiz->esq) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    else if(fb < -1 && fatorDeBalancemento(raiz->dir) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

tNo* inserirAVL(tNo *no, int valor)
{
    if(no == NULL)
    {
        return criaNo(valor);
    }
    else
    {
        if(valor < no->chave)
            no->esq = inserirAVL(no->esq, valor);
        else if(valor > no->chave)
            no->dir = inserirAVL(no->dir, valor);
        else
            printf("Inserção da %d chave falhou! Chave existente \n", valor);
    }

    no->altura = maior(alturaNo(no->esq), alturaNo(no->dir)) + 1;
    
    no = balancear(no);

    return no; 
}

tNo* removerAVL(tNo* no, int valor)
{
    if(no == NULL)
        return NULL;
    else
    {
        if(no->chave == valor)
        {
            if( (no->esq == NULL) && (no->dir == NULL) )            
            {
                free(no);
                return NULL;    
            }
            else
            {
                if(no->esq != NULL && no->dir != NULL)
                {
                    tNo *no2 = no->esq;
                    
                    while(no2->dir != NULL)
                        no2 = no2->dir;
                    
                    no->chave = no2->chave;
                    no2->chave = valor;

                    no->esq = removerAVL(no->esq, valor);
                    return no;
                }
                else
                {
                    tNo *noAux;
                    if(no->esq != NULL)
                        noAux = no->esq;
                    else    
                        noAux = no->dir;
                    free(no);
                    return noAux;
                }
            }
        }
        else
        {
            if(valor < no->chave)
                no->esq = removerAVL(no->esq, valor);
            else
                no->dir = removerAVL(no->dir, valor);
        }
        
        no->altura = maior(alturaNo(no->esq), alturaNo(no->dir)) + 1;

        no = balancear(no);

        return no;
    }
}

void emOrdem_ArvBin(tNo *raiz, int altura)
{
    if(raiz == NULL)
        return;
    if(raiz != NULL)
    {
        emOrdem_ArvBin(raiz->esq, altura + 1);
        printf("%d,%d\n",raiz->chave, altura);
        emOrdem_ArvBin(raiz->dir, altura + 1);
    }
}

int alturaAVL(tNo *p)
{
    int he, hd;
    if (p == NULL) return -1;
    he = alturaNo (p->esq);
    hd = alturaNo (p->dir);
    if (he > hd)
        return he+1;
    else
        return hd+1;        
}

void imprimirAVL(tNo* raiz, int nivel)
{
    int i;

    if(raiz)
    {
        imprimirAVL(raiz->dir, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");
        
        printf("%d", raiz->chave);
        imprimirAVL(raiz->esq, nivel + 1);
    }
}