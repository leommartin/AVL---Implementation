/* 
    Implementação de Árvore AVL, feito por : Leonardo Martin.
    Data: 14/07/2022.
    Estruturas e funções para Implementação de Árvore AVL.  
*/ 

typedef struct no{
    int chave;
    struct no *esq, *dir;
    int altura;
}tNo;

tNo* inserirAVL(tNo *no, int valor);

tNo* removerAVL(tNo* no, int valor);

void imprimirAVL(tNo* raiz, int nivel);

void emOrdem_ArvBin(tNo *raiz, int altura);

int alturaAVL(tNo *p);