#include "../digraph_lista_adjacencia/digraph_lista_adjacencia.h"

#define VERTICE_BRANCO 0
#define VERTICE_CINZA 1
#define VERTICE_PRETO 2

typedef struct informacao_no_busca_profundidade{
	int vertice;
	int cor;
	int pred;
	int d_tempo;
	int f_tempo;
} info_no_dfs;

typedef struct tabela_informacao_nos_dfs{
	info_no_dfs *coluna_info_no;
	int ciclos;
} tabela_info_nos_dfs;

tabela_info_nos_dfs * busca_profundidade(digraph_lista *lista, int inicial);

tabela_info_nos_dfs *busca_profundidade_visita(digraph_lista *lista, int no, tabela_info_nos_dfs *tabela_info);