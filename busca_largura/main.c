#include "busca_largura.h"

int main(void){
	digraph_lista *dir_grafo = lista_criaGRAFO(3);
	lista_addARESTA_grafo(dir_grafo, 0, 1);
	lista_addARESTA_grafo(dir_grafo, 1, 2);
	lista_mostra_grafo(dir_grafo);
	tabela_info_nos_bfs *tabela_nos = busca_largura(dir_grafo, 2);

	printf("\n\nu  ");
	for(int a = 0; a < 3; a++)
		printf(" %d ", a);
	
	printf("\ncor");
	for (int j = 0; j < dir_grafo->num_vertices; ++j)
	{
		printf(" %d ", tabela_nos->coluna_info_no[j].cor);
	}
	printf("\npre");
	for (int i = 0; i < dir_grafo->num_vertices; ++i)
	{
		printf(" %d ", tabela_nos->coluna_info_no[i].pred);
	}
	printf("\nd  ");
	for (int i = 0; i < dir_grafo->num_vertices; ++i)
	{
		printf(" %d ", tabela_nos->coluna_info_no[i].dist);
	}
}