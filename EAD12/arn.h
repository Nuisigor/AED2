#pragma once

typedef enum{
    C_VERMELHO,
    C_PRETO
}ARN_COR;

typedef struct ARN{
    struct ARN *esq;
    struct ARN *dir;
    int chave;
    int valor;
    ARN_COR cor; 
}ARN;

ARN* ARN_Criar(int chave, int valor);
void ARN_Inserir(ARN** A, int chave, int valor);
int ARN_Sort(int* v, int n);
int ARN_Altura(ARN *A);