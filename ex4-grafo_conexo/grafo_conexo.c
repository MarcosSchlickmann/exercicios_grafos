#include "grafo_conexo.h"

int grafo_conexo(tabela_info_nos *tabela, int qtd_vertices){
	for (int i = 0; i < qtd_vertices; ++i)
		if(i != 0 && tabela->coluna_info_no[i].pred == -1)
			return 0;
	return 1;
}