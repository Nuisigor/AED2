#include <stdio.h>
#include <stdlib.h>
#include "asciitrie.h"

int main(int argc, char** argv){
    char* nome = argv[1];
    int L = atoi(argv[2]);
    FILE* arq  = fopen(nome, "r");

    fseek(arq, 0, SEEK_END);
    int tam = ftell(arq);
    fseek(arq, 0, SEEK_SET);

    char* string = malloc(sizeof(char)*(tam+1));
    fread(string, sizeof(char), tam, arq);
    string[tam] = '\0';
    fclose(arq);

    printf("Quantidade = %d\n",SubstringCountLenL(string, L));
}
