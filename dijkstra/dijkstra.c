#include "dijkstra.h"

tabela_dij_info *dijkstra(digraph_lista *lista, int inicial){
	tabela_dij_info *tabela_nos = (tabela_dij_info*)malloc(sizeof(tabela_dij_info));
	tabela_nos->vertices = (int*)malloc(lista->num_vertices*sizeof(int));
	tabela_nos->dist = (int*)malloc(lista->num_vertices*sizeof(int));
	tabela_nos->pred = (int*)malloc(lista->num_vertices*sizeof(int));
	tabela_nos->qtd_vertices = 0;
	for(int i = 0; i < lista->num_vertices; i++){
		tabela_nos->dist[i].dist = INFINITO;
		tabela_nos->pred[i].pred = -1;
		tabela_nos = inserir_fila_p(tabela_nos, inicial);
	}
	tabela_nos->pred[inicial].dist = 0;
	
	int u;
	while(!vazia(fila_ver)){
		heap_sort_menor_para_maior(tabela_nos->fila_p, tabela_nos->dist, lista->num_vertices);
		remover_fila_p(tabela_nos, &u);
		no_lista *Adjacente = lista->VETOR_lista_adj[u].prox;
		while(Adjacente){
			if(tabela_nos->coluna[Adjacente->vertice].dist > (tabela_nos->coluna[Adjacente->vertice].dist + peso(u, Adjacente->vertice))){
				tabela_nos->coluna[Adjacente->vertice].dist = tabela_nos->coluna[Adjacente->vertice].dist + peso(u, Adjacente->vertice);
				tabela_nos->coluna[Adjacente->vertice].pred = u;
			}
			Adjacente = Adjacente->prox;
		}
	}
}


int peso(digraph_matriz *matriz_distancias, int origem, int destino){
	for(int i = 0; i < digrafo->numVertice; i++)
		for(int j = 0; j < digrafo->numVertice; j++)
			if(i == origem && j == destino)
				return matriz_distancias->matriz_adj[origem][destino];
}


tabela_dij_info *inserir_fila_p(tabela_dij_info *tabela, int vertice){
	tabela->fila_p[tabela->qtd_vertices] = vertice;
	tabela->qtd_vertices += 1;
	return tabela;
}


tabela_dij_info *remover_fila_p(tabela_dij_info *tabela, int *vertice){
	*vertice = tabela->fila_p[tabela->qtd_vertices - 1];
	tabela->fila_p[tabela->qtd_vertices - 1] = 0;
	tabela->qtd_vertices -= 1;
	return tabela;
}