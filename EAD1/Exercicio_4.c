#include <stdio.h>

//  b)
int mdc_recursivo(int x, int y){
    if(x >= y && x%y == 0)  return y;
    else if(y > x)   return mdc_recursivo(y , x);
    else    return mdc_recursivo(y, x % y);
}

//  c)
int mdc_iterativo(int x, int y){
    int resto;
    
    if(y > x){
        int temp = y;
        y = x;
        x = temp;
    }

    while(y != 0){
        resto = x % y;
        x = y;
        y = resto;
    }
    return x;
}

int main(){
    printf("%d\n",mdc_recursivo(36,90));
    printf("%d\n",mdc_iterativo(36,90));
}