#include "ex2-lista_para_matriz.h"

int main(){
	digraph_lista *digrafo_lista = lista_criaGRAFO(3);
	lista_addARESTA_grafo(digrafo_lista, 0, 1);
	lista_addARESTA_grafo(digrafo_lista, 1, 2);
	lista_addARESTA_grafo(digrafo_lista, 2, 0);
	lista_mostra_grafo(digrafo_lista);

	digraph_matriz *digrafo_matriz = matriz_criaDIGRAFO(3);
	matriz_insere_arco_grafo(digrafo_matriz, 0, 1);
	matriz_insere_arco_grafo(digrafo_matriz, 1, 2);
	matriz_insere_arco_grafo(digrafo_matriz, 2, 0);
	matriz_mostra_digrafo(digrafo_matriz);

	printf("\n\n\n");

	digraph_matriz *matriz_digrafo_lista = lista_para_matriz(digrafo_lista);
	matriz_mostra_digrafo(matriz_digrafo_lista);
}