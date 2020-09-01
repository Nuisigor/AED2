#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int maxx(int *v, int n){
    int max = v[0];

    for(int i = 1; i < n; i++)
        if(max < v[i])
            max = v[i];
    
    return max;
}

void counting_sort(int *v, int* temp, int n, int div, int base){
    int i, t, acum = 0;
    //int c[base];
    //memset(c, 0, sizeof(int)*base);

    int* c = calloc(base, sizeof(int));

    #define DIGIT(X) (X / div) % base

    for(i = 0; i < n; i++)
        c[DIGIT(v[i])]++;

    for(i = 0; i < base; i++){
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
    k = maxx(v,n);

    int *temp = malloc(sizeof(int)*n);
    
    while(k > 0){
        counting_sort(v, temp, n, div, base);
        div *= base;
        k /= base;
    }
    free(temp);
}