#include "grafo_orientado.h"

int grafo_orientado(digraph_lista *lista){
	int i, encontrou;
	for(i = 0; i < lista->num_vertices; i++){
		no_t *Primeiro = lista->VETOR_lista_adj[i].prox;
		while(Primeiro){
			no_t *Segundo = lista->VETOR_lista_adj[Primeiro->vertice].prox;
			while(Segundo){
				if(Segundo->vertice == i){
					encontrou = 1;
					break;
				}
				Segundo = Segundo->prox;
			}
			if(!encontrou)
				return 0;
			encontrou = 0;
			Primeiro = Primeiro->prox;
		}
	}
	return 1;
}