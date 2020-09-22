#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "hash.h"

THED* THED_Criar(int m, int alloc_step){
    int i;
    THED* th = malloc(sizeof(THED));
    th->m = m;
    th->t = malloc(sizeof(ILIST*)*m);
    for(i = 0; i < m; i++)
        th->t[i] = ILIST_Criar(alloc_step);
    
    return th;
}

int THED_Hash(THED* TH, int chave){
    return chave % TH->m;
}

void THED_Inserir(THED* TH, int chave, int valor){
    int h = THED_Hash(TH, chave);
    ILIST_Inserir(TH->t[h], chave, valor);
}

void THED_Remover(THED* TH, int chave){
    int h = THED_Hash(TH, chave);
    ILIST_Remover(TH->t[h], chave);
}

INOH* THED_Buscar(THED* TH, int chave){
    int h, pos;
    h = THED_Hash(TH, chave);
    pos = ILIST_Buscar(TH->t[h], chave);
    return ILIST_Endereco(TH->t[h], pos);
}