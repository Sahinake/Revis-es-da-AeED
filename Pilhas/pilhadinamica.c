#include <stdio.h>
#include <stdlib.h>

/*
PILHA DINÂMICA

pilhaDinamica.h
*/

struct aluno {
	int matricula;
	char nome[50];
	float av1;
	float av2;
	float pr;
};

typedef struct elemento* Pilha //mesma ideia da lista dinâmica

Pilha* criar();

/*
pilhaDinamica.c*/

#include <stdlib.h>
#include "pilhaDinamica.h"

struct elemento {
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elemento;
Pilha* criar () {
	Pilha* pd; //cria uma struct elemento;
	pe = (Pilha*)malloc(sizeof(Pilha)); //aloca memória para a pilha
	if (pe != NULL) { //se a pilha for diferente de NULL
		*pe = NULL; //a pilha aponta para NULL
	}
	return pe; //retorna pilha
}

int vazia (Pilha* pd) {
	if (pd == NULL) //verifica se a pilha está vazia
		return 1;
	else if (*pd == NULL) //verifica se a pilha aponta para o vazio
		return 1;
	else {
		return 0;
	}
}

int inserir (Pilha* pd, struct aluno novosdados) {
	if (pd == NULL) { //verifica se a pilha existe
		return 0;
	}
	else {
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento)); //cria um novo elemento
		if (novo == NULL) //verifica se foi alocado com sucesso
			return 0;
		novo->dados = novosdados; //o novo elemento recebe os dados passados
		novo->prox = *pd; //o novo elemento aponta para o topo da pilha
		*pd = novo; //a pilha aponta para o novo elemento
		return 1;
	}
}

int remover (Pilha* pd) {
	if (vazia(pd)) { //verifica se a pilha está vazia
		return 0;
	}
	else {
		Elemento *aux = *pd; //criação de um elemento auxiliar apontando para o topo da pilha
		*pd = aux->prox; //pilha aponta para o segundo elemento da pilha
		free(aux); //o primeiro elemento é excluido juntamente com o auxiliar
		return 1;
	}
}

int acessar(Pilha *pd, struct aluno* a) {
	if (vazia(pd)) //verifica se a pilha está vazia
		return 0;
	else {
		*a = (*pd)->dados; //retorna o topo da pilha
		return 1;
	}
}

void destruir (Pilha* pd) {
	if (pd != NULL) { //se a pilha for diferente de NULL
		Elemento* aux; //cria um auxiliar
		while (*pd != NULL) { //enquanto a pilha apontar para diferente de NULL
			aux = *pd; //auxiliar aponta para o topo da pilha
			*pd = (*pd)->prox; //a pilha aponta para o próximo elemento
			free(aux); //o topo é excluído juntamente com o auxiliar
		}
		free(pd); //after all, a pilha é limpa completamente
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

int main () {
	Pilha *oppa;
	oppa = NULL;
	oppa = criar();
	return 0;
}