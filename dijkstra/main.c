#include "dijkstra.h"

int main(void){
	digraph_lista *dir_grafo = lista_criaGRAFO(9);
	digraph_matriz *matriz_pesos = matriz_criaDIGRAFO(9);
	lista_addARESTA(dir_grafo, 1 -1, 2 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 1 -1, 2 -1, 5);
	lista_addARESTA(dir_grafo, 2 -1, 4 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 2 -1, 4 -1, 11);
	lista_addARESTA(dir_grafo, 3 -1, 2 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 3 -1, 2 -1, 7);
	lista_addARESTA(dir_grafo, 4 -1, 5 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 4 -1, 5 -1, 20);
	lista_addARESTA(dir_grafo, 4 -1, 7 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 4 -1, 7 -1, 2);
	lista_addARESTA(dir_grafo, 4 -1, 9 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 4 -1, 9 -1, 4);
	lista_addARESTA(dir_grafo, 5 -1, 3 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 5 -1, 3 -1, 4);
	lista_addARESTA(dir_grafo, 5 -1, 8 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 5 -1, 8 -1, 30);
	lista_addARESTA(dir_grafo, 6 -1, 3 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 6 -1, 3 -1, 3);
	lista_addARESTA(dir_grafo, 6 -1, 8 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 6 -1, 8 -1, 4);
	lista_addARESTA(dir_grafo, 7 -1, 8 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 7 -1, 8 -1, 50);
	lista_addARESTA(dir_grafo, 7 -1, 9 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 7 -1, 9 -1, 3);
	lista_addARESTA(dir_grafo, 9 -1, 1 -1);
	matriz_insere_arco_digrafo_dist(matriz_pesos, 9 -1, 1 -1, 7);
	lista_mostra_grafo(dir_grafo);
	matriz_mostra_digrafo_dist(matriz_pesos);

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