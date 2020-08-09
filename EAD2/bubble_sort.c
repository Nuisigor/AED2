#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *v, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

int bubble_sort(int *v, int n){
    int comparacao = 0;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j+1])
                troca(v, j, j+1);
            comparacao++;
        }
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
    int comparacao;
    int tam = 100;
    int *v = random_vector(tam, 100, 0);
    comparacao = bubble_sort(v, tam);

    t = clock() - t;
    printf("Tempo = %f s\n", ((float)t)/CLOCKS_PER_SEC);

    printf("Quantidade de comparações Bubble= %d\n",comparacao);
}