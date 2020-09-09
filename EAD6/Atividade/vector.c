#include <stdlib.h>
#include <stdio.h>

int* random_vector(int n, int max, int seed){
    srand(seed);

    int *v  = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        v[i] = rand() % (max+1);
    }

    return v;
}

void print_vector(int *v, int n){
    printf("[ ");
    for(int i = 0; i < n; i++){
        if(i == n-1)
            printf("%d ]\n",v[i]);
        else
            printf("%d, ",v[i]);
    }
}


void troca(int* v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void embaralhar(int *v, int ini, int fim, int seed){
    int i, j;
    srand(seed);
    for(i = fim-1; i > ini; i--){
        j = (rand() % (i + 1));
        j = j <= ini ? ini+1 : j;
        troca(v, i, j);
     }
}


int* random_vector_unique_elems(int n, int seed){
    int x = rand() % (12+1);
    int* v = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
    embaralhar(v, 0, n, seed);
    embaralhar(v, 0, n, seed);
    return v;
}