#include "busca_largura.h"

tabela_info_nos *busca_largura(digraph_lista * lista_adj, int inicio){
	tabela_info_nos *tabela_nos = (tabela_info_nos*)malloc(sizeof(tabela_info_nos));
	tabela_nos->coluna_info_no = (info_no*)malloc(lista->num_vertices * sizeof(info_no));
	for (int i = 0; i < lista_adj->num_vertices; ++i){
		if(i == inicio)
			continue;
	}
}