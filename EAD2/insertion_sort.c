#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int insertion(int *v, int k){
    int i = k-1;
    int aux = v[k];

    int comparacao = 0;
    while((aux < v[i]) && (i >= 0)){
        v[i+1] = v[i];
        i--;
        comparacao++;
    }
    v[i+1] = aux;
    return comparacao;
}

int insertion_sort(int *v, int n){
    int comparacao = 0;
    for(int i = 1; i < n; i++){
        comparacao += insertion(v,i);
    }
    return comparacao;
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
    clock_t t;
    t = clock();
    int tam = 100;
    int *v = random_vector(tam, 1000, 0);
    int comparacao = insertion_sort(v, tam);

    t = clock() - t;
    printf("Tempo = %lf s\n", ((long double)t)/CLOCKS_PER_SEC);

    printf("Quantidade de comparações Selection= %d\n",comparacao);
}