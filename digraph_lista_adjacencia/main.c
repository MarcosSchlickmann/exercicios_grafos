#include "digraph_lista_adjacencia.h"

int main(){
	grafo_t *dir_grafo = criaGRAFO(5);
	addARESTA(dir_grafo, 0, 1);
	addARESTA(dir_grafo, 0, 4);
	addARESTA(dir_grafo, 1, 2);
	addARESTA(dir_grafo, 1, 3);
	addARESTA(dir_grafo, 1, 4);
	addARESTA(dir_grafo, 2, 3);
	addARESTA(dir_grafo, 3, 4);
	mostra_grafo(dir_grafo);
	return 0;
}