#include <stdio.h>

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

void printv(int *v, int n){
    printf("[ ");
    for(int i = 0; i < n; i++){
        if(i == n-1)
            printf("%d ]\n",v[i]);
        else
            printf("%d, ",v[i]);
    }
}


int main(){
    int v[] = {2,6,88,4,6,9,55};
    printv(v, sizeof(v)/4);
    insertion_sort(v,sizeof(v)/4);
    printv(v, sizeof(v)/4);
}