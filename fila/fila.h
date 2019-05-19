#include <stdio.h>
#include <stdlib.h>

typedef struct no_fila
{
	int info;
	struct no_fila *prox;
} no_fila;

typedef struct fila_incio_fim{
	no_fila *ini;
	no_fila *fim;
} Fila;

Fila *cria(void);

Fila *insere(Fila *fila, float info);

int retira(Fila *fila);

int vazia(Fila *fila);

void libera(Fila *fila);

void imprime(Fila *fila);