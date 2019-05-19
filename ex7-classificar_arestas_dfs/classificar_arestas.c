#include "../busca_profundidade/busca_profundidade.h"

int main(void){
	digraph_lista *dir_grafo = lista_criaGRAFO(9);
	lista_addARESTA(dir_grafo, 1 -1, 2 -1);
	lista_addARESTA(dir_grafo, 2 -1, 3 -1);
	lista_addARESTA(dir_grafo, 2 -1, 4 -1);
	lista_addARESTA(dir_grafo, 3 -1, 2 -1);
	lista_addARESTA(dir_grafo, 4 -1, 5 -1);
	lista_addARESTA(dir_grafo, 4 -1, 7 -1);
	lista_addARESTA(dir_grafo, 5 -1, 3 -1);
	lista_addARESTA(dir_grafo, 5 -1, 8 -1);
	lista_addARESTA(dir_grafo, 6 -1, 8 -1);
	lista_addARESTA(dir_grafo, 9 -1, 1 -1);
	tabela_info_nos_dfs *tabela_nos = busca_profundidade(dir_grafo, 1 -1);
	printf("\n");
	for(int i = 0; i <= tabela_nos->qtd_arestas; i++){
		if(tabela_nos->class_arestas_tabela[i].classificacao_aresta){
			printf("Aresta entre %d e %d: ", tabela_nos->class_arestas_tabela[i].vertice_origem+1, tabela_nos->class_arestas_tabela[i].vertice_destino+1);
			print_tipo_aresta(tabela_nos->class_arestas_tabela[i].classificacao_aresta);
		}
	}
}