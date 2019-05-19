#include "../digraph_lista_adjacencia/digraph_lista_adjacencia.h"

#define VERTICE_BRANCO 0
#define VERTICE_CINZA 1
#define VERTICE_PRETO 2
#define INFINITO 1000000
typedef struct informacao_no_busca_largura{
	int vertice;
	int cor;
	int pred;
	int dist;
} info_no;

typedef struct tabela_informacao_nos{
	info_no *coluna_info_no;
} tabela_info_nos;

tabela_info_nos *busca_largura(digraph_lista * lista_adj, int inicio);