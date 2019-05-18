#include "busca_profundidade.h"

int tempo;

tabela_info_nos * busca_profundidade(digraph_lista *lista){
	tabela_info_nos *tabela_nos = (tabela_info_nos*)malloc(sizeof(tabela_info_nos));
	tabela_nos->coluna_info_no = (info_no*)malloc(lista->num_vertices * sizeof(info_no));
	tabela_nos->ciclos = 0;
	for (int i = 0; i < lista->num_vertices; ++i){
		tabela_nos->coluna_info_no[i].cor = VERTICE_BRANCO;
		tabela_nos->coluna_info_no[i].pred = -1;
	}
	tempo = 0;
	for(int u = 0; u < lista->num_vertices; u++)
		if(tabela_nos->coluna_info_no[u].cor == VERTICE_BRANCO)
			tabela_nos = busca_profundidade_visita(lista, u, tabela_nos);
	return tabela_nos;
}


tabela_info_nos *busca_profundidade_visita(digraph_lista *lista, int no, tabela_info_nos *tabela_info){
	tabela_info->coluna_info_no[no].cor = VERTICE_CINZA;
	tempo += 1;
	tabela_info->coluna_info_no[no].d_tempo = tempo;

	no_t *Adjacente = lista->VETOR_lista_adj[no].prox;
	while(Adjacente){
		if(tabela_info->coluna_info_no[Adjacente->vertice].cor == VERTICE_CINZA){
			tabela_info->ciclos += 1;
		}
		if(tabela_info->coluna_info_no[Adjacente->vertice].cor == VERTICE_BRANCO){
			tabela_info->coluna_info_no[Adjacente->vertice].pred = no;
			tabela_info = busca_profundidade_visita(lista, Adjacente->vertice, tabela_info);
		}
		Adjacente = Adjacente->prox;
	}
	tabela_info->coluna_info_no[no].cor = VERTICE_PRETO;
	tempo += 1;
	tabela_info->coluna_info_no[no].f_tempo = tempo;
	return tabela_info;
}