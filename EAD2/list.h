#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}no;

typedef struct Lista{
    no* primeiro;
    no* ultimo;
    int qtde;
}Lista;


Lista* lista_criar();
void lista_destruir(Lista* l);
void lista_inserir(Lista* l, Tipo elemento, int posicao);
void lista_inserir_fim(Lista* l, Tipo elemento);
int* lista_remover1(Lista* l, int posicao);
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);
Boolean lista_remover_elemento(Lista* l, Tipo elemento);
Boolean lista_buscar(Lista* l, int posicao, int* endereco);
Boolean lista_contem(Lista* l, Tipo elemento);
int lista_posicao(Lista* l, Tipo elemento);
int lista_tamanho(Lista* l);
void lista_imprimir(Lista* l);

Lista* lista_criar(){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    l->primeiro = l->ultimo = NULL;
    l->qtde = 0;
    
    return l;
}

void lista_destruir(Lista* l){
    no* aux = l->primeiro;
    no* aux2;

    for(int i = 0; i < l->qtde; i++){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    free(l);
}

no* getno(Tipo elemento){
    no* n = (no*) malloc(sizeof(no));
    n->dado = elemento;
    n->ant = n->prox = NULL;

    return n;
}

void lista_inserir(Lista* l, Tipo elemento, int posicao){
    if(elemento == NULL)    return;
    if(l == NULL)   return;

    if(l->qtde == 0){
        no* n = getno(elemento);
        l->primeiro = l->ultimo = n;
        l->qtde++;
    }
    else if(posicao == 0){
        no* n = getno(elemento);

        l->primeiro->ant = n;
        n->prox = l->primeiro;
        l->primeiro = n;

        l->qtde++;
    }
    else if(posicao == l->qtde){
        no* n = getno(elemento);

        l->ultimo->prox = n;
        n->ant = l->ultimo;
        l->ultimo = n;

        l->qtde++;
    }
    else if(posicao > 0 && posicao < l->qtde){
        no* n = getno(elemento);
        
        no* aux = l->primeiro;
        int i = 0;

        while(i != posicao){
            aux = aux->prox;
            i++;
        }
        
        aux->prox->ant = n;
        n->prox = aux->prox;
        n->ant = aux;
        aux->prox = n;
        
        l->qtde++;
    }

}