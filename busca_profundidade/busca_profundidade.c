#include "busca_profundidade.h"

int tempo;

tabela_info_nos_dfs * busca_profundidade(digraph_lista *lista, int inicial){
	tabela_info_nos_dfs *tabela_nos = (tabela_info_nos_dfs*)malloc(sizeof(tabela_info_nos_dfs));
	tabela_nos->coluna_info_no = (info_no_dfs*)malloc(lista->num_vertices * sizeof(info_no_dfs));
	tabela_nos->class_arestas_tabela = (class_aresta*)malloc(MAX_ARESTAS * sizeof(class_aresta));
	tabela_nos->qtd_arestas = 0;

	tabela_nos->ciclos = 0;
	for (int i = 0; i < lista->num_vertices; ++i){
		tabela_nos->coluna_info_no[i].cor = VERTICE_BRANCO;
		tabela_nos->coluna_info_no[i].pred = -1;
	}
	tempo = 0;
	if(inicial)
		tabela_nos = busca_profundidade_visita(lista, inicial, tabela_nos);
	for(int u = 0; u < lista->num_vertices; u++)
		if(tabela_nos->coluna_info_no[u].cor == VERTICE_BRANCO)
			tabela_nos = busca_profundidade_visita(lista, u, tabela_nos);
	return tabela_nos;
}


tabela_info_nos_dfs *busca_profundidade_visita(digraph_lista *lista, int no, tabela_info_nos_dfs *tabela_info){
	tabela_info->coluna_info_no[no].cor = VERTICE_CINZA;
	tempo += 1;
	tabela_info->coluna_info_no[no].d_tempo = tempo;

	no_lista *Adjacente = lista->VETOR_lista_adj[no].prox;
	while(Adjacente){
		tabela_info->qtd_arestas += 1;
		tabela_info->class_arestas_tabela[tabela_info->qtd_arestas].vertice_origem = no;
		tabela_info->class_arestas_tabela[tabela_info->qtd_arestas].vertice_destino = Adjacente->vertice;
		if(tabela_info->coluna_info_no[Adjacente->vertice].cor == VERTICE_CINZA){
			tabela_info->ciclos += 1;
			tabela_info->class_arestas_tabela[tabela_info->qtd_arestas].classificacao_aresta = ARESTA_RETORNO;
		}
		if(tabela_info->coluna_info_no[Adjacente->vertice].cor == VERTICE_PRETO){
			if(raiz(tabela_info, no) == raiz(tabela_info, Adjacente->vertice)){
				tabela_info->class_arestas_tabela[tabela_info->qtd_arestas].classificacao_aresta = ARESTA_DIRETA;	
			}else{
				tabela_info->class_arestas_tabela[tabela_info->qtd_arestas].classificacao_aresta = ARESTA_CRUZADA;	
			}
		}
		if(tabela_info->coluna_info_no[Adjacente->vertice].cor == VERTICE_BRANCO){
			tabela_info->class_arestas_tabela[tabela_info->qtd_arestas].classificacao_aresta = ARESTA_ARVORE;	
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


int raiz(tabela_info_nos_dfs *tabela, int no){
	if(tabela->coluna_info_no[no].pred == -1)
		return no;
	return raiz(tabela, tabela->coluna_info_no[no].pred);
}


void print_tipo_aresta(int i){
	switch(i){
		case ARESTA_ARVORE:
			printf("ARESTA ARVORE.\n");
			break;
		case ARESTA_RETORNO:
			printf("ARESTA RETORNO.\n");
			break;
		case ARESTA_DIRETA:
			printf("ARESTA DIRETA.\n");
			break;
		case ARESTA_CRUZADA:
			printf("ARESTA CRUZADA.\n");
			break;
		default:
			printf("AVISO: aresta nao reconhecida.\n");
	}
}