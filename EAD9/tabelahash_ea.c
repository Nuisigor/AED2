#include "tabelahash_ea.h"
#include "prime_list.h"
#include <stdlib.h>
#include <stdio.h>


static void THEA_Redimensionar(THEA* th, int novo){
    ELEM* nova;
    ELEM* antiga;
    int i, m_antigo;
    nova = calloc(novo, sizeof(ELEM));

    for( i = 0; i < novo; i++)
        nova[i].estado = E_LIVRE;
    
    antiga = th->th;
    m_antigo = th->m;
    th->th = nova;
    th->m = novo;
    if(th->f_sondagem == FS_HASH_DUPLO)
        th->s = novo-1;
    th->N = 0;

    for( i = 0; i < m_antigo; i++)
        if(antiga[i].estado == E_OCUPADO)
            THEA_Inserir(th, antiga[i].chave, antiga[i].valor);

    free(antiga);
}

int hash_linear(THEA* th, int chave, int k){
    return ((chave % th->m) + k) % th->m;
}

int hash_quadratica(THEA* th, int chave, int k){
    return ((chave % th->m) + k*k)% th->m;
}

int hash_dupla(THEA* th, int chave, int k){
    return ((chave % th->m) + k * ((chave % th->s)+1)) % th->m;
}

int THEA_Hash(THEA* th, int chave, int k){
    return th->hash(th,chave,k);
}

THEA* THEA_Criar(int m, FSONDAGEM sondagem){
    int i;
    THEA* novo = malloc(sizeof(THEA));
    novo->primos = PL_Load("primes1.dat", 1000000);
    novo->m = PL_NextPrime(novo->primos, m);
    novo->th = calloc(novo->m, sizeof(ELEM));
    novo->N = 0;
    novo->colisao = 0;

    novo->f_sondagem = sondagem;
    switch (sondagem){
        case FS_LINEAR:
            novo->hash = hash_linear;
            break;
        case FS_QUADRATICA:
            novo->hash = hash_quadratica;
            break;
        case FS_HASH_DUPLO:
            novo->hash = hash_dupla;
            novo->s = m - 1;
            break;
    }

    for(i = 0; i < m; i++){
        novo->th[i].estado = E_LIVRE;
    }
    return novo;
}
int THEA_Inserir(THEA* th, int chave, int valor){
    int h, k , h_inicial;
    k = 0;

    if(th->N > th->m/2){
        int m_novo = PL_NextPrime(th->primos, th->m);
        if(m_novo <=  15485863) 
            THEA_Redimensionar(th, m_novo);
    }


    h_inicial = h = THEA_Hash(th, chave, k);
    while(th->th[h].estado == E_OCUPADO){
        th->colisao++;
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

int* random_vector(int n, int max, int seed){
    int i;
    srand(seed);
    int* v = malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        v[i] = rand() % (max + 1);
    }
    return v;
}

THEA* random_hash(int* v, int n, FSONDAGEM f_sondagem){
    int i;
    THEA* v1 = THEA_Criar(2, f_sondagem);
    for(i = 0; i < n; i++){
        THEA_Inserir(v1, v[i], 0);
    }
    return v1;
}

