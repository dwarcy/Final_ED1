#include "cardapio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 15

struct item{
    int codigo;
    char nome[MAX];
    float valor;
};

struct node{
    int c;
    Item itens[3];
    struct node *next;
};

struct lista{
    Node *head;
};

Node *novoNo(){
    Node *n;
    n = malloc(sizeof(Node));
    return n;
}

Lista *criar(){
    Lista *l;

    l = malloc(sizeof(Lista));
    if(l != NULL) l->head = NULL; //lista vazia
    
    return l; //se alocação nao funcionar, retorna NULL
}

bool vazia(Lista *l){
    if (l->head == NULL)
    {
        return true; //lista está vazia
    } else return false; 
    
}

bool cheia(Lista *l){
    return false;
}

//insere novo nó e o preenche com as informações
bool insere(Lista *l, int codigo, Item *itens){
    Node *P;
    Node *P_auxiliar, *P_anterior;

    //criar novo nó
    P = novoNo();
    if (P == NULL)
    {
        return false; //retorna deuCerto = false 
    }
    P->c = codigo;
    //vetor do parametro pra dentro do nó
    P->itens[0] = itens[0];
    P->itens[1] = itens[1];
    P->itens[2] = itens[2];
    
    //CASO 1: lista esta vazia
    if (vazia(l) == true)
    {
        l->head = P;
        P->next = NULL;
    }
    
    P_auxiliar = l->head;

    //percorre a lista para achar qual o ultimo nó
    P_anterior = NULL;
    while (P_auxiliar->next != NULL && P->c > P_auxiliar->c) {
    	P_anterior = P_auxiliar;
    	P_auxiliar = P_auxiliar->next;
    }

    //CASO 2: insere na ultima 
    if (P_auxiliar->next == NULL && P->c > P_auxiliar->c) {
    	P->next = P_auxiliar->next;
    	P_auxiliar->next = P;
    	return true;
    }

}