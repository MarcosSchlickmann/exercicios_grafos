#include "ex17.h"
#define INFINITO 100000000
int distancias [9] = {
	32, 
	10, 
	3, 
	21, 
	41, 
	0, 
	23, 
	4, 
	25
};
void cria_heap(int vetor[], int inicio, int final){
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


void heap_sort_menor_para_maior(int vetor[], int tamanho){
	int i, aux;

	for(i = (tamanho-1)/2; i >= 0; i--)
		cria_heap(vetor, i, tamanho-i);

	for (i = tamanho-1; i >= 1; i--)
	{
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;
		cria_heap(vetor, 0, i-1);
	}
}
