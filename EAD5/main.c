#include <stdio.h>
#include <stdlib.h>
#include "counting.h"
#include "radixsort.h"

Info* random_info_vector(int n, int max, int seed){
    srand(seed);

    int i;
    Info* v = malloc(sizeof(Info)*n);

    for(i = 0; i < n; i++){
        v[i].dado = rand() % (max+1);
        v[i].chave = rand() % (max+1);
    }

    return v;
}

void imprimir_chave(Info *v, int n){
    printf("[ ");
    for(int i = 0; i < n; i++){
        if(i == n-1)
            printf("%d ]\n",v[i].chave);
        else
            printf("%d, ",v[i].chave);
    }
}

int main(int argc, char** argv){

    int n = n = atoi(argv[1]);

    Info* c = random_info_vector(n, n*100, 42);
    imprimir_chave(c,n);
    counting_sort(c,n);
    imprimir_chave(c,n);


    return 0;
}