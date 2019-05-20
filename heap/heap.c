#include "heap.h"
#define INFINITO 100000000

void cria_heap(int vetor[], int distancias[], int inicio, int final){
	int aux = vetor[inicio];
	int filho = inicio * 2 + 1;

	while(filho <= final){
		if(filho < final)
			if(distancias[vetor[filho]] < distancias[vetor[filho + 1]])
				filho = filho + 1;
		if(distancias[aux] < distancias[vetor[filho]]){
			vetor[inicio] = vetor[filho];
			inicio = filho;
			filho = 2 * inicio + 1;
		} else
			filho = final + 1;
	} 
	vetor[inicio] = aux;
}


void heap_sort_menor_para_maior(int vetor[], int distancias[], int tamanho){
	int i, aux;

	for(i = (tamanho-1)/2; i >= 0; i--)
		cria_heap(vetor, distancias, i, tamanho-i);

	for (i = tamanho-1; i >= 1; i--)
	{
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;
		cria_heap(vetor, distancias, 0, i-1);
	}
}
