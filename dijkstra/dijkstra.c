#include "dijkstra.h"

tabela_dij_info *dijkstra(digraph_lista *lista, digraph_matriz *matriz_pesos, int inicial){
	tabela_dij_info *tabela_nos = (tabela_dij_info*)malloc(sizeof(tabela_dij_info));
	tabela_nos->fila_p = (int*)malloc(lista->num_vertices*sizeof(int));
	tabela_nos->dist = (int*)malloc(lista->num_vertices*sizeof(int));
	tabela_nos->pred = (int*)malloc(lista->num_vertices*sizeof(int));
	tabela_nos->matriz_distancias = matriz_pesos;
	tabela_nos->qtd_vertices = 0;
	for(int i = 0; i < lista->num_vertices; i++){
		tabela_nos->dist[i] = INFINITO;
		tabela_nos->pred[i] = -1;
		tabela_nos = inserir_fila_p(tabela_nos, i);
	}
	tabela_nos->dist[inicial] = 0;
	
	int u;
	while(tabela_nos->qtd_vertices > 0){
		heap_sort_menor_para_maior(tabela_nos->fila_p, tabela_nos->dist, lista->num_vertices);
		remover_fila_p(tabela_nos, &u);
		no_lista *Adjacente = lista->VETOR_lista_adj[u].prox;
		while(Adjacente){
			if(tabela_nos->dist[Adjacente->vertice] > (tabela_nos->dist[u] + peso(tabela_nos->matriz_distancias, u, Adjacente->vertice))){
				tabela_nos->dist[Adjacente->vertice] = tabela_nos->dist[u] + peso(tabela_nos->matriz_distancias, u, Adjacente->vertice);
				tabela_nos->pred[Adjacente->vertice] = u;
			}
			Adjacente = Adjacente->prox;
		}
	}

	return tabela_nos;
}


int peso(digraph_matriz *matriz_distancias, int origem, int destino){
	for(int i = 0; i < matriz_distancias->numVertice; i++)
		for(int j = 0; j < matriz_distancias->numVertice; j++)
			if(i == origem && j == destino)
				return matriz_distancias->matriz_adj[origem][destino];
	return -1;
}


tabela_dij_info *inserir_fila_p(tabela_dij_info *tabela, int vertice){
	tabela->fila_p[tabela->qtd_vertices] = vertice;
	tabela->qtd_vertices += 1;
	return tabela;
}


tabela_dij_info *remover_fila_p(tabela_dij_info *tabela, int *vertice){
	*vertice = tabela->fila_p[0];
	for (int i = 1; i <= tabela->qtd_vertices; ++i)
		tabela->fila_p[i-1] = tabela->fila_p[i];
	tabela->qtd_vertices -= 1;
	return tabela;
}


void exibe_tabela_dijkstra(tabela_dij_info *tabela){
	printf("\n  ");
	for (int i = 0; i < tabela->matriz_distancias->numVertice; ++i){
		if(i + 1 < 10){
			printf("0%d ", i+1);
		} else{
			printf("%d ", i+1);
		}
	}
	printf("\n");
	printf("\n");
	printf("d ");
	for (int d = 0; d < tabela->matriz_distancias->numVertice; ++d){
		if(tabela->dist[d] >= 10){
			printf("%d ", tabela->dist[d]);
		}else{
			printf("0%d ", tabela->dist[d]);
		}
	}
	printf("\n");
	printf("p ");
	for (int p = 0; p < tabela->matriz_distancias->numVertice; ++p){
		if(tabela->pred[p] + 1 < 10){
			printf("0%d ", tabela->pred[p] + 1);
		} else{
			printf("%d ", tabela->pred[p] + 1);
		}
	}
	printf("\n");
}


void exibe_caminho_mais_proximo(tabela_dij_info *tabela, int destino){
	if(tabela->pred[destino] > -1){
		printf("Do vertice %d ao vertice %d com custo %d\n", tabela->pred[destino]+1, destino+1, tabela->dist[destino]);
		exibe_caminho_mais_proximo(tabela, tabela->pred[destino]);
	}
}