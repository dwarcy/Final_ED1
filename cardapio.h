//paradinha que faz rodar o cardápio
//interface - aaa
//apenas declarando variaveis
#ifndef cardapio
#define cardapio

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 15

//DECLARANDO AS STRUCTS USADA NO CODIGO
typedef struct item Item;

typedef struct node Node;

typedef struct lista Lista;

//DECLARANDO AS FUNÇÕES
Node *novoNo();
Lista *criar();
bool vazia(Lista *l);
bool cheia(Lista *l);
bool insere(Lista *l, int codigo, Item *itens);

#endif