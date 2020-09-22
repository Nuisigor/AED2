#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "list.h"

int main(){
    int i,x;
    THED* t = THED_Criar(7, 10);
    THED_Inserir(t, 0, 88);
    THED_Inserir(t, 8, 8);
    THED_Inserir(t, 5, 5);
    THED_Inserir(t, 13, 13);
    THED_Inserir(t, 14, 14);
    THED_Inserir(t, 11, 11);
    THED_Inserir(t, 7, 7);
    THED_Inserir(t, 9, 9);
    THED_Inserir(t, 1, 1);
    printf("FOI");

    for(i = 0; i < t->m; i++){
        printf("%d: ",i);
        ILIST_Imprimir(t->t[i], 1);
    }

    x = 0;
    INOH* b = THED_Buscar(t,x);
    if(b){
        printf("buscar %d : %d\n", x, b->valor);
    }
    else{
        printf("%d não foi encontrado\n",  x);
    }

}