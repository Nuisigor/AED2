int sequencial(int *v, int n, int x){
    for(int i = 0; i < n ; i++){
        if(x == v[i])
            return i;
    }
    
    return -1;
}