#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "asciitrie.h"

ASCIITrie* AT_Buscar_R(ASCIITrie* T, unsigned char *chave, int n, int p){
    if(T == NULL)
        return NULL;
    if(n == p)
        return T;

    return AT_Buscar_R(T->filhos[chave[p]], chave, n, p+1);
}

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave){
    return AT_Buscar_R(T, chave, strlen(chave), 0);
}

ASCIITrie* AT_Criar(){
    ASCIITrie* noh = malloc(sizeof(ASCIITrie));
    int i;
    noh->estado = ATE_LIVRE;
    noh->val = 0;
    noh->tamanho = 0;
    for(i = 0; i < 256; i++){
        noh->filhos[i] = NULL;
    }

    return noh;
}

void AT_Inserir_R(ASCIITrie **T, unsigned char *chave, int val, int n, int p){
    if(*T == NULL)
        *T = AT_Criar();
    if(p == n){
        (*T)->val = val;
        (*T)->estado = ATE_OCUPADO;
        return;
    }

    AT_Inserir_R(&(*T)->filhos[chave[p]], chave, val, n, p+1);
}

void AT_Inserir(ASCIITrie **T, unsigned char *chave, int val){
    AT_Inserir_R(T, chave, val, strlen(chave), 0);
    (*T)->tamanho++;
}

void AT_Remover_R(ASCIITrie **T, unsigned char *chave, int n, int p){
    int i;
    if(*T == NULL)
        return;

    if(p == n){
        (*T)->estado = ATE_LIVRE;
    }
    else{
        AT_Remover_R(&(*T)->filhos[chave[p]], chave, n, p+1);
    }

    if((*T)->estado == ATE_OCUPADO)
        return;
    
    for(i = 0; i < 256; i++){
        if((*T)->filhos[i] != NULL)
            return;
    }
    free(*T);
    *T = NULL;
}

void AT_Remover(ASCIITrie **T, unsigned char *chave){
    AT_Remover_R(T, chave, strlen(chave), 0);
    (*T)->tamanho--;
}

void AT_Imprimir_R(ASCIITrie* T, int nivel, unsigned char c){
    int i;
    for(i = 0; i < nivel; i++)
        printf("-");

    printf("(%c) %d (%c)\n",c, T->val, T->estado == ATE_OCUPADO ? 'O': 'L');

    for(i = 0; i < 255; i++){
        if(T->filhos[i] != NULL)
            AT_Imprimir_R(T->filhos[i], nivel+1, i);
    }
}

void AT_Imprimir(ASCIITrie* T){
    printf("\n");
    AT_Imprimir_R(T, 0, ' ');
}

ASCIITrie* AT_Buscar_I(ASCIITrie* T, unsigned char *chave){
    int i;
    ASCIITrie* aux = T;
    for(i = 0; i <= strlen(chave); i++){
        if(aux == NULL)
            return NULL;
        if(i == strlen(chave)){
            return aux;
        }
        aux = aux->filhos[chave[i]];
    }
}

void AT_Inserir_I(ASCIITrie **T, unsigned char *chave, int val){
    int i;
    ASCIITrie** aux = T;
    for(i = 0; i <= strlen(chave); i++){
        if(*aux == NULL)
            *aux = AT_Criar();
        if(i == strlen(chave)){
            (*aux)->val = val;
            (*aux)->estado = ATE_OCUPADO;
        }
        aux = &(*aux)->filhos[chave[i]];
    }
    (*T)->tamanho++;

}


void AT_Remover_I(ASCIITrie **T, unsigned char *chave){
    int i, j, ultima, flag;
    ASCIITrie* aux = *T;
    ASCIITrie* aux2;

    for(i = 0 ; i <= strlen(chave); i++){
        flag = 0;
        if(aux == NULL)
            break;
        
        if(i == strlen(chave)){
            (aux)->estado = ATE_LIVRE;
        }
        // Guarda ultima variavel "ocupada"
        for(j = 0; j < 256; j++){
            if((int)chave[i] != j && (aux)->filhos[j] != NULL){
                aux2 = aux;
                ultima = i;
                break;
            }
        }
        aux = (aux)->filhos[chave[i]];
    }
    //r o u p a
    //0 1 2 3 4
    aux = aux2->filhos[chave[ultima]];
    aux2->filhos[chave[ultima]] = NULL;
    for(i = ultima+1; i < strlen(chave); i++){
        aux2 = aux;
        aux = aux->filhos[chave[i]];
        free(aux2);
    }
    (*T)->tamanho--;
}

int AT_Limpa(ASCIITrie* T){
    int i;
    int count = 0;
    int um = 0;
    int zero = 0;
    if(T == NULL)
        return 1;

    for(i = 0; i < 256; i++){
        if(T->filhos[i] != NULL){
            count++;
            if(AT_Limpa(T->filhos[i]) == 1)
                um++;
            else
                zero++;
        }
    }
    if(zero != 0)
        return 0;
    if(T->estado != ATE_OCUPADO && T->val != 0)
        return 0; 
    return 1;
}

int AT_Tamanho(ASCIITrie* T){
    int i;
    int count = T->estado == ATE_OCUPADO ? 1 : 0;
    for(i = 0; i < 256; i++)
        if(T->filhos[i] != NULL){
            count += AT_Tamanho(T->filhos[i]);
        }
    return count;
}

int AT_Tamanho_A(ASCIITrie* T){
    return T->tamanho;
}

void AT_Min_R(ASCIITrie* T, char** chave){
    int i;
    int tam = strlen(*chave);
    char* novo = malloc(sizeof(char)*(tam+2));
    strcpy(novo, *chave);
    free(*chave);
    *chave = novo;
    for(i = 0; i < 256; i++){
        if(T->filhos[i] != NULL){
            char aux = (char)i;
            strncat(*chave, &aux, 1);
            AT_Min_R(T->filhos[i], chave);
            return;
        }
    }
}

char* AT_Min(ASCIITrie* T){
    char* aux = "";
    AT_Min_R(T, &aux);
    return aux;
}

void AT_Max_R(ASCIITrie* T, char** chave){
    int i;
    int tam = strlen(*chave);
    char* novo = malloc(sizeof(char)*(tam+2));
    strcpy(novo, *chave);
    free(*chave);
    *chave = novo;
    for(i = 255; i >= 0; i--){
        if(T->filhos[i] != NULL){
            char aux = (char)i;
            strncat(*chave, &aux, 1);
            AT_Max_R(T->filhos[i], chave);
            return;
        }
    }
}

char* AT_Max(ASCIITrie* T){
    char* aux = "";
    AT_Max_R(T, &aux);
    return aux;
}

int SubstringCountLenL(char * s, int L) {
    int i,j,k;
    int n = strlen(s);
    if(L > n) 
        return 0;

    ASCIITrie* T = NULL;
    AT_Inserir(&T, "", -1);
    T->tamanho = 0;

    char* substring = malloc(sizeof(char)*L);

    for(i = 0; i < n; i++) {
        if(i + L > n) break;
        for(j = i, k = 0; j < (i + L); j++, k++) {
            substring[k] = s[j];
        }
        AT_Inserir_I(&T, substring, i);
    }
    int tam = AT_Tamanho_A(T);
    free(T);
    return tam;
}