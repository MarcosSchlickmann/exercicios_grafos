#include "digraph_matriz_adjacencia.h"

int main(){
	digraph_matriz *digrafo = matriz_criaDIGRAFO(5);
	matriz_insere_arco_grafo(digrafo, 0, 1);
	matriz_insere_arco_grafo(digrafo, 0, 4);
	matriz_insere_arco_grafo(digrafo, 1, 2);
	matriz_insere_arco_grafo(digrafo, 2, 3);
	matriz_insere_arco_grafo(digrafo, 3, 0);
	matriz_insere_arco_grafo(digrafo, 3, 4);

	matriz_mostra_digrafo(digrafo);

	matriz_remove_arco_grafo(digrafo, 0, 4);
	matriz_remove_arco_grafo(digrafo, 2, 3);

	matriz_mostra_digrafo(digrafo);
	return 0;
}