#include "../digraph_lista_adjacencia/digraph_lista_adjacencia.h"
#include "../fila/fila.h"
#include "../heap/heap.h"

#define INFINITO 100000000

typedef struct dijkstra_vertice_info{
	int vertice;
	int dist;
	int pred;
} dij_info;

typedef struct dijkstra_vertice_info{
	dij_info *coluna;
} tabela_dij_info;

tabela_dij_info *dijkstra(digraph_lista *lista, int inicial);

int peso(int origem, int destino);