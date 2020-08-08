#include <stdio.h>

void troca(int *v, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

void bubble_sort(int *v, int n){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j+1])
                troca(v, j, j+1);
        }
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
    bubble_sort(v,sizeof(v)/4);
    printv(v, sizeof(v)/4);
}