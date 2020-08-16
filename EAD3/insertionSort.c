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