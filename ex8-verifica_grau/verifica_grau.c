#include "verifica_grau.h"

int verifica_grau(digraph_lista *lista, int no){
	int grau = 0;
	for(int i = 0; i < lista->num_vertices; i++){
		no_lista *Adjacente = lista->VETOR_lista_adj[i].prox;
		while(Adjacente){
			if(Adjacente->vertice == no){
				grau += 1;
				break;
			}
			Adjacente = Adjacente->prox;
		}
	}
	return grau;
}


void print_grau_todos(digraph_lista *lista){
	for(int i = 0; i < lista->num_vertices; i++)
		printf("Vertice %d possui grau %d\n", i +1, verifica_grau(lista, i));
}