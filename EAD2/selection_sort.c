#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int* random_vector(int n, int max, int seed){
    int *v = (int*) calloc(n,sizeof(int));
    srand(seed);
    
    for(int i = 0; i < n; i++){
        int aux = rand()% 101;
        v[i] = aux;
    }
    
    return v;
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
    int tam = 100;
    int *v = random_vector(tam, 1000, 0);
 
    printv(v, tam);
    selection_sort(v, tam);
    printv(v, tam);
}