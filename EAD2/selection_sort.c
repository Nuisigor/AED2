#include <stdio.h>
#include <stdlib.h>

int MAX(int *v, int st, int end){
    int aux = st;
    int maior = v[st];

    for(int i = st+1; i <= end; i++){
        if(v[i] > v[aux])
            aux = i;
    }
    return aux;
}

void troca(int *v, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

void selection_sort(int *v, int n){
    int i;
    int maior;
    for(i = n-1; i > 0; i--){
        maior = MAX(v,0,i);
        troca(v, maior, i);
    }
}

void printv(int *v, int n){
    printf("[ ");
    for(int i = 0; i < n; i++){
        if(i == n-1)
            printf("%d ]\n",v[i]);
        else
            printf("%d, ",v[i]);
    }
}


int main(){
    int v[] = {2,6,88,4,6,9,55};
    printv(v, sizeof(v)/4);
    selection_sort(v,sizeof(v)/4);
    printv(v, sizeof(v)/4);
}