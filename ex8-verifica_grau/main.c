#include "verifica_grau.h"

int main(void){
	digraph_lista *dir_grafo = lista_criaGRAFO(9);
	lista_addARESTA(dir_grafo, 1 -1, 2 -1);
	lista_addARESTA(dir_grafo, 2 -1, 3 -1);
	lista_addARESTA(dir_grafo, 2 -1, 4 -1);
	lista_addARESTA(dir_grafo, 3 -1, 2 -1);
	lista_addARESTA(dir_grafo, 4 -1, 5 -1);
	lista_addARESTA(dir_grafo, 4 -1, 7 -1);
	lista_addARESTA(dir_grafo, 5 -1, 3 -1);
	lista_addARESTA(dir_grafo, 5 -1, 8 -1);
	lista_addARESTA(dir_grafo, 6 -1, 8 -1);
	lista_addARESTA(dir_grafo, 9 -1, 1 -1);

	print_grau_todos(dir_grafo);
}