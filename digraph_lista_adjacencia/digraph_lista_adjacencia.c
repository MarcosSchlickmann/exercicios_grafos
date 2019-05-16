#include "digraph_lista_adjacencia.h"

grafo_t *criaGRAFO(int n){
	int i;
	grafo_t *grafo = (grafo_t*)malloc(sizeof(grafo_t));
	if(!grafo){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O GRAFO \n SAINDO...\n");
		exit(500);
	}

	grafo->num_vertices = n;

	grafo->VETOR_lista_adj = (no_t*)malloc(n * sizeof(no_t));
	if(!grafo->VETOR_lista_adj){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O VETOR DE LISTA ADJACENTE \n SAINDO...\n");
		exit(500);
	}

	for(i = 0; i < n; i++)
		grafo->VETOR_lista_adj[i].prox = NULL;

	return grafo;
}


void addARESTA(grafo_t *grafo, int origem, int dest){
	no_t *novoNO = criaNO(dest);
	novoNO->prox = grafo->VETOR_lista_adj[origem].prox;
	grafo->VETOR_lista_adj[origem].prox = novoNO;
}


void addARESTA_grafo(grafo_t *grafo, int origem, int dest){
	no_t *novoNO = criaNO(origem);
	novoNO->prox = grafo->VETOR_lista_adj[dest].prox;
	grafo->VETOR_lista_adj[dest].prox = novoNO;


}


no_t *criaNO(int v){
	no_t *novoNO = (no_t*)malloc(sizeof(no_t));
	if(!novoNO){
		printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA UM NOVO NO \n SAINDO...\n");
		exit(500);		
	}
	novoNO->vertice = v;
	novoNO->prox = NULL;
	return novoNO;
}


void destroiGRAFO(grafo_t* grafo){
	if(grafo){
		if(grafo->VETOR_lista_adj){
			int v;
			for(v = 0; v < grafo->num_vertices; v++){
				no_t *Primeiro = grafo->VETOR_lista_adj[v].prox;
				while(Primeiro){
					no_t *tmp = Primeiro;
					Primeiro = Primeiro->prox;
					free(tmp);
				}
			}
			free(grafo->VETOR_lista_adj);
		}
		free(grafo);
	}
}


void mostra_grafo(grafo_t *grafo){
	int i;
	for(i = 0; i < grafo->num_vertices; i++){
		printf("\n%d  ", i);
		no_t *Primeiro = grafo->VETOR_lista_adj[i].prox;
		while(Primeiro){
			printf("%d ", Primeiro->vertice);
			Primeiro = Primeiro->prox;
		}
	}
}