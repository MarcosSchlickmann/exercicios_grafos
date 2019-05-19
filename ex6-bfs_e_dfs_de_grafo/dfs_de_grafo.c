#include "../busca_profundidade/busca_profundidade.h"

int main(void){
	digraph_lista *dir_grafo = lista_criaGRAFO(9);
	lista_addARESTA(dir_grafo, 5 -1, 3 -1);
	lista_addARESTA(dir_grafo, 5 -1, 4 -1);
	lista_addARESTA(dir_grafo, 1 -1, 2 -1);
	lista_addARESTA(dir_grafo, 1 -1, 9 -1);
	lista_addARESTA(dir_grafo, 2 -1, 3 -1);
	lista_addARESTA(dir_grafo, 3 -1, 5 -1);
	lista_addARESTA(dir_grafo, 3 -1, 6 -1);
	lista_addARESTA(dir_grafo, 4 -1, 2 -1);
	lista_addARESTA(dir_grafo, 4 -1, 7 -1);
	lista_addARESTA(dir_grafo, 6 -1, 8 -1);
	lista_addARESTA(dir_grafo, 7 -1, 8 -1);
	lista_addARESTA(dir_grafo, 8 -1, 5 -1);
	lista_addARESTA(dir_grafo, 9 -1, 1 -1);

	tabela_info_nos_dfs *tabela_nos = busca_profundidade(dir_grafo, 5-1);

	printf("\n\nu  ");
	for(int a = 0; a < 9; a++)
		printf(" %d ", a+1);
	
	printf("\ncor");
	for (int j = 0; j < dir_grafo->num_vertices; ++j)
	{
		printf(" %d ", tabela_nos->coluna_info_no[j].cor);
	}
	printf("\npre");
	for (int i = 0; i < dir_grafo->num_vertices; ++i)
	{
		printf(" %d ", tabela_nos->coluna_info_no[i].pred+1);
	}
	printf("\nd  ");
	for (int i = 0; i < dir_grafo->num_vertices; ++i)
	{
		printf(" %d ", tabela_nos->coluna_info_no[i].d_tempo);
	}
	printf("\nf  ");
	for (int i = 0; i < dir_grafo->num_vertices; ++i)
	{
		printf(" %d ", tabela_nos->coluna_info_no[i].f_tempo);
	}
	printf("\nCiclos: %d\n", tabela_nos->ciclos);
}