#include "busca_largura.h"

tabela_info_nos_bfs *busca_largura(digraph_lista * lista_adj, int inicio){
	tabela_info_nos_bfs *tabela_nos = (tabela_info_nos_bfs*)malloc(sizeof(tabela_info_nos_bfs));
	tabela_nos->coluna_info_no = (info_no_bfs*)malloc(lista_adj->num_vertices * sizeof(info_no_bfs));
	for (int i = 0; i < lista_adj->num_vertices; ++i){
		if(i == inicio)
			continue;
		tabela_nos->coluna_info_no[i].cor = VERTICE_BRANCO;
		tabela_nos->coluna_info_no[i].dist = INFINITO;
		tabela_nos->coluna_info_no[i].pred = -1;
	}
	tabela_nos->coluna_info_no[inicio].cor = VERTICE_CINZA;
	tabela_nos->coluna_info_no[inicio].dist = 0;
	tabela_nos->coluna_info_no[inicio].pred = -1;

	Fila *fila = cria();
	int indice;
	fila = insere(fila, inicio);
	while(!vazia(fila)){
		indice = retira(fila);
		no_lista *Adjacente = lista_adj->VETOR_lista_adj[indice].prox;
		while(Adjacente){
			if(tabela_nos->coluna_info_no[Adjacente->vertice].cor == VERTICE_BRANCO){
				tabela_nos->coluna_info_no[Adjacente->vertice].cor = VERTICE_CINZA;
				tabela_nos->coluna_info_no[Adjacente->vertice].dist = tabela_nos->coluna_info_no[indice].dist + 1;
				tabela_nos->coluna_info_no[Adjacente->vertice].pred = indice;
				fila = insere(fila, Adjacente->vertice);
			}
			Adjacente = Adjacente->prox;
		}
		tabela_nos->coluna_info_no[indice].cor = VERTICE_PRETO;
	}
	libera(fila);
	return tabela_nos;
}