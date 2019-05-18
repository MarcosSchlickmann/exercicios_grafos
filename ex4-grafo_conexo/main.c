#include "grafo_conexo.h"

int main(void){
	digraph_lista *dir_grafo1 = lista_criaGRAFO(3);
	lista_addARESTA_grafo(dir_grafo1, 0, 1);
	lista_addARESTA_grafo(dir_grafo1, 1, 2);

	if(grafo_conexo(busca_profundidade(dir_grafo1), dir_grafo1->num_vertices)){
		printf("grafo1 é Conexo.\n");
	}else{
		printf("grafo1 não é Conexo.\n");
	}

	digraph_lista *dir_grafo2 = lista_criaGRAFO(5);
	lista_addARESTA_grafo(dir_grafo2, 0, 1);
	lista_addARESTA_grafo(dir_grafo2, 1, 2);
	
	lista_addARESTA_grafo(dir_grafo2, 3, 4);

	if(grafo_conexo(busca_profundidade(dir_grafo2), dir_grafo2->num_vertices)){
		printf("grafo2 é Conexo.\n");
	}else{
		printf("grafo2 não é Conexo.\n");
	}

	return 0;
}