#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "atividade_a_b.h"

int main(){
    clock_t t;
    //Leitura
    int m,n;
    scanf("%d", &m);
    scanf("%d", &n);
    t = clock();

    //Criação das fileiras
    int *f = malloc(sizeof(int)*m);

    for(int i = 0; i < m; i++){
        //Leitura de assentos
        int x;
        scanf("%d", &x);
        //Ordenando assentos de forma que o que contem o menor numero fique na raiz
        fp_min_inserir(f, i, x);
    }

    int lucro = 0;

    //Conta o lucro
    while(n != 0){
        lucro += 100 + (100/fp_inicio(f,m));
        f[0]--;
        buildMinHeap(f,m);
        if(f[0] == 0)
            m = fp_remover_minimo(f,m);
        n--;
    }

    printf("Lucro = %d\n",lucro);
    t = clock() - t;
    printf("Tempo = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);
   
   return 0;
}