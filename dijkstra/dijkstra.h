#include "../digraph_matriz_adjacencia/digraph_matriz_adjacencia.h"
#include "../digraph_lista_adjacencia/digraph_lista_adjacencia.h"

#include "../heap/heap.h"

#define INFINITO 100000

typedef struct dijkstra_vertice_info{
	int *fila_p;
	int *dist;
	int *pred;
	int qtd_vertices;
	digraph_matriz *matriz_distancias;
} tabela_dij_info;

tabela_dij_info *dijkstra(digraph_lista *lista, digraph_matriz *matriz_pesos, int inicial);

int peso(digraph_matriz *matriz_distancias, int origem, int destino);

tabela_dij_info *inserir_fila_p(tabela_dij_info *tabela, int vertice);

tabela_dij_info *remover_fila_p(tabela_dij_info *tabela, int *vertice);

void exibe_tabela_dijkstra(tabela_dij_info *tabela);

void exibe_caminho_mais_proximo(tabela_dij_info *tabela, int destino);