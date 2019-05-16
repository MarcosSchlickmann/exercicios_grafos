#include "ex1-matriz_para_lista.h"

int main(){
	digraph_matriz *digrafo_matriz = matriz_criaDIGRAFO(3);
	matriz_insere_arco_grafo(digrafo_matriz, 0, 1);
	matriz_insere_arco_grafo(digrafo_matriz, 1, 2);
	matriz_insere_arco_grafo(digrafo_matriz, 2, 0);
	matriz_mostra_digrafo(digrafo_matriz);

	digraph_lista *digrafo_lista = lista_criaGRAFO(3);
	lista_addARESTA_grafo(digrafo_lista, 0, 1);
	lista_addARESTA_grafo(digrafo_lista, 1, 2);
	lista_addARESTA_grafo(digrafo_lista, 2, 0);
	lista_mostra_grafo(digrafo_lista);

	printf("\n\n\n");

	digraph_lista *lista_digrafo_matriz = matriz_para_lista(digrafo_matriz);
	lista_mostra_grafo(lista_digrafo_matriz);
}