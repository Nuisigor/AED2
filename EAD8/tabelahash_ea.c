#include "tabelahash_ea.h"
#include <stdlib.h>

int THEA_Hash(THEA* th, int chave, int k){
    return ((chave % th->m) + k) % th->m;
}

THEA* THEA_Criar(int m){
    int i;
    THEA* novo = malloc(sizeof(THEA));
    novo->m = m;
    novo->th = malloc(sizeof(ELEM)*m);

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
    }
    return maximo;
}