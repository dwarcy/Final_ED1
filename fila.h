#ifndef fila_cliente
#define fila_cliente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_fila No;
typedef struct fila Fila;

No *novo_no_fila();
Fila *cria_f();
void insere_fila(Fila *f,char cliente[],FILE *comanda);
void remove_fila(Fila *f);
void imprime_Fila(Fila *f);


#endif