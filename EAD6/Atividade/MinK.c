#include <stdio.h>
#include "vector.h"

//----------------------- SELECTIONMINK -----------------------//

int MAX(int *v, int st, int end){
    int max = st;
    for(int i = st+1; i <= end; i++){
        if(v[i] > v[max])
            max = i;
    }
    return max;
}

int MIN(int *v, int st, int end){
    int min = st;
    for(int i = st+1; i <= end; i++){
        if(v[i] < v[min])
            min = i;
    }
    return min;
}
int SelectionMinK(int *v, int n, int k){
    if(k >= n)
        return v[MAX(v, 0, n-1)];
    else{
        int i;
        int menor, pos;
        for(int i = 0; i < k; i++){
            menor = MIN(v, i, n-1);
            troca(v, i, menor);
            pos = i;
        }
        return v[pos];
    }
}

//----------------------- HEAPMINK -----------------------//

int esq(int n){
    return 2*n+1;
}

int dir(int n){
    return 2*n+2;
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

void buildMinHeap(int *v, int n){
    int i;
    for(i = n/2 ; i >= 0; i--){
        minHeapify(v,i,n);
    }
}   

int fp_remover_minimo(int *fp, int n){
    troca(fp, 0, n - 1);
    minHeapify(fp, 0, n - 2);
    return n - 1;
}

int HeapMinK(int *v, int n, int k){
    int i, pos = n;
    int x;
    buildMinHeap(v,n);
    if(k >= n)
        return v[0];

    for(i = 0; i < k-1; i++){
        pos = fp_remover_minimo(v,pos);
        x = v[0];
    }
    return x;
    
}

//----------------------- QUICKMINK -----------------------//

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


int QuickMinK(int *v, int e, int d, int k){
    int q; // POSIÇÃO DO PIVO
    int x; //valor do pivo

    if(k > d && e == 0)
        return v[MAX(v, e ,d)];

    if(e <= d){
        q = partition(v, e, d);
        if(q == k-1)
            return v[q];
        else if(q > k-1)
            x = QuickMinK(v, e, q-1, k);
        else
            x = QuickMinK(v, q, d, k);
    }
    
    return x;
    
}