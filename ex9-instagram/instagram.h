#include <string.h>
#include "../ex8-verifica_grau/verifica_grau.h"

typedef struct instagram_perfil {
	int id;
	int idade;
	char nome[20];
	int qtd_seguidores;
} perfil_insta;

typedef struct instagram_perfis {
	int qtd;
	perfil_insta *perfis;
} perfis_insta;

perfis_insta *inicializa_instagram(int qtd);

void print_pessoa_mais_popular(digraph_lista *lista_adj, perfis_insta *perfis);

void print_quantidade_seguidores(digraph_lista *lista_adj, perfis_insta *perfis, int id);

void print_perfis_que_seguem_mais_velhos(digraph_lista *lista_adj, perfis_insta *perfis);