#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int *v, int k){
    int i = k-1;
    int aux = v[k];
    while((aux < v[i]) && (i >= 0)){
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = aux;
}

void insertion_sort(int *v, int n){
    for(int i = 1; i < n; i++){
        insertion(v,i);
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
    insertion_sort(v, tam);
    printv(v, tam);
}