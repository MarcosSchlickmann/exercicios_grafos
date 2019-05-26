#include "digraph_matriz_adjacencia.h"

digraph_matriz *matriz_criaDIGRAFO(int num_vertices){
	digraph_matriz *G = malloc(sizeof(digraph_matriz));
	G->numVertice = num_vertices;
	G->matriz_adj = matriz_criaMatriz(num_vertices, num_vertices, 0);
	return G;
};


int **matriz_criaMatriz(int total_linha, int total_coluna, int valor){
	int coluna, linha;
	int **matriz = (int**)malloc(total_coluna * sizeof(int*));
	for(linha = 0; linha < total_linha; linha++)
		matriz[linha] = (int*)malloc(total_coluna * sizeof(int));
	for(linha = 0; linha < total_linha; linha++)
		for(coluna = 0; coluna < total_coluna; coluna++)
			matriz[linha][coluna] = valor;
	return matriz;
}


void matriz_insere_arco_digrafo(digraph_matriz *digrafo, int origem, int destino){
	if(digrafo->matriz_adj[origem][destino] == 0)
		digrafo->matriz_adj[origem][destino] = 1;
}


void matriz_insere_arco_digrafo_dist(digraph_matriz *digrafo, int origem, int destino, int dist){
	if(digrafo->matriz_adj[origem][destino] == 0)
		digrafo->matriz_adj[origem][destino] = dist;
}


void matriz_insere_arco_grafo(digraph_matriz *digrafo, int origem, int destino){
	matriz_insere_arco_digrafo(digrafo, origem, destino);
	matriz_insere_arco_digrafo(digrafo, destino, origem);
}


void matriz_insere_arco_grafo_dist(digraph_matriz *digrafo, int origem, int destino, int dist){
	matriz_insere_arco_digrafo_dist(digrafo, origem, destino, dist);
	matriz_insere_arco_digrafo_dist(digrafo, destino, origem, dist);
}


void matriz_mostra_digrafo(digraph_matriz *digrafo){
	int origem, destino;
	printf("\nMOSTRA MATRIZ ADJACENCIA DIGRAFO\n");
	printf("   %d %d %d %d %d\n", 0, 1, 2, 3, 4);
	printf("\n");
	for(origem = 0; origem < digrafo->numVertice; origem++){
		printf("%d ", origem);
		for(destino = 0; destino < digrafo->numVertice; destino++){
			printf(" %d", digrafo->matriz_adj[origem][destino]);
		}
		printf(" \n");
	}
}


void matriz_mostra_digrafo_dist(digraph_matriz *digrafo){
	int origem, destino;
	printf("\nMOSTRA MATRIZ ADJACENCIA DIGRAFO\n");
	printf("   ");
	for (int i = 1; i <= digrafo->numVertice; ++i)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("\n");
	for(origem = 0; origem < digrafo->numVertice; origem++){
		printf("%d ", origem+1);
		for(destino = 0; destino < digrafo->numVertice; destino++){
			printf(" %d", digrafo->matriz_adj[origem][destino]);
		}
		printf(" \n");
	}
}


void matriz_remove_arco_digrafo(digraph_matriz *digrafo, int origem, int destino){
	if(digrafo->matriz_adj[origem][destino] == 1)
		digrafo->matriz_adj[origem][destino] = 0;
}


void matriz_remove_arco_grafo(digraph_matriz *digrafo, int origem, int destino){
	if(digrafo->matriz_adj[origem][destino] == 1){
		digrafo->matriz_adj[origem][destino] = 0;
		digrafo->matriz_adj[destino][origem] = 0;
	}
}