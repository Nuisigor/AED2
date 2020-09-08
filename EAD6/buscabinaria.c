int buscabin1(int *v, int x, int e, int d){
    int m;
    if(e <= d){
        m = (e+d)/2;
        if(v[m] == x)
            return m;
        else{
            if(v[m] > x)
                return buscabin1(v, x, e, m-1);
            else
                return buscabin1(v, x, m+1, d);
        }
    }
    return -1;
}

int buscabin(int *v, int n, int x){
    return buscabin1(v, x, 0, n);
}

