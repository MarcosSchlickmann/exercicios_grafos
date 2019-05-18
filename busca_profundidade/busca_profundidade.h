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
	int vertices_que_acessa;
} info_no;

typedef struct tabela_informacao_nos{
	info_no *coluna_info_no;
	int ciclos;
} tabela_info_nos;

tabela_info_nos *busca_profundidade(digraph_lista *lista);

tabela_info_nos *busca_profundidade_visita(digraph_lista *lista, int no, tabela_info_nos *tabela_info);