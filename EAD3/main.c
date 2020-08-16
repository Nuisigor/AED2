#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "quickSort.h"
#include "mergeSort.h"

#define DEBUG 0

//Esta função aloca e inicializa um vetor de n inteiros aleatórios
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

void imprimir_vetor(int* v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d, ", v[i]);
        fflush(stdout);
    }
    printf("\n");
}

int main(int argc, char** argv){
    
    int* v = NULL;
    int n = 0;
    int i;

    //pegar o tamanho do vetor aleatório a ser gerado da linha de comando.
    //No VSCODE, dá pra alterar esse valor no arquivo .vscode/launch.json, na opção "args"
    n = atoi(argv[1]);
    srand(0);

    v = gerar_vetor_aleatorio(n, n * 100, 0);

    imprimir_vetor(v, n);

    selection_sort(v, n);
    // insertion_sort(v, n);
    // bubble_sort(v,n);
    // quickSort(v,0,n-1);
    // mergeSort(v,0,(n-1));

    imprimir_vetor(v, n);


    return 0;
}
