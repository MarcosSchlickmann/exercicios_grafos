#include "ex1-matriz_para_lista.h"

digraph_lista* matriz_para_lista(digraph_matriz *digrafo_matriz){
	digraph_lista *digrafo_lista = lista_criaGRAFO(digrafo_matriz->numVertice);
	int origem, destino;
	// Itera por todos os vertices na matriz, verificando se possuem ligação
	for(origem = 0; origem < digrafo_matriz->numVertice; origem++){
		for(destino = 0; destino < digrafo_matriz->numVertice; destino++){
			if(digrafo_matriz->matriz_adj[origem][destino])
				lista_addARESTA(digrafo_lista, origem, destino);// Adiciona à lista caso possuírem
		}
	}
	return digrafo_lista;
}