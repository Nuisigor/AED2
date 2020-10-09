#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum no{
    raiz,
    esq,
    dir
}no;

ABB* ABB_Criar(int chave, ABB* e, ABB* d){
    ABB* a = malloc(sizeof(ABB));

    a->chave = chave;
    a->direita = d;
    a->esquerda = e;
    return a;
}

void ABB_Inserir(ABB **A, int chave){
    if((*A) == NULL){
        *A = ABB_Criar(chave, NULL, NULL);
        return;
    }
    else{
        if((*A)->chave < chave)
            ABB_Inserir(&(*A)->direita, chave);
        else
            ABB_Inserir(&(*A)->esquerda, chave);
    }
}

ABB* ABB_Buscar(ABB *A, int chave){
    if(A == NULL)
        return NULL;
    if(A->chave == chave)
        return A;
    if(A->chave > chave)
        return ABB_Buscar(A->esquerda, chave);
    return ABB_Buscar(A->direita, chave);
}

void ABB_Imprimir1(ABB* A, int profundidade, no n){
    if(A == NULL)  
        return;
    char c = n == raiz ? 'r' : (n == esq ? 'e' : 'd');
    int i;
    for(i = 0; i < profundidade; i++){
        printf("\t");
    }

    printf("(%c) %d\n",c, A->chave);
    ABB_Imprimir1(A->esquerda, profundidade + 1, esq);
    ABB_Imprimir1(A->direita, profundidade + 1, dir);
}


void ABB_Imprimir(ABB* A){
    ABB_Imprimir1(A, 0, raiz);
}

ABB* ABB_Busca_Pai(ABB* A, int chave, ABB* chav){
    if(A->direita == chav || A->esquerda == chav)
        return A;
    if(A->chave > chave)
        return ABB_Busca_Pai(A->esquerda, chave, chav);
    return ABB_Busca_Pai(A->direita, chave, chav);
}

int ABB_Busca_Sucessor(ABB* A){
    if(A->esquerda == NULL)
        return A->chave;
    return ABB_Busca_Sucessor(A->esquerda);
}

void ABB_Remover(ABB **A, int chave){
    ABB* aux = ABB_Buscar((*A), chave);
    ABB* aux2;

    if(aux == NULL)
        return;

    // Nó folha
    if(aux->direita == NULL && aux->esquerda == NULL){
        aux2 = ABB_Busca_Pai((*A), chave, aux);
        if(aux2->direita == aux)
            aux2->direita = NULL;
        if(aux2->esquerda == aux)
            aux2->esquerda = NULL;
        free(aux);
        return;
    }
    //Nó com um filho
    if(aux->direita == NULL || aux->esquerda == NULL){
        aux2 = ABB_Busca_Pai((*A), chave, aux);
        if(aux2->direita == aux){
            if(aux->direita != NULL)
                aux2->direita = aux->direita;
            else
                aux2->direita = aux->esquerda;
        }
        else{
            if(aux->direita != NULL)
                aux2->esquerda = aux->direita;
            else
                aux2->esquerda = aux->esquerda;
        }
        free(aux);
        return;
    }
    // Nó com 2 filhos
    int auxi = ABB_Busca_Sucessor(aux->direita);
    ABB_Remover(&aux, auxi);
    aux->chave = auxi;
}