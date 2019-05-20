#include "dijkstra.h"

tabela_dij_info *dijkstra(digraph_lista *lista, int inicial){
	tabela_dij_info *tabela_nos = (tabela_dij_info*)malloc(sizeof(tabela_dij_info));
	tabela_nos->coluna = (dij_info*)malloc(lista->num_vertices * sizeof(dij_info));
	for(int i = 0; i < lista->num_vertices; i++){
		tabela_nos->coluna[i].dist = INFINITO;
		tabela_nos->coluna[i].pred = -1;
	}
	tabela_nos->coluna[inicial].dist = 0;
	Fila fila_ver = cria();
	fila_ver = insere(fila_ver, inicial);
	int u;
	while(!vazia(fila_ver)){
		u = retira(fila_ver);
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