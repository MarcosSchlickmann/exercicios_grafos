#include "../dijkstra/dijkstra.h"

int main(void){
	digraph_lista *dir_grafo = lista_criaGRAFO(20);
	digraph_matriz *matriz_pesos = matriz_criaDIGRAFO(20);
	lista_addARESTA_grafo(dir_grafo, 1 -1, 2 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 1 -1, 2 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 1 -1, 3 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 1 -1, 3 -1, 4);
	lista_addARESTA_grafo(dir_grafo, 1 -1, 4 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 1 -1, 4 -1, 1);

	lista_addARESTA_grafo(dir_grafo, 2 -1, 3 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 2 -1, 3 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 2 -1, 5 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 2 -1, 5 -1, 1);
	lista_addARESTA_grafo(dir_grafo, 3 -1, 5 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 3 -1, 5 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 3 -1, 6 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 3 -1, 6 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 4 -1, 6 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 4 -1, 6 -1, 5);
	lista_addARESTA_grafo(dir_grafo, 4 -1, 7 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 4 -1, 7 -1, 4);

	lista_addARESTA_grafo(dir_grafo, 5 -1, 8 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 5 -1, 8 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 6 -1, 8 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 6 -1, 8 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 6 -1, 9 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 6 -1, 9 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 6 -1, 10 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 6 -1, 10 -1, 4);
	lista_addARESTA_grafo(dir_grafo, 6 -1, 7 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 6 -1, 7 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 7 -1, 11 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 7 -1, 11 -1, 2);
	
	lista_addARESTA_grafo(dir_grafo, 8 -1, 15 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 8 -1, 15 -1, 8);
	lista_addARESTA_grafo(dir_grafo, 8 -1, 12 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 8 -1, 12 -1, 6);
	lista_addARESTA_grafo(dir_grafo, 9 -1, 12 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 9 -1, 12 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 9 -1, 13 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 9 -1, 13 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 9 -1, 10 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 9 -1, 10 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 10 -1, 14 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 10 -1, 14 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 10 -1, 11 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 10 -1, 11 -1, 6);
	lista_addARESTA_grafo(dir_grafo, 10 -1, 13 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 10 -1, 13 -1, 6);
	lista_addARESTA_grafo(dir_grafo, 11 -1, 14 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 11 -1, 14 -1, 4);
	lista_addARESTA_grafo(dir_grafo, 11 -1, 18 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 11 -1, 18 -1, 2);
	
	lista_addARESTA_grafo(dir_grafo, 12 -1, 15 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 12 -1, 15 -1, 6);
	lista_addARESTA_grafo(dir_grafo, 12 -1, 13 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 12 -1, 13 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 13 -1, 15 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 13 -1, 15 -1, 4);
	lista_addARESTA_grafo(dir_grafo, 13 -1, 16 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 13 -1, 16 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 13 -1, 14 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 13 -1, 14 -1, 5);
	lista_addARESTA_grafo(dir_grafo, 14 -1, 17 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 14 -1, 17 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 14 -1, 18 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 14 -1, 18 -1, 1);
	
	lista_addARESTA_grafo(dir_grafo, 15 -1, 19 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 15 -1, 19 -1, 6);
	lista_addARESTA_grafo(dir_grafo, 15 -1, 16 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 15 -1, 16 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 16 -1, 19 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 16 -1, 19 -1, 2);
	lista_addARESTA_grafo(dir_grafo, 16 -1, 20 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 16 -1, 20 -1, 1);
	lista_addARESTA_grafo(dir_grafo, 16 -1, 17 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 16 -1, 17 -1, 1);
	lista_addARESTA_grafo(dir_grafo, 17 -1, 20 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 17 -1, 20 -1, 3);
	lista_addARESTA_grafo(dir_grafo, 17 -1, 18 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 17 -1, 18 -1, 8);
	lista_addARESTA_grafo(dir_grafo, 18 -1, 20 -1);
	matriz_insere_arco_grafo_dist(matriz_pesos, 18 -1, 20 -1, 5);


	int origem, destino;
	printf("\n\nDigite o vertice de origem: ");
	scanf("%d", &origem);
	printf("\n\nDigite o vertice de destino: ");
	scanf("%d", &destino);
	tabela_dij_info *tabela_dijkstra = dijkstra(dir_grafo, matriz_pesos, origem -1);

	exibe_tabela_dijkstra(tabela_dijkstra);

	printf("\n\n\n");
	exibe_caminho_mais_proximo(tabela_dijkstra, destino-1);
	return 0;
}