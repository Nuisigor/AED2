// Aluno : Igor Lara de Oliveira

#include <stdio.h>
#include <stdlib.h>
#include "MinK.h"
#include "vector.h"
#include <time.h>
#include <string.h>

int main(int argc, char** argv){
    clock_t t;
    int n = atoi(argv[1]);
    int k;
    int *v = random_vector_unique_elems(n,42);
    int x;
    int *v1 = malloc(sizeof(int)*n);
    int i;
    for(i = 0; i < 3; i++){
        if(i == 0){
            k = 1;
            printf("k = 1\n");
        }
        if(i == 1){
            k = n/3;
            printf("\n\nk = n/3\n");
        }
        if(i == 2){
            k = n/2;
            printf("\n\nk = n/2\n");
        }
        //SelectionMinK
        if(k <= 10000){
            memcpy(v1, v, sizeof(int)*n);
            t = clock();
            x = SelectionMinK(v1, n, k);
            t = clock() - t;
            printf("X = %d\t k = %d\t Tempo SelectionMinK = %.0f ms\n", x, k, ((float)t/CLOCKS_PER_SEC)*1000);
        }
        else
            printf("\n");

        //HeapMinK
        memcpy(v1, v, sizeof(int)*n);
        t = clock();
        x = HeapMinK(v1, n, k);
        t = clock() - t;
        printf("X = %d\t k = %d\t Tempo HeapMinK = %.0f ms\n", x, k, ((float)t/CLOCKS_PER_SEC)*1000);

        //QuickMinK
        memcpy(v1, v, sizeof(int)*n);
        t = clock();
        x = QuickMinK(v1, 0, n-1, k);
        t = clock() - t;
        printf("X = %d\t k = %d\t Tempo QuickMinK= %.0f ms\n", x, k, ((float)t/CLOCKS_PER_SEC)*1000);
    }
    
    return 0;
}
