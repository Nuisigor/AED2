#pragma once
#include "prime_list.h"

typedef enum ESTADO{
    E_LIVRE,
    E_OCUPADO,
    E_APAGADO
} ESTADO;

typedef enum FSONDAGEM{
    FS_LINEAR,
    FS_QUADRATICA,
    FS_HASH_DUPLO
} FSONDAGEM;
typedef struct ELEM{
    int chave;
    int valor;
    ESTADO estado;
}ELEM;

typedef struct THEA{
    int m;
    int N;
    int s;
    int colisao;
    ELEM* th;
    FSONDAGEM f_sondagem;
    int (*hash)(struct THEA* th, int chave, int k);
    prime_list_t* primos;
}THEA;

static void THEA_Redimensionar(THEA* th, int novo);
int THEA_Hash(THEA* th, int chave, int k);
THEA* THEA_Criar(int m, FSONDAGEM sondagem);
int THEA_Inserir(THEA*th, int chave, int valor);
int THEA_Buscar(THEA* th, int chave);
int THEA_Remover(THEA* th, int chave);
int THEA_ClusterMaximo(THEA* TH);
float THEA_TamMedioClusters(THEA* TH);
float THEA_CustoBemSucedida(THEA *TH);
int* random_vector(int n, int max, int seed);
THEA* random_hash(int* v, int n, FSONDAGEM f_sondagem);