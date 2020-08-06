#include <stdio.h>

//  b)
unsigned long int fibonacci_recursivo(int n){
    if(n == 0)   return 0;
    if(n == 1)   return 1;
    return fibonacci_recursivo(n-1) + fibonacci_recursivo( n - 2);
}

//  c)
unsigned long int m[1000] = {0};

unsigned long int fibonacci_memoria(int n){
    if(m[n] == 0){
        if(n == 0 || n == 1) 
            m[n] = n;
        else{
            m[n] = fibonacci_memoria(n-1) + fibonacci_memoria(n-2);
        }
    }
    return m[n];
}

//  d)
unsigned long int fibonacci_interativo(int n){
    unsigned long int n0 = 0, n1 = 1;
    for(; n > 1; n--){
        unsigned long int novo = n0+n1;
        n0 = n1;
        n1 = novo;
    }
    return n1;
}


int main(){
    printf("%ld\n",fibonacci_recursivo(20));
    printf("%ld\n",fibonacci_memoria(20));
    printf("%ld\n",fibonacci_interativo(20));
}