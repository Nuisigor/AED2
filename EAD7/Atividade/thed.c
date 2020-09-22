#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "thed.h"

THED* THED_Criar(int m, int alloc_step){
    int i;
    THED* th = malloc(sizeof(THED));
    th->m = m;
    th->t = malloc(sizeof(ILIST*)*m);
    for(i = 0; i < m; i++)
        th->t[i] = ILIST_Criar(alloc_step);
    
    return th;
}

THED* inserir_n_aleatorios(int n, int m, int seed){
    int i, x, flag;
    srand(seed);
    THED* t = THED_Criar(m, 10);
    for(i = 0; i < n; i++){
        flag = 0;
        do{            
            x = rand() % (10*n+1);
            if(ILIST_Buscar(t->t[THED_Hash(t, x)], x) == -1){
                THED_Inserir(t, x, x );
                flag++;
            }
        }while(flag == 0);
    }
    return t;
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

int THED_MaisLonga(THED* TH){
    int i, maior = TH->t[0]->tam;

    for(i = 1; i < TH->m; i++)
        if(TH->t[i]->tam > maior)
            maior = TH->t[i]->tam;

    return maior;
}

int THED_MaisCurta(THED* TH){
    int i, menor = TH->t[0]->tam;
    
    for(i = 1; i < TH->m; i++)
        if(TH->t[i]->tam < menor)
            menor = TH->t[i]->tam;
    
    return menor;
}

float THED_TamMedio(THED* TH){
    int i;
    float media = 0;

    for(i = 0; i < TH->m; i++)
        media += TH->t[i]->tam;
    
    return media/(float)TH->m;
}