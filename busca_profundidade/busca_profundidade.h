#include "../digraph_lista_adjacencia/digraph_lista_adjacencia.h"

#define VERTICE_BRANCO 0
#define VERTICE_CINZA 1
#define VERTICE_PRETO 2

#define MAX_ARESTAS 10000
#define ARESTA_ARVORE 1
#define ARESTA_RETORNO 2
#define ARESTA_DIRETA 3
#define ARESTA_CRUZADA 4

typedef struct informacao_no_busca_profundidade{
	int vertice;
	int cor;
	int pred;
	int d_tempo;
	int f_tempo;
} info_no_dfs;

typedef struct classificacao_aresta_dfs{
	int vertice_origem;
	int vertice_destino;
	int classificacao_aresta;
} class_aresta;

typedef struct tabela_informacao_nos_dfs{
	info_no_dfs *coluna_info_no;
	int ciclos;
	class_aresta *class_arestas_tabela;
	int qtd_arestas;
} tabela_info_nos_dfs;


tabela_info_nos_dfs * busca_profundidade(digraph_lista *lista, int inicial);

tabela_info_nos_dfs *busca_profundidade_visita(digraph_lista *lista, int no, tabela_info_nos_dfs *tabela_info);

int raiz(tabela_info_nos_dfs *tabela, int no);

void print_tipo_aresta(int i);