#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int vertice;
	struct no *prox;
} no_t;

typedef struct grafo{
	int num_vertices;
	no_t *VETOR_lista_adj;	
} grafo_t;

grafo_t *criaGRAFO(int n);

void addARESTA(grafo_t *grafo, int origem, int dest);

void addARESTA_grafo(grafo_t *grafo, int origem, int dest);

no_t *criaNO(int v);

void destroiGRAFO(grafo_t* grafo);

void mostra_grafo(grafo_t *grafo);