#include <stdio.h>
#include <stdlib.h>



typedef struct no{
	int vertice;
	struct no *prox;
} no_t;

typedef struct grafo{
	int num_vertices;
	no_t *VETOR_lista_adj;	
} digraph_lista;

digraph_lista *lista_criaGRAFO(int n);

void lista_addARESTA(digraph_lista *grafo, int origem, int dest);

void lista_addARESTA_grafo(digraph_lista *grafo, int origem, int dest);

no_t *lista_criaNO(int v);

void lista_destroiGRAFO(digraph_lista* grafo);

void lista_mostra_grafo(digraph_lista *grafo);