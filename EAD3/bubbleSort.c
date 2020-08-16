#include "quickSort.h"


int bubble_Sort(int *v, int n){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j+1])
                troca(v, j, j+1);
        }
    }
}
