#include "digraph_lista_adjacencia.h"

digraph_lista *lista_criaGRAFO(int n){
	int i;
	digraph_lista *grafo = (digraph_lista*)malloc(sizeof(digraph_lista));
	if(!grafo){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O GRAFO \n SAINDO...\n");
		exit(500);
	}

	grafo->num_vertices = n;

	grafo->VETOR_lista_adj = (no_lista*)malloc(n * sizeof(no_lista));
	if(!grafo->VETOR_lista_adj){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O VETOR DE LISTA ADJACENTE \n SAINDO...\n");
		exit(500);
	}

	for(i = 0; i < n; i++)
		grafo->VETOR_lista_adj[i].prox = NULL;

	return grafo;
}


void lista_addARESTA(digraph_lista *grafo, int origem, int dest){
	no_lista *novoNO = lista_criaNO(dest);
	novoNO->prox = grafo->VETOR_lista_adj[origem].prox;
	grafo->VETOR_lista_adj[origem].prox = novoNO;
}


void lista_addARESTA_grafo(digraph_lista *grafo, int origem, int dest){
	no_lista *novoNO1 = lista_criaNO(dest);
	novoNO1->prox = grafo->VETOR_lista_adj[origem].prox;
	grafo->VETOR_lista_adj[origem].prox = novoNO1;

	no_lista *novoNO2 = lista_criaNO(origem);
	novoNO2->prox = grafo->VETOR_lista_adj[dest].prox;
	grafo->VETOR_lista_adj[dest].prox = novoNO2;
}


no_lista *lista_criaNO(int v){
	no_lista *novoNO = (no_lista*)malloc(sizeof(no_lista));
	if(!novoNO){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA UM NOVO NO \n SAINDO...\n");
		exit(500);		
	}
	novoNO->vertice = v;
	novoNO->prox = NULL;
	return novoNO;
}


void lista_destroiGRAFO(digraph_lista* grafo){
	if(grafo){
		if(grafo->VETOR_lista_adj){
			int v;
			for(v = 0; v < grafo->num_vertices; v++){
				no_lista *Primeiro = grafo->VETOR_lista_adj[v].prox;
				while(Primeiro){
					no_lista *tmp = Primeiro;
					Primeiro = Primeiro->prox;
					free(tmp);
				}
			}
			free(grafo->VETOR_lista_adj);
		}
		free(grafo);
	}
}


void lista_mostra_grafo(digraph_lista *grafo){
	int i;
	for(i = 0; i < grafo->num_vertices; i++){
		printf("\n%d  ", i);
		no_lista *Primeiro = grafo->VETOR_lista_adj[i].prox;
		while(Primeiro){
			printf("%d ", Primeiro->vertice);
			Primeiro = Primeiro->prox;
		}
	}
}