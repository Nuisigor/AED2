#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *v, int p, int q, int r){
    int *e, *d;
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    //CRIAÇÃO DOS SUBVETORES
    e = malloc(sizeof(int) * (n1+1));
    d = malloc(sizeof(int) * (n2+1));

    //CÓPIA DO VETOR PARA O PRIMEIRO SUBVETOR
    for(i = 0; i < n1; i++){
        e[i] = v[p+i];
    }

    e[n1] = INT_MAX; // Sentinela

    //CÓPIA DO VETOR PARA O SEGUNDO SUBVETOR
    for(j = 0; j < n2; j++){
        d[j] = v[q+1+j];
    }
    d[n2] = INT_MAX;

    //INTERCALAÇÃO
    i = 0;
    j = 0;

    for( k = p; k <= r; k++){
        if(e[i] <= d[j])
            v[k] = e[i++];
        else
            v[k] = d[j++];
    }

    free(e);
    free(d);

}

void mergeSort(int *v, int e, int d){
    int m;
    if(e < d){
        m = (e+d)/2;
        mergeSort(v, e, m);
        mergeSort(v, m+1, d);
        merge(v, e, m, d);
    }
}

