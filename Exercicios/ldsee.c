#include <stdio.h>
#include <stdlib.h>
#include "ldse.h"

//Exercícios de Lista Dinâmica Simplesmente Encadeada

//a) Inserir sem repetição no início. Ao tentar inserir algo com id/matrícula/código (escolha um) a algum que já existe na lista, não permitir.

struct elemento {
	struct aluno dados;
	struct elemento* prox;
}

typedef struct elemento Elemento;

Lista* criar() {
	Lista* ldse = (Lista*)malloc(sizeof(Lista));
	if (ldse != NULL)
		*ldse = NULL;
	return ldse;
}

void destruir(Lista* ldse) {
	if (ldse != NULL) {
		Elemento* aux;
		while (*ldse != NULL) {
			aux = *ldse;
			*ldse = (*ldse)->prox;
			free(aux);
		}
		//free(ldse);
	}
}

int tamanho(Lista* ldse) {
	if (ldse == NULL)
		return 0;
	else if (*ldse == NULL)
		return 0;
	else {
		int qtd = 0;
		Elemento* aux = *ldse;
		while (aux != NULL) {
			aux = aux->prox;
			qtd++;
		}
		printf("Sua lista possue %d elementos!\n", qtd);
		return qtd;
	}
}

int cheia(Lista* ldse) {
	return 0;
}

int vazia(Lista*) {
	if (ldse == NULL)
		return 1;
	else if (*ldse == NULL)
		return 1;
	else {
		return 0;
	}
}
int inserirFim(Lista* ldse, struct aluno novosdados) {
	if (ldse == NULL)
		return 0;
	else {
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
		if (novo == NULL)
			return 0;
		novo->dados = novosdados;
		novo->prox = NULL;
		if (vazia(ldse)) {
			*ldse = novo;
		}
		else {
			Elemento* aux = *ldse;
			while (aux->prox != NULL) {
				aux = aux->prox;
			}
			aux->prox = novo;
		}
		return 1;
	}
}
int inserirInicio(Lista* ldse, struct aluno novosdados) {
	if(ldse == NULL)
		return 0;
	else {
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
		if (novo == NULL)
			return 0;
		novo->dados = novosdados;
		Elemento* aux = *ldse;
	}
}
int inserirOrdenado(Lista*, struct aluno);
int removerFim(Lista*);
int removerInicio (Lista*);
int removerValor(Lista*, int);
int acessarIndice(Lista*, in, struct aluno*);
int acessarValor(Lista*, int, struct aluno*);

