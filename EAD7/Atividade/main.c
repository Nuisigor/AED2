#include <stdio.h>
#include <stdlib.h>
#include "thed.h"
#include "list.h"

int main(int argc, char** argv){
    int i;
    int total = 0;
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    THED* t = inserir_n_aleatorios(n, m, 42);

    for(i = 0; i < t->m; i++){
        // printf("%d: ",i);
        // printf("Tam = %d\n",t->t[i]->tam);
        total += t->t[i]->tam;
    }

    printf("Maior lista : %d\n",THED_MaisLonga(t));
    printf("Menor Lista : %d\n",THED_MaisCurta(t));
    printf("Média de listas : %f\n",THED_TamMedio(t));
    printf("New N : %d\n",total);

}