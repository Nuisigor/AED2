#pragma once

typedef struct abb
{
    struct abb* esquerda;
    struct abb* direita;
    int chave;
}ABB;

ABB* ABB_Criar(int chave, ABB* e, ABB* d);
void ABB_Inserir(ABB **A, int chave);
ABB* ABB_Buscar(ABB *A, int chave);
void ABB_Imprimir(ABB* A);
void ABB_Remover(ABB **A, int chave);
