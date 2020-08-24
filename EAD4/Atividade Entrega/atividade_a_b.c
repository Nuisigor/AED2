#include <stdlib.h>
#include <stdio.h>

int pai(int n){
    return (n-1)/2;
}

int esq(int n){
    return 2*n+1;
}

int dir(int n){
    return 2*n+2;
}

void troca(int *v, int i, int j){
    int *aux = malloc(sizeof(int));
    *aux = v[j];
    v[j] = v[i];
    v[i] = *aux;
    free(aux);
}

//------------------------- FP MAXIMO -------------------------

void maxHeapify(int *v, int i, int th){
    int e = esq(i), d = dir(i);
    int maior = i;

    if((e < th) && (v[e] > v[i]))
        maior = e;

    if((d < th) && (v[d] > v[maior]))
        maior = d;
    
    if(maior != i){
        troca(v, i, maior);
        maxHeapify(v,maior,th);
    }
}

int fp_inicio(int *fp, int n){
    if(fp[0] != NULL)
        return fp[0];
}

int fp_remover_maximo(int *fp, int n){
    troca(fp, 0, n - 1);
    maxHeapify(fp, 0, n - 2);
    return n-1;
}

int fp_inserir(int *fp, int n, int valor){
    fp[n] = valor;
    int pos = n;
    while(fp[pos] > fp[pai(pos)]){
        troca(fp, pos, pai(pos));
        pos = pai(pos);
    }
    return n+1;
}


//------------------------- FP MINIMO -------------------------


int fp_min_inserir(int *fp, int n, int valor){
    fp[n] = valor;
    int pos = n;
    while(fp[pos] < fp[pai(pos)]){
        troca(fp, pos, pai(pos));
        pos = pai(pos);
    }
    return n+1;
}

void minHeapify(int *fp, int n, int th){
    int e = esq(n), d = dir(n);
    int min = n;

    if((e < th) && (fp[e] < fp[n]))
        min = e;

    if((d < th) && (fp[d] < fp[min]))
        min = d;
    
    if(min != n){
        troca(fp, n, min);
        minHeapify(fp, min, th);
    }
}

int fp_remover_minimo(int *fp, int n){
    troca(fp, 0, n - 1);
    minHeapify(fp, 0, n - 2);
    return n - 1;
}

void buildMinHeap(int *v, int n){
    int i;
    for(i = n/2 ; i >= 0; i--){
        minHeapify(v,i,n);
    }
}   


//------------------------- HEAP SORT -------------------------
void buildMaxHeap(int *v, int n){
    int i;
    for(i = n/2 ; i >= 0; i--){
        maxHeapify(v,i,n);
    }
}

void HeapSort(int *v, int n){
    int i;
    buildMaxHeap(v,n);
    for(i = n-1; i > 0; i--){
        troca(v, 0 , i);
        maxHeapify(v, 0, i);
    }
}