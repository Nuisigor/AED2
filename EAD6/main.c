#include <stdio.h>
#include <stdlib.h>
#include "buscabinaria.h"
#include "sequencial.h"
#include "MinK.h"
#include "vector.h"
#include <time.h>
#include <string.h>

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int *v = random_vector_unique_elems(n,42);
    int *v1;
    memcpy(v1, v, sizeof(int)*n);
    
    
    return 0;
}
