#include "grafo_orientado.h"

int grafo_orientado(digraph_lista *lista){
	int i, encontrou;
	for(i = 0; i < lista->num_vertices; i++){
		no_lista *Primeiro = lista->VETOR_lista_adj[i].prox;
		while(Primeiro){// Itera pelos adjacentes de todos os vertices
			// E verifica se também é adjacente deles
			no_lista *Segundo = lista->VETOR_lista_adj[Primeiro->vertice].prox;
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