#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--------------------FUNCOES--------------------//

void troca(int *v, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
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


int* random_vector(int n, int max, int seed){
    int *v = (int*) calloc(n,sizeof(int));
    srand(seed);
    
    for(int i = 0; i < n; i++){
        int aux = rand()% max;
        v[i] = aux;
    }
    
    return v;
}


//--------------------SELECTION SORT--------------------//

int comparacaoMax;

int MAX(int *v, int st, int end){
    int aux = st;

    for(int i = st; i <= end; i++){
        if(v[i] > v[aux])
            aux = i;
        comparacaoMax++;
    }
    return aux;
}

void selection_sort(int *v, int n){
    int i;
    int maior;
    comparacaoMax = 0;
    for(i = n-1; i > 0; i--){
        maior = MAX(v,0,i);
        troca(v, maior, i);
    }
}


//--------------------BUBBLE SORT--------------------//

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


//--------------------INSERTION SORT--------------------//

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


int main(){
    int tam = 10;
    int comparacao;

    clock_t t;
    for(int i = 0; i < 4; i++, tam*=10){
        //--------------------SELECTION SORT--------------------//
        t = clock();
        int *v0 = random_vector(tam, 1000, 0);
        selection_sort(v0, tam);

        t = clock() - t;
        printf("Tempo Selection = %.10f s\n", ((float)t)/CLOCKS_PER_SEC);

        printf("Quantidade de comparações Selection = %d\n",comparacaoMax);


        //--------------------BUBBLE SORT--------------------//
        t = clock();
        int *v1 = random_vector(tam, 100, 0);
        comparacao = bubble_sort(v1, tam);

        t = clock() - t;
        printf("Tempo Bubble= %.10f s\n", ((float)t)/CLOCKS_PER_SEC);

        printf("Quantidade de comparações Bubble= %d\n",comparacao);


        //--------------------INSERTION SORT--------------------//
        t = clock();
        int *v2 = random_vector(tam, 1000, 0);
        comparacao = insertion_sort(v2, tam);

        t = clock() - t;
        printf("Tempo Insertion= %.10f s\n", ((float)t)/CLOCKS_PER_SEC);

        printf("Quantidade de comparações Insertion= %d\n",comparacao);

        printf("\n\n\n");
    }
}