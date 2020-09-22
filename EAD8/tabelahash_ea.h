#pragma once

typedef enum ESTADO{
    E_LIVRE,
    E_OCUPADO,
    E_APAGADO
} ESTADO;

typedef struct ELEM{
    int chave;
    int valor;
    ESTADO estado;
}ELEM;

typedef struct THEA{
    int m;
    ELEM* th;
}THEA;

int THEA_Hash(THEA* th, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA*th, int chave, int valor);
int THEA_Buscar(THEA* th, int chave);
int THEA_Remover(THEA* th, int chave);
int THEA_ClusterMaximo(THEA* TH);
float THEA_TamMedioClusters(THEA* TH);