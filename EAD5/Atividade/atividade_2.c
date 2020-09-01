#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atividade_1.h"
#include <time.h>

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


int main(int argc, char** argv){
    clock_t t;

    t = clock();
    int n = atoi(argv[1]);
    int base = atoi(argv[2]);

    int *v = random_vector(n, n*100, 0);
    // print_vector(v, n);
    radix_sort(v, n, base);
    // print_vector(v, n);
    t = clock() - t;
    printf("Tempo : %.0f ms\n", ((float)t/CLOCKS_PER_SEC)*1000);

    return 0;
}