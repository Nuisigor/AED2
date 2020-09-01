#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct info
{
    int dado;
    int chave;
} Info;

int maxx(Info* v, int n){
    int max = v[0].chave;
    for(int i = 1; i < n; i++){
        if(v[i].chave > max)
            max = v[i].chave;
    }

    return max;
}

void soma_prefixo(Info* v, int* c, int n, int k){
    int acum = 0;
    for(int i = 0; i < n; i++)
        c[v[i].chave]++;
    
    for(int i = 0; i <= k; i++){
        int t = c[i];
        c[i] = acum;
        acum += t;
    }
}

void counting_sort(Info* v, int n){
    int k;
    int *c;
    Info* s;

    k = maxx(v,n);
    c = calloc(k+1, sizeof(int));
    s = malloc(sizeof(Info)*n);


    soma_prefixo(v, c, n, k);
    for(int i = 0; i < n; i++)
        s[c[v[i].chave]++] = v[i];

    memcpy(v, s, sizeof(Info)*n);
    free(c);
    free(s);
}