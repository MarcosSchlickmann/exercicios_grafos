#include "grafo_orientado.h"

int main(void){
	digraph_lista *dir_grafo1 = lista_criaGRAFO(3);
	lista_addARESTA_grafo(dir_grafo1, 0, 1);
	lista_addARESTA_grafo(dir_grafo1, 1, 2);
	lista_mostra_grafo(dir_grafo1);


	if(grafo_orientado(dir_grafo1)){
		printf("\ngrafo1 nao e orientado.\n");
	}else{
		printf("\ngrafo1 e orientado.\n");
	}

	digraph_lista *dir_grafo2 = lista_criaGRAFO(3);
	lista_addARESTA(dir_grafo2, 0, 1);
	lista_addARESTA(dir_grafo2, 1, 2);
	lista_mostra_grafo(dir_grafo2);


	if(grafo_orientado(dir_grafo2)){
		printf("\ngrafo2 nao e orientado.\n");
	}else{
		printf("\ngrafo2 e orientado.\n");
	}

	return 0;
}