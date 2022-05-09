#include <stdio.h>
#include <stdlib.h>

/*
FILA DINÂMICA

ARQUIVOS
	main.c
	filaDinamica.c
	filaDinamica.h

FUNÇÕES BÁSICAS
	criar a fila
	inserir um elemento no final da fila
	remover um elemento no começo da fila
	acessar o elemento no começo da fila
	destruir a fila

filaDinamica.h */

struct aluno {
	int matricula;
	char nome[50];
	float av1;
	float av2;
	float pr;
};

typedef struct fila Fila; //estamos acostumados a usar ponteiro de ponteiro colocando * aqui
//, mas não será assim com a fila, pois ela terá uma estrutura específica para realizar esse
//apontamento indireto.

Fila* criar ();
void destruir (Fila*);
int tamanho (Fila*);
int cheia (Fila*);
int vazia (Fila*);
int inserir (Fila*, struct aluno);
int remover (Fila*);
int acessar (Fila*, struct aluno*);
/*

filaDinamica.c */

#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

struct elemento {
	struct aluno dados;
	struct elemento *prox;
}:
	
typedef struct elemento Elemento;

struct fila { //estrutura conhecida como nó descritor, pois serve para apontar para os elementos
	struct elemento *inicio; // da Fila
	struct elemento *fim;
};

Fila* criar () {
	Fila* fd; //criação da fila
	fd = (Fila*)malloc(sizeof(Fila)); //alocalão da fila
	if (fd != NULL) { //validação da fila
		fd->inicio = NULL;
		fd->fim = NULL;
	}
	return fd;
}

int tamanho (Fila* fd) {
	if (vazia(fd)) {
		return 0;
	}
	int cont = 0;
	Elemento* aux = fd->inicio; //criação do auxiliar
	while (aux != NULL) { //enquanto auxiliar for diferente de NULL
		cont++; //contador incrementa
		aux = aux->prox; //e auxiliar aponta para o proximo elemento
	}
	return cont;
}

int cheia (Fila* fd) {
	return 0;
}

void destruir (Fila* fd) {
	if (fd != NULL) {
		Elemento *aux;
		while (fd->inicio != NULL) {
			aux = fd->inicio;
			fd->inicio = fd->inicio->prox;
			free(aux);
		}
		fd->fim = NULL
		//free(fd);
	}
}

int inserir (Fila* fd, struct aluno novosdados) {
	if (fd == NULL) {
		return 0;
	}
	else {
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento)); //criação de um novo elemento
		if (novo == NULL) //validação
			return 0;
		novo->dados = novosdados; //elemento recebe dados repassados
		novo->prox = NULL; //o elemento depois desse recebe NULL
		if (fd->fim == NULL) { //se o fim da fila é NULL
			fd->inicio = novo; //o inicio da fila aponta para novo
		}
		else {
			fd->fim->prox = novo; //o fim da fila aponta para o novo elemento
		}
		fd->fim = novo; //fim da fila é o novo elemento
		return 1;
	}
}

int remover (Fila* fd) {
	if(vazia(fd)) {
		return 0;
	}
	else {
		Elemento* aux = fd->inicio;
		fd->inicio = fd->inicio->prox;
		if (fd->inicio == NULL) {
			fd->fim = NULL;
		}
		free(aux);
		return 1;
	}
}

int acessar (Fila* fd, struct aluno* a) {
	if (vazia(fd))
		return 0;
	else {
		*a = fd->inicio->dados;
		return 1;
	}
}
/*
main.c */

#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

int main () {
	Fila* guilhotina;
	guilhotina = NULL;
	guilhotina = criar();
	return 0;
}
/*
*/