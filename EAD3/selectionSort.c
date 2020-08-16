#include "quickSort.h"

int MAX(int *v, int st, int end){
    int aux = st;

    for(int i = st; i <= end; i++){
        if(v[i] > v[aux])
            aux = i;
    }
    return aux;
}


void selection_sort(int *v, int n){
    int i;
    int maior;
    for(i = n-1; i > 0; i--){
        maior = MAX(v,0,i);
        troca(v, maior, i);
    }
}