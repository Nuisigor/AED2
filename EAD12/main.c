#include "abb.h"
#include "avl.h"
#include "arn.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* random_vector(int n, int max, int seed){
    int *v = (int*) calloc(n,sizeof(int));
    srand(seed);
    
    for(int i = 0; i < n; i++){
        int aux = rand()% max;
        v[i] = aux;
    }
    
    return v;
}

int* vet_cresc(int n){
    int i, j;
    int* v = calloc(n,sizeof(int));
    for(i = 0, j = n; j > 0; j--, i++)
        v[i] = j;
    return v;
}

void vetcopy(int *v, int **v1, int n){
    free(*v1);
    int *aux = calloc(n,sizeof(int));
    for(int i = 0; i < n; i++){
        aux[i] = v[i]; 
    }
    *v1 = aux;
}


int main(int argc, char** argv){
    int *x,*b;
    int n = atoi(argv[1]);
    x = vet_cresc(n);
    clock_t t;
    /*  Teste 1 */
    //ABB
    // vetcopy(x, &b, n);
    // t = clock();
    // ABB_Sort(b,n);
    // t = clock() - t;
    // printf("Tempo: %f\n", (((float)t)/CLOCKS_PER_SEC));
    
    //ARN
    vetcopy(x, &b, n);
    t = clock();
    ARN_Sort(b,n);
    t = clock() - t;
    printf("Tempo: %f\n", (((float)t)/CLOCKS_PER_SEC));

    //AVL
    vetcopy(x, &b, n);
    t = clock();
    AVL_Sort(b,n);
    t = clock() - t;
    printf("Tempo: %f\n", (((float)t)/CLOCKS_PER_SEC));

    /*  Teste 2 */
    // float vet[10];
    // float mediaAlt, mediavet, desvpadrao;
    
    // //ABB
    // mediaAlt = 0;
    // mediavet = 0;
    // for(int i = 0; i < 10; i++){
    //     free(b);
    //     b = random_vector(n, 100*n, 42);
    //     t = clock();
    //     mediaAlt += ABB_Sort(b,n);
    //     t = clock() -t;
    //     mediavet += ((float)t/CLOCKS_PER_SEC);
    //     vet[i] = ((float)t/CLOCKS_PER_SEC);
    // }
    // mediaAlt /= 10;
    // mediavet /= 10;
    // desvpadrao = 0;
    // for(int i = 0; i < 10; i++){
    //     desvpadrao += pow(vet[i] - mediavet, 2);
    // }
    // desvpadrao /= 10;
    // desvpadrao = sqrt(desvpadrao);
    // printf("ABB\nMedia de Altura = %.3f\t Media tempo = %.3f\t Desv Padrão = %.3f\n",mediaAlt, mediavet, desvpadrao);

    // //ARN
    // mediaAlt = 0;
    // mediavet = 0;
    // for(int i = 0; i < 10; i++){
    //     free(b);
    //     b = random_vector(n, 100*n, 42);
    //     t = clock();
    //     mediaAlt += ARN_Sort(b,n);
    //     t = clock() -t;
    //     mediavet += ((float)t/CLOCKS_PER_SEC);
    //     vet[i] = ((float)t/CLOCKS_PER_SEC);
    // }
    // mediaAlt /= 10;
    // mediavet /= 10;
    // desvpadrao = 0;
    // for(int i = 0; i < 10; i++){
    //     desvpadrao += pow(vet[i] - mediavet, 2);
    // }
    // desvpadrao /= 10;
    // desvpadrao = sqrt(desvpadrao);
    // printf("ARN\nMedia de Altura = %.3f\t Media tempo = %.3f\t Desv Padrão = %.3f\n",mediaAlt, mediavet, desvpadrao);

    // //AVL
    // mediaAlt = 0;
    // mediavet = 0;
    // for(int i = 0; i < 10; i++){
    //     free(b);
    //     b = random_vector(n, 100*n, 42);
    //     t = clock();
    //     mediaAlt += AVL_Sort(b,n);
    //     t = clock() -t;
    //     mediavet += ((float)t/CLOCKS_PER_SEC);
    //     vet[i] = ((float)t/CLOCKS_PER_SEC);
    // }
    // mediaAlt /= 10;
    // mediavet /= 10;
    // desvpadrao = 0;
    // for(int i = 0; i < 10; i++){
    //     desvpadrao += pow(vet[i] - mediavet, 2);
    // }
    // desvpadrao /= 10;
    // desvpadrao = sqrt(desvpadrao);
    // printf("AVL\nMedia de Altura = %.3f\t Media tempo = %.3f\t Desv Padrão = %.3f\n",mediaAlt, mediavet, desvpadrao);
}