#include "instagram.h"

int main(void){
	perfis_insta *perfis = inicializa_instagram(9);
	
	digraph_lista *lista_adj = lista_criaGRAFO(9);
	lista_addARESTA(lista_adj, 0, 1);
	lista_addARESTA(lista_adj, 0, 2);
	lista_addARESTA(lista_adj, 0, 3);
	lista_addARESTA(lista_adj, 1, -1);
	lista_addARESTA(lista_adj, 2, 0);
	lista_addARESTA(lista_adj, 2, 4);
	lista_addARESTA(lista_adj, 3, 1);
	lista_addARESTA(lista_adj, 3, 4);
	lista_addARESTA(lista_adj, 3, 5);
	lista_addARESTA(lista_adj, 3, 6);
	lista_addARESTA(lista_adj, 4, 3);
	lista_addARESTA(lista_adj, 4, 5);
	lista_addARESTA(lista_adj, 4, 6);
	lista_addARESTA(lista_adj, 5, 7);
	lista_addARESTA(lista_adj, 5, 8);
	lista_addARESTA(lista_adj, 6, 8);
	lista_addARESTA(lista_adj, 7, 5);
	lista_addARESTA(lista_adj, 7, 8);
	lista_addARESTA(lista_adj, 8, -1);
	print_pessoa_mais_popular(lista_adj, perfis);
	print_quantidade_seguidores(lista_adj, perfis, 3);
	print_perfis_que_seguem_mais_velhos(lista_adj, perfis);
	return 0;
}