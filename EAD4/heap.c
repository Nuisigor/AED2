
int esq(int n){
    return 2*n+1;
}

int dir(int n){
    return 2*n+2;
}

void troca(int *v, int i, int j){
    int aux = malloc(sizeof(int));
    aux = v[j];
    v[j] = v[i];
    v[i] = aux;
    free(aux);
}

void maxHeapify(int *v, int i, int th){
    int e = esq(i), d = dir(i);
    int maior = i;

    if((e < th) && (v[e] < v[i]))
        maior = e;

    if((d < th) && (v[d] < v[maior]))
        maior = d;
    
    if(maior != i){
        troca(v, i, maior);
        maxHeapify(v,maior,th);
    }
}

void buildMaxHeap(int *v, int n){
    int i;
    for(i = n/2 ; i >= 0; i--){
        maxHeapify(v,i,n);
    }
}

void HeapSort(int *v, int n){
    int i;
    buildMaxHeap(v,n);
    for( i = n-1; i > 0; i--){
        troca(v, 0 , i);
        maxHeapify(v, 0, i);
    }
}