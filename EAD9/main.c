#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_ea.h"

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int* v = random_vector(n, n*10, 42);
    THEA* t_linear = random_hash(v, n, FS_LINEAR);
    printf("Colisões Linear: %d\n", t_linear->colisao);
    THEA* t_quadratica = random_hash(v, n, FS_QUADRATICA);
    printf("Colisões Quadrática: %d\n", t_quadratica->colisao);
    THEA* t_hash_duplo = random_hash(v, n, FS_HASH_DUPLO);
    printf("Colisões Hash Duplo: %d\n", t_hash_duplo->colisao);

    // for(int i = 0; i < t->m; i++){
    //     const char e = t->th[i].estado == E_OCUPADO ? 'O' : (t->th[i].estado == E_LIVRE ? 'L' : 'A');
    //     printf("%d : %d, %c\n", i, t->th[i].chave, e);
    // }
}