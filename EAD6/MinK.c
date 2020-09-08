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

int SelectionMinK(int *v, int n, int k){
    if(k >= n)
        return v[MAX(v, 0, n-1)];
    else{
        int i;
        int maior, pos;
        for(i = n-1; i > k-2; i--){
            maior = MAX(v,0,i);
            troca(v, maior, i);
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

int HeapMinK(int *v, int n, int k){
    int i;
    buildMinHeap(v,n);
    for(i = n-1; i > 0; i--){
        troca(v, 0 , i);
        minHeapify(v, 0, i);
    }
    if(k > n)
        return v[0];
    else
        return v[n-k];
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