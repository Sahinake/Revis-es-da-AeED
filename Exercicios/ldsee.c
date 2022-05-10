#include <stdio.h>
#include <stdlib.h>
#include "ldse.h"

//Exercícios de Lista Dinâmica Simplesmente Encadeada

struct elemento {
	struct aluno dados;
	struct elemento* prox;
};

struct informacoes {
	int qtd;
	int pares;
	int impares;
	int maior;
	int menor;
};

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

//a) Inserir sem repetição no início. Ao tentar inserir algo com
// id/matrícula/código (escolha um) a algum que já existe na lista, não permitir.
int inserirInicio(Lista* ldse, struct aluno novosdados) {
	if(ldse == NULL)
		return 0;
	else {
		Elemento* aux = *ldse;
		while (aux->dados.matricula != novo->dados.matricula && aux != NULL) {
			aux = aux->prox;
		}
		if (aux->dados.matricula == novo->dados.matricula)
			return 0;
		else {
			Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
			if (novo == NULL)
				return 0;
			novo->dados = novosdados;
			novo->prox = *ldse;
			*ldse = novo;
			return 1;
		}
	}
}
int inserirOrdenado(Lista* ldse, struct aluno novosdados) {
	if (ldse == NULL)
		return 0;
	else {
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
		if (novo == NULL)
			return 0;
		novo->dados = novosdados;
		if (*ldse == NULL || (*ldse)->dados.matricula > novo->dados.matricula) {
			novo->prox = *ldse;
			*ldse = novo;
		}
		else {
			Elemento* ant = *ldse;
			Elemento* ant = *ldse;
			while(novo->dados.matricula > aux->dados.matricula && aux != NULL) {
				ant = aux;
				aux = aux->prox;
			}
			ant->prox = novo;
			novo->prox = aux;
		}
		return 1;
	}
}
int removerFim(Lista* ldse) {
	if (ldse == NULL) {
		return 0;
	}
	else if ((*ldse)->prox == NULL) {
		Elemento* aux = *ldse;
		*ldse = aux->prox;
		free(aux);
		return 1;
	}
	else {
		Elemento* ant = *ldse;
		Elemento* aux = ant->prox;
		while (aux->prox != NULL) {
			ant = aux;
			aux = aux->prox;
		}
		ant->prox = aux->prox;
		free(aux);
		return 1;
	}
}

int removerInicio (Lista* ldse) {
	if (ldse == NULL)
		return 0;
	else {
		Elemento* aux = *ldse;
		*ldse = aux->prox;
		free(aux);
		return 1;
	}
}
int removerValor(Lista* ldse, int vlr) {
	if (ldse == NULL || *ldse = NULL)
		return 0;
	else if ((*ldse)->dados.matricula == vlr) {
		Elemento* aux = *ldse;
		*ldse = aux->prox;
		free(aux);
		return 1;
	}
	else {
		Elemento* ant = *ldse;
		Elemento* aux = ant->prox;
		while (aux->dados.matricula != vlr && aux != NULL) {
			ant = aux;
			aux = aux->prox;
		}
		if (aux == NULL)
			return 0;
		ant->prox = aux->prox;
		free(aux);
		return 1;
		
	}
}
int acessarIndice(Lista* ldse, int pos, struct aluno* a) {
	if (ldse == NULL || *ldse == NULL)
		return 0;
	else if (pos <= 0){
		return 0;
	}
	else {
		int cont = 0;
		Elemento* aux = *ldse;
		while (aux != NULL e pos != cont) {
			aux = aux->prox;
			cont++;
		}
		if (aux == NULL)
			return 0;
		*a = aux->dados;
		return 1;
	}
}
int acessarValor(Lista* ldse, int vlr, struct aluno* a) {
	if (ldse == NULL || *ldse == NULL)
		return 0;
	else {
		Elemento* aux = *ldse;
		while (aux->dados.matricula != vlr && aux != NULL) {
			aux = aux->prox;
		}
		if (aux == NULL)
			return 0;
		*a = aux->dados;
		return 1;
		
	}
}

//b) Informações. Dizer quantos impares, pares, maior e menor valor de uma lista.
int informacoes (Lista* ldse, Info inf) {
	if(vazia(ldse))
		return 0;
	else {
		Info* info =
		int maior = *ldse, menor = *ldse;
		if ()
	}
}

