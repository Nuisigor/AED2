void troca(int *v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int partition(int *v, int p, int  r){
    int x;
    int i, j;

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