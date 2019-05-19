#include "instagram.h"

perfis_insta *inicializa_instagram(int qtd){
	perfis_insta *perfis = (perfis_insta*)malloc(sizeof(perfis_insta));
	perfis->perfis = (perfil_insta*)malloc(qtd * sizeof(perfil_insta));

	perfis->perfis[0].id = 0;
	perfis->perfis[0].idade = 25;
	strcpy(perfis->perfis[0].nome, "Joao");

	perfis->perfis[1].id = 1;
	perfis->perfis[1].idade = 20;
	strcpy(perfis->perfis[1].nome, "Caio");

	perfis->perfis[2].id = 2;
	perfis->perfis[2].idade = 23;
	strcpy(perfis->perfis[2].nome, "Ana");
	
	perfis->perfis[3].id = 3;
	perfis->perfis[3].idade = 20;
	strcpy(perfis->perfis[3].nome, "Pedro");
	
	perfis->perfis[4].id = 4;
	perfis->perfis[4].idade = 30;
	strcpy(perfis->perfis[4].nome, "Jane");
	
	perfis->perfis[5].id = 5;
	perfis->perfis[5].idade = 19;
	strcpy(perfis->perfis[5].nome, "Marcos");
	
	perfis->perfis[6].id = 6;
	perfis->perfis[6].idade = 23;
	strcpy(perfis->perfis[6].nome, "Bruna");
	
	perfis->perfis[7].id = 7;
	perfis->perfis[7].idade = 20;
	strcpy(perfis->perfis[7].nome, "Felipe");
	
	perfis->perfis[8].id = 8;
	perfis->perfis[8].idade = 35;
	strcpy(perfis->perfis[8].nome, "Renata");
	
	return perfis;
}


void print_pessoa_mais_popular(digraph_lista *lista_adj, perfis_insta *perfis){
	int maior_grau = -2;
	for(int i = 0; i < lista_adj->num_vertices; i++){
		perfis->perfis[i].qtd_seguidores = verifica_grau(lista_adj, i);
		if(verifica_grau(lista_adj, i) > maior_grau)
			maior_grau = verifica_grau(lista_adj, i);
	}
	for (int j = 0; j < lista_adj->num_vertices; ++j)
		if(perfis->perfis[j].qtd_seguidores == maior_grau)
			printf("Pessoa popular: %s, com %d seguidores\n", perfis->perfis[j].nome, maior_grau);
}


void print_quantidade_seguidores(digraph_lista *lista_adj, perfis_insta *perfis, int id){
	int segue = 0;
	no_lista *Adjacente = lista_adj->VETOR_lista_adj[id].prox;
	while(Adjacente){
		segue += 1;
		Adjacente = Adjacente->prox;
	}
	printf("%s segue %d pessoas.\n", perfis->perfis[id].nome, segue);
}


void print_perfis_que_seguem_mais_velhos(digraph_lista *lista_adj, perfis_insta *perfis){
	int idade;
	int segue_mais_jovens;
	for(int i = 0; i < lista_adj->num_vertices; i++){
		segue_mais_jovens = 0;
		idade = perfis->perfis[i].idade;
		no_lista *Adjacente = lista_adj->VETOR_lista_adj[i].prox;
		while(Adjacente){
			if(perfis->perfis[Adjacente->vertice].idade <= idade){
				segue_mais_jovens = 1;
				break;
			}
			Adjacente = Adjacente->prox;
		}
		if(!segue_mais_jovens)
			printf("%s so segue pessoas mais velhas.\n", perfis->perfis[i].nome);
	}
}