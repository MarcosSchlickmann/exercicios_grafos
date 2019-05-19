#include "fila.h"

int main(void){
	Fila * f = cria();
	f = insere(f, 1);
	f = insere(f, 2);
	f = insere(f, 3);
	f = insere(f, 4);
	f = insere(f, 5);
	printf("%d\n", retira(f));
	printf("%d\n", retira(f));
	printf("%d\n", retira(f));
	printf("%d\n", retira(f));
	printf("%d\n", retira(f));
	printf("%d\n", retira(f));
}