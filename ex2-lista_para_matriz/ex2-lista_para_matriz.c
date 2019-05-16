#include "ex2-lista_para_matriz.h"

digraph_matriz* lista_para_matriz(digraph_lista *digrafo_lista){
	digraph_matriz *digrafo_matriz = matriz_criaDIGRAFO(digrafo_lista->num_vertices);
	int i;
	for(i = 0; i < digrafo_lista->num_vertices; i++){
		no_t *Primeiro = digrafo_lista->VETOR_lista_adj[i].prox;
		while(Primeiro){
			matriz_insere_arco_digrafo(digrafo_matriz, i, Primeiro->vertice);
			Primeiro = Primeiro->prox;
		}
	}
	return digrafo_matriz;
}