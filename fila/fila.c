#include "fila.h"

Fila *cria(void){
	Fila *fila = (Fila*) malloc(sizeof(Fila));
	fila->ini = fila->fim = NULL;
	return fila;
}


Fila *insere(Fila *fila, float info){
	no_fila *novo = (no_fila*) malloc(sizeof(no_fila));
	novo->info = info;
	novo->prox = NULL;
	if(fila->fim != NULL)
		fila->fim->prox = novo;
	fila->fim = novo;
	if(fila->ini == NULL)
		fila->ini = fila->fim;
	return fila;
}


int retira(Fila *fila){
	int primeiro;
	if(vazia(fila)){
		printf("\nAVISO: fila vazia.\n");
		exit(1);
	}
	primeiro = fila->ini->info;
	no_fila *segundo = fila->ini->prox;
	free(fila->ini);
	fila->ini = segundo;
	if(fila->ini == NULL)
		fila->fim = NULL;
	return primeiro;
}


int vazia(Fila *fila){
	return fila->ini == NULL;
}


void libera(Fila *fila){
	no_fila *elemento = fila->ini;
	while(elemento != NULL){
		no_fila *proximo = elemento->prox;
		free(elemento);
		elemento = proximo;
	}
	free(fila);
}


void imprime(Fila *fila){
	for(no_fila *i; i != NULL; i = i->prox)
		printf("\n%d", i->info);
}