#include <stdio.h>

void sort(int *v, int n){

    for(int i = n; i >= 0; i--){
        int pos = i;

        for(int j = i-1; j >= 0; j--){
            if(v[j] > v[pos]){
                pos = j;
            }
        }
        if(pos == i){}
        else{
            int aux = v[i];
            v[i] = v[pos];
            v[pos] = aux;
        }
    }
}


int main () {
    int v[] = {8,5,6,4,4,2,7};

    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    printf("\n");

    sort(v,7);

    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}