#include <stdio.h>

// b)
unsigned long int comites_recursivo(int n, int k){
    if(k > n)   return 0;
    else if( k == 1) return n;

    return comites_recursivo(n - 1, k) + comites_recursivo(n - 1, k - 1);
}

// c)
unsigned long int m[1000][1000] = {0};

unsigned long int comites_memoria(int n, int k){
    if(m[n][k] == 0){
        if(k > n)   return 0;
        if(k == 1)   return n;
        m[n][k] = comites_memoria(n-1 , k) + comites_memoria( n - 1, k - 1);
    }
    return m[n][k];
}

int main(){
    printf("%ld\n",comites_recursivo(7,4));
    printf("%ld\n",comites_memoria(7,4));
}
