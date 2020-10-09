#include "abb.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
// a. Insira as chaves na sequência: 70, 39, 88. Remova 70.
    ABB* a = NULL;
    ABB_Inserir(&a, 70);
    ABB_Inserir(&a, 39);
    ABB_Inserir(&a, 88);
    ABB_Remover(&a, 70);
    ABB_Imprimir(a);
    printf("*********************************************************************************************\n");
// b. Insira as chaves na sequência: 10, 4, 20, 6, 2, 3, 5, 7. Remova: 10, 4, 5.
    ABB* b = NULL;
    ABB_Inserir(&b, 10);
    ABB_Inserir(&b, 4);
    ABB_Inserir(&b, 20);
    ABB_Inserir(&b, 6);
    ABB_Inserir(&b, 2);
    ABB_Inserir(&b, 3);
    ABB_Inserir(&b, 5);
    ABB_Inserir(&b, 7);
    ABB_Remover(&b, 10);
    ABB_Remover(&b, 4);
    ABB_Remover(&b, 5);
    ABB_Imprimir(b);
    printf("*********************************************************************************************\n");
// c. Insira as chaves na sequência: 30, 50, 40, 47, 15, 20, 25, 17, 19, 4, 7, 0. Remova: 0, 30, 15, 20.
    ABB* c = NULL;
    ABB_Inserir(&c, 30);
    ABB_Inserir(&c, 50);
    ABB_Inserir(&c, 40);
    ABB_Inserir(&c, 47);
    ABB_Inserir(&c, 15);
    ABB_Inserir(&c, 20);
    ABB_Inserir(&c, 25);
    ABB_Inserir(&c, 17);
    ABB_Inserir(&c, 19);
    ABB_Inserir(&c, 4);
    ABB_Inserir(&c, 7);
    ABB_Inserir(&c, 0);
    ABB_Remover(&c, 0);
    ABB_Remover(&c, 30);
    ABB_Remover(&c, 15);
    ABB_Remover(&c, 20);
    ABB_Imprimir(c);
}