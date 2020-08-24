#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "heapSort.h"
#include "atividade.h"


int* gerar_vetor_aleatorio(int n, int max, int seed){
    int i;
    int* v;
    srand(seed);

    //Alocar vetor na heap com n elementos.
    v = malloc(sizeof(int) * n);
    //Inicializar o vetor com numeros aleatórios de 0 a (n*10)-1
    for(i = 0; i < n; i++){
        v[i] = rand() % (max +1) ;
    }

    return v;
}

int* gerar_arvore_aleatorio(int n, int max, int seed, int (*inserir)(int *v, int n, int valor)){
    int i;
    int* v;
    srand(seed);
    int aux;

    v = malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        aux = rand() % (max +1) ;
        inserir(v , i, aux);
    }

    return v;
}

void imprimir_vetor(int* v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d, ", v[i]);
        fflush(stdout);
    }
    printf("\n");
}

void imprimir_arvore(int *v, int n){
    int i = 0;
    int aux = 0;
    int exp = 1;
    for(int i = 0; i < n; i++){
        if(i == aux){
            printf("%d\n",v[i]);
            aux = aux + pow(2, exp++);
        }
        else
            printf("%d - ",v[i]);
            
    }
}

int main(int argc, char** argv){
    
    int* v = NULL;
    int n = 0;
    int i;

    n = atoi(argv[1]);
    srand(0);

    // v = gerar_vetor_aleatorio(n, n * 100, 0);
    // imprimir_vetor(v, n);
    // HeapSort(v,n);
    // printf("\n");
    // imprimir_vetor(v,n);



    v = gerar_arvore_aleatorio(n, n*100, 0, fp_inserir);
    imprimir_arvore(v,n);
    n = fp_remover_maximo(v,n);
    n = fp_remover_minimo(v,n);
    printf("\n\n");
    imprimir_arvore(v,n);
    printf("\n\n");


    return 0;
}
