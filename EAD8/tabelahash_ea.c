#include "tabelahash_ea.h"
#include <stdlib.h>
#include <stdio.h>

int THEA_Hash(THEA* th, int chave, int k){
    return ((chave % th->m) + k) % th->m;
}

THEA* THEA_Criar(int m){
    int i;
    THEA* novo = malloc(sizeof(THEA));
    novo->m = m;
    novo->th = calloc(m, sizeof(ELEM));
    novo->N = 0;

    for(i = 0; i < m; i++){
        novo->th[i].estado = E_LIVRE;
    }
    return novo;
}
int THEA_Inserir(THEA* th, int chave, int valor){
    int h, k , h_inicial;

    k = 0;
    h_inicial = h = THEA_Hash(th, chave, k);

    while(th->th[h].estado == E_OCUPADO){

        if(th->th[h].chave == chave)
            break;

        k++;
        h = THEA_Hash(th, chave, k);

        if(h == h_inicial)
            return -1;
    }

    th->th[h].chave = chave;
    th->th[h].valor = valor;
    if(th->th[h].estado == E_LIVRE)
        th->N++;
    th->th[h].estado = E_OCUPADO;

    return h;
}

int THEA_Buscar(THEA* th, int chave){
    int h, k, h_inicial;
    k = 0;
    h_inicial = h = THEA_Hash(th, chave, k);

    while(th->th[h].estado != E_LIVRE){

        if(th->th[h].estado == E_OCUPADO)
            if(th->th[h].chave == chave)
                return h;
        k++;
        h = THEA_Hash(th, chave, k);

        if(h == h_inicial)
            return -1;
    }

    return -1;
}

int THEA_Remover(THEA* th, int chave){
    int h = THEA_Buscar(th, chave);
    if(h != -1){
        th->th[h].estado = E_APAGADO;
        th->N--;
        return 1;
    }
    else
        return 0;
}

int THEA_ClusterMaximo(THEA* TH){
    int maximo = 0;
    int auxm = 0;
    int i;
    for( i = 0; i < TH->m; i++){
        if(TH->th[i].estado != E_OCUPADO){
            if(auxm > maximo)
                maximo = auxm;
            auxm = 0;
        }
        else
            auxm++;
        if(i == TH->m - 1){
            if(auxm > maximo)
                maximo = auxm;
        }
    }
    return maximo;
}

float THEA_TamMedioClusters(THEA* TH){
    float quantidadec = 0;
    float somac = 0;
    int auxc = 0, i;
    for(i = 0; i < TH->m; i++){
        if(TH->th[i].estado != E_OCUPADO){
            if(auxc > 0){
                quantidadec += 1;
                somac += auxc;
            }
            auxc = 0;
        }
        else
            auxc++;
        if(i == TH->m - 1){
            if(auxc > 0){
                quantidadec += 1;
                somac += auxc;
            }
        }
    }
    return somac/quantidadec;
}

float THEA_CustoBemSucedida(THEA *TH){
    int* vetCluster = malloc(sizeof(int)*TH->m);
    int c = 0, auxc = 0, i;

    #define MAX(a,b) a > b ? a : b

    for(i = 0; i < TH->m; i++){
        if(TH->th[i].estado != E_OCUPADO){
            if(auxc > 0){
                vetCluster[c++] = auxc;
            }
            auxc = 0;
        }
        else
            auxc++;
        if(i == TH->m - 1){
            if(auxc > 0){
                vetCluster[c++] = auxc;
            }
        }
    }
    float sum = 0;
    for(i = 0; i < c; i++)
        sum += MAX((float)vetCluster[i]/2,(float) 1);
    return sum/(float)TH->N;
}

THEA* random_hash(int n, int m, int max, int seed){
    int i;
    THEA* v1 = THEA_Criar(m);
    srand(seed);
    for(i = 0; i < n; i++){
        THEA_Inserir(v1, rand() % (max +1), 0);
    }
    return v1;
}