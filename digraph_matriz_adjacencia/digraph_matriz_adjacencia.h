#include <stdio.h>
#include <stdlib.h>

typedef struct digraph{
		int numVertice;
		int **matriz_adj;
} digraph_matriz;


digraph_matriz *matriz_criaDIGRAFO(int num_vertices);

int **matriz_criaMatriz(int total_linha, int total_coluna, int valor);

void matriz_insere_arco_digrafo(digraph_matriz *digrafo, int origem, int destino);

void matriz_insere_arco_grafo(digraph_matriz *digrafo, int origem, int destino);

void matriz_mostra_digrafo(digraph_matriz *digrafo);

void matriz_remove_arco_digrafo(digraph_matriz *digrafo, int origem, int destino);

void matriz_remove_arco_grafo(digraph_matriz *digrafo, int origem, int destino);