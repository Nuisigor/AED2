#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_ea.h"

int main(int argc, char** argv){
    FILE * testes;
    testes = fopen("testes.txt", "a+");
    if(testes != NULL){
        int n = atoi(argv[1]);
        int m = atoi(argv[2]);
        THEA* t = random_hash(n, m, 10*n, 42);
        fprintf(testes, "%d\t %d\t %.3f\t\t %.3f\t\t %.3f\t\t %d\n",t->m, t->N, (float)t->N/t->m, THEA_TamMedioClusters(t), THEA_CustoBemSucedida(t), THEA_ClusterMaximo(t));
        // for(int i = 0; i < t->m; i++){
        //     const char e = t->th[i].estado == E_OCUPADO ? 'O' : (t->th[i].estado == E_LIVRE ? 'L' : 'A');
        //     printf("%d : %d, %c\n", i, t->th[i].chave, e);
        // }
        // fprintf(testes,"M\t N\t a\t CustoMal\t CustoBem\t MaiorC\n");
        printf("Cluster max = %d\n", THEA_ClusterMaximo(t));
        printf("Tam medio Cluster = %f\n", THEA_TamMedioClusters(t));
        printf("Cutso bem sucedido = %f\n", THEA_CustoBemSucedida(t));
    }
    fclose(testes);
}