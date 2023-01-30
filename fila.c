#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fila.h"

struct node_fila{
    char nome[20];
    FILE *com;
    struct node_fila *next;
};

struct fila{
    No *primeiro;
    No *ultimo;
};

No *novo_no_fila(){
    No *n;
    n = malloc(sizeof(No));
    
    return n;
}

Fila *cria_f(){
    Fila *f;

    f =(Fila*) malloc(sizeof(Fila));

    if (f == NULL)
    {
        printf("Nao foi possivel alocar memoria.\n");
    }

    f->primeiro = NULL;
    f->ultimo = NULL;

    return f;    
}

void insere_fila(Fila *f,char cliente[],FILE *comanda){
    //printf("oi\n");
    No *novo;

    novo = novo_no_fila();
    novo->com = comanda;
    strcpy(novo->nome,cliente);
    novo->next = NULL;
    
    //printf("oi\n");
    if (f->primeiro == NULL)
    {
        //printf("oie\n");
        f->primeiro = novo; 
    } else f->ultimo->next = novo;
    //printf("oi\n");

    f->ultimo = novo;   
}

void remove_fila(Fila *f){
    No *auxilar;

    auxilar = f->primeiro;

    if (f->primeiro == NULL) //fila está vazia
    {
        printf("Fila esta vazia.\n");
    } else {
        f->primeiro = f->primeiro->next;

        free(auxilar);
    }
}

void imprime_Fila(Fila *f){
    No *aux;

    aux = f->primeiro;

    printf("///////////////////////////////////////////////////\n");
    printf("\t\tFila de clientes: \n");

    int i = 0;
    while (aux != NULL)
    {   
        printf("%d- ", i+1);
        printf("%s\n",aux->nome);
        aux = aux->next;

        i++;
    }
    printf("\n");    
}
