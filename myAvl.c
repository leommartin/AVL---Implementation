/* 
    Implementação de Árvore AVL, feito por : Leonardo Martin
    Data: 14/07/2022.
    Testa implementação e manutenção da Árvore AVL.
    (Inclusão, Remoção e Balanceamento por meio de Rotações)  
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "libAvl.h"

int main()
{
    char op;
    int  valor, altura, altAvl;

    tNo *raiz = NULL;

    while(scanf("%c %d\n", &op, &valor) != EOF)
    {
        if(op == 'i')
            raiz = inserirAVL(raiz, valor);
        else if(op == 'r')
            raiz = removerAVL(raiz, valor); 

        imprimirAVL(raiz, 1); printf("\n\n:Demarcador de passo\n"); // Descomente para imprimir a árvore passo a passo         
    }

    altura = 0;
    emOrdem_ArvBin(raiz, altura);

    altAvl = alturaAVL(raiz);

    printf("A altura da árvore Avl é: %d.", altAvl);
}
