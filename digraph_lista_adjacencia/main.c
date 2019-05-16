#include "digraph_lista_adjacencia.h"

int main(){
	digraph_lista *dir_grafo = lista_criaGRAFO(5);
	lista_addARESTA_grafo(dir_grafo, 0, 1);
	lista_addARESTA_grafo(dir_grafo, 0, 4);
	lista_addARESTA_grafo(dir_grafo, 1, 2);
	lista_addARESTA_grafo(dir_grafo, 1, 3);
	lista_addARESTA_grafo(dir_grafo, 1, 4);
	lista_addARESTA_grafo(dir_grafo, 2, 3);
	lista_addARESTA_grafo(dir_grafo, 3, 4);
	lista_mostra_grafo(dir_grafo);
	return 0;
}