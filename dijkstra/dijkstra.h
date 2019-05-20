#include "../digraph_matriz_adjacencia/digraph_matriz_adjacencia.h"
#include "../digraph_lista_adjacencia/digraph_lista_adjacencia.h"

#include "../heap/heap.h"

#define INFINITO 100000000

typedef struct dijkstra_vertice_info{
	int *fila_p;
	int *dist;
	int *pred;
	int qtd_vertices;
	digraph_matriz *matriz_distancias;
} tabela_dij_info;

tabela_dij_info *dijkstra(digraph_lista *lista, int inicial);

int peso(int origem, int destino);

tabela_dij_info *inserir_fila_p(tabela_dij_info *tabela, int vertice);

tabela_dij_info *remover_fila_p(tabela_dij_info *tabela, int *vertice);