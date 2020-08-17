#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>


//--------------------- FUNÇÕES GLOBAIS ---------------------
void troca(int *v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int* random_vector(int n, int max, int seed){
    int *v = (int*) calloc(n,sizeof(int));
    srand(seed);
    
    for(int i = 0; i < n; i++){
        v[i] = rand() % (max+1);    
    }
    
    return v;
}

int* inverteV(int *v, int n){
    int *v1 = malloc(sizeof(int)*n);
    int i,j;
    for(i = 0, j = n-1; i < n; i++, j--){
        v1[j] = v[i];
    }
    int *aux = v;
    v = v1;
    free(aux);
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

//--------------------- BUBBLE SORT ---------------------
int bubble_Sort(int *v, int n){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j+1])
                troca(v, j, j+1);
        }
    }
}

//--------------------- INSERTION SORT ---------------------
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

//--------------------- SELECTION SORT ---------------------
int MAX(int *v, int st, int end){
    int aux = st;

    for(int i = st; i <= end; i++){
        if(v[i] > v[aux])
            aux = i;
    }
    return aux;
}


void selection_sort(int *v, int n){
    int i;
    int maior;
    for(i = n-1; i > 0; i--){
        maior = MAX(v,0,i);
        troca(v, maior, i);
    }
}

//--------------------- MERGE SORT ---------------------
void merge(int *v, int p, int q, int r){
    int *e, *d;
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    //CRIAÇÃO DOS SUBVETORES
    e = malloc(sizeof(int) * (n1+1));
    d = malloc(sizeof(int) * (n2+1));

    //CÓPIA DO VETOR PARA O PRIMEIRO SUBVETOR
    for(i = 0; i < n1; i++){
        e[i] = v[p+i];
    }

    e[n1] = INT_MAX; // Sentinela

    //CÓPIA DO VETOR PARA O SEGUNDO SUBVETOR
    for(j = 0; j < n2; j++){
        d[j] = v[q+1+j];
    }
    d[n2] = INT_MAX;

    //INTERCALAÇÃO
    i = 0;
    j = 0;

    for( k = p; k <= r; k++){
        if(e[i] <= d[j])
            v[k] = e[i++];
        else
            v[k] = d[j++];
    }

    free(e);
    free(d);

}

void mergeSort(int *v, int e, int d){
    int m;
    if(e < d){
        m = (e+d)/2;
        mergeSort(v, e, m);
        mergeSort(v, m+1, d);
        merge(v, e, m, d);
    }
}

//--------------------- QUICK SORT ---------------------
int partition(int *v, int p, int  r){
    int x;
    int i, j;

    troca(v, r - 1, rand() % (r - p) + p); // Evitar pior caso

    x = v[r];
    i = p-1;

    for(j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            troca(v, i, j);
        }
    }

    troca(v, i+1, r);
    return i+1;
}

void quickSort(int *v, int e, int d){
    int q; // POSIÇÃO DO PIVO
    if(e < d){
        q = partition(v, e, d);
        quickSort(v, e, q-1);
        quickSort(v, q, d);
    }
}



//--------------------- MAIN ---------------------

int main(int argc, char** argv){
    
    int* v = NULL;
    int n = 0;
    int seed = 0;

    n = atoi(argv[1]);
    clock_t t;

    /*----------------- LETRA A -----------------*/


    // // BUBBLE SORT
    // t = clock();
    // v = random_vector(n, n * 100, seed);
    // bubble_Sort(v,n);
    // t = clock() - t;
    // printf("Tempo Bubble Sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

    // //  INSERTION SORT
    // t = clock();
    // v = random_vector(n, n * 100, seed);
    // insertion_sort(v, n);
    // t = clock() - t;
    // printf("Tempo Insertion Sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

    // // SELECTION SORT
    // t = clock();
    // v = random_vector(n, n * 100, seed);
    // selection_sort(v ,n);
    // t = clock() - t;
    // printf("Tempo Selection Sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

    // // MERGE SORT
    // t = clock();
    // v = random_vector(n, n * 100, seed);
    // mergeSort(v, 0, n-1);
    // t = clock() - t;
    // printf("Tempo Merge Sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

    // QUICK SORT
    // v = random_vector(n, n * 100, seed);
    // t = clock();
    // quickSort(v, 0, n-1);
    // t = clock() - t;
    // printf("Tempo Quick sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);






    /*----------------- LETRA B -----------------*/
    v = random_vector(n, n * 100, seed);
    quickSort(v, 0, n-1);

    //BUBBLE SORT
    t = clock();
    bubble_Sort(v,n);
    t = clock() - t;
    printf("Tempo Bubble sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

    //INSERTION SORT
    t = clock();
    insertion_sort(v, n);
    t = clock() - t;
    printf("Tempo Insertion sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

   
    //SELECTION SORT
    t = clock();
    selection_sort(v, n);
    t = clock() - t;
    printf("Tempo Selection sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);
    
    
    //MERGE SORT
    t = clock();
    mergeSort(v, 0, n-1);
    t = clock() - t;
    printf("Tempo Merge sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

    
    //QUICK SORT
    t = clock();
    quickSort(v, 0, n-1);
    t = clock() - t;
    printf("Tempo Quick sort = %.5f s\n", ((float)t)/CLOCKS_PER_SEC);

    return 0;
}