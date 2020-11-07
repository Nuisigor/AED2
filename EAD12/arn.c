#include "arn.h"
#include <stdio.h>
#include <stdlib.h>

ARN* ARN_Criar(int chave, int valor){
    ARN* novo = malloc(sizeof(ARN));
    novo->chave = chave;
    novo->valor = valor;
    novo->dir = novo->esq = NULL;
    novo->cor = C_VERMELHO;

    return novo;
}

static inline int eh_vermelho(ARN *A){
    if(A == NULL)
        return 0;
    
    return A->cor == C_VERMELHO ? 1 : 0;
}

static void inverter_cores(ARN *A){
    A->cor = C_VERMELHO;
    A->dir->cor = C_PRETO;
    A->esq->cor = C_PRETO;
}

static void rot_esq(ARN **A){
    ARN *h, *x;
    h = *A;
    x = h->dir;

    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

static void rot_dir(ARN **A){
    ARN *h, *x;
    h = *A;
    x = h->esq;

    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

void ARN_Inserir_R(ARN** A, int chave, int valor){
    if((*A) == NULL){
        *A = ARN_Criar(chave,valor);
    }
    
    if(chave < (*A)->chave)
        ARN_Inserir_R(&(*A)->esq, chave, valor);

    if(chave > (*A)->chave)
        ARN_Inserir_R(&(*A)->dir, chave, valor);

    if(eh_vermelho((*A)->dir) && !eh_vermelho((*A)->esq)){
        rot_esq(A);
    }
    if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->esq->esq)){
        rot_dir(A);
    }
    if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->dir)){
        inverter_cores(*A);
    }
}

void ARN_Inserir(ARN** A, int chave, int valor){
    ARN_Inserir_R(A, chave, valor);
    (*A)->cor = C_PRETO;
}


static int ARN_Sort_R(ARN* A, int *v, int n){
    if(A->esq != NULL)
        n = ARN_Sort_R(A->esq, v, n);
    v[n] = A->chave;
    n++;
    if(A->dir != NULL)
        n = ARN_Sort_R(A->dir, v, n);
    free(A);
    return n;
}

int ARN_Sort(int* v, int n){
    int i;
    ARN* A = NULL;
    for(i = 0; i < n; i++){
        ARN_Inserir(&A, v[i],v[i]);
    }
    i = ARN_Altura(A);
    printf("Altura ARN = %d\n",i);
    ARN_Sort_R(A, v, 0);
    return i;
}

int ARN_Altura(ARN *A){
    int n = !eh_vermelho(A);
    int m = !eh_vermelho(A);

    if(A->esq != NULL)
        n += ARN_Altura(A->esq);
    if(A->dir != NULL)
        m += ARN_Altura(A->dir);
    if(n > m)
        return n;
    return m;
}