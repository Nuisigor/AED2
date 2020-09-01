#include <stdlib.h>
#include <string.h>

void counting_sortr(int *v, int* temp, int n, int div, int base){
    int i, t, acum = 0;
    //int c[base];
    //memset(c, 0, sizeof(int)*base);

    int* c = calloc(base, sizeof(int));

    #define DIGIT(X) (X / div) % base

    for(i = 0; i < n; i++)
        c[DIGIT(v[i])]++;

    for(i = 0; i < n; i++){
        t = c[i];
        c[i] = acum;
        acum += t;
    }

    for(i = 0; i < n; i++)
        temp[c[DIGIT(v[i])]++] = v[i];
    
    memcpy(v, temp, sizeof(int)*n);
}

void radix_sort(int *v, int n, int base){
    int k, div = 1;
    k = max(v,n);
    int *temp = malloc(sizeof(int)*n);

    while(k > 0){
        counting_sortr(v, temp, n, div, base);
        div *= 10;
        k /= 10;
    }
    free(temp);
}