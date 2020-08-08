#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *v, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

void bubble_sort(int *v, int n){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j+1])
                troca(v, j, j+1);
        }
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
    bubble_sort(v, tam);
    printv(v, tam);
}