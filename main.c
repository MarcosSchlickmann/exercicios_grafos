#include "digraph/digraph.h"

int main(){
	tipo_digrafo *digrafo = criaDIGRAFO(5);
	insere_arco_grafo(digrafo, 0, 1);
	insere_arco_grafo(digrafo, 0, 4);
	insere_arco_grafo(digrafo, 1, 2);
	insere_arco_grafo(digrafo, 2, 3);
	insere_arco_grafo(digrafo, 3, 0);
	insere_arco_grafo(digrafo, 3, 4);

	mostra_digrafo(digrafo);

	remove_arco_grafo(digrafo, 0, 4);
	remove_arco_grafo(digrafo, 2, 3);

	mostra_digrafo(digrafo);
	return 0;
}