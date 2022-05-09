#include <stdio.h>
#include <stdlib.h>

/*
Pilha é uma Estrutura de Dados Simples que possui um ou mais elementos do mesmo
tipo organizados linearmente, isto é, um existe após o outro, sem ramificações.

Em uma pilha existe algumas restrições de operações, sendo possível apenas Inserir e
Remover do topo da Pilha

Aplicações
	- Expressões aritméticas
	- Conversão de dicimal para binário
	- Inversão
	- Qualquer simulação de pilha
	
Tal qual as Listas, uma Pilha pode ser
	ESTÁTICA: se for implementada com vetores
	DINÂMICA: se for implementada usando ponteiros para o próximo elemento

ARQUIVOS
	main.c
	pilhaEstatica.c
	pilhaEstatica.h
	
FUNÇÕES BÁSICAS
	Criar a pilha
	Inserir um elemento no topo da pilha
	Remover um elemento do topo da pilha
	Acessar o elemento no topo da pilha
	Destruir a pilha

pilhaEstatica.h
*/

#define MAX 50 //definição de uma constante

struct aluno {
	int matricula;
	char nome[50];
	float av1;
	float av2;
	float pr;
};

typedef struct pilha Pilha; //definição do struct pilha está no arquivo.c

// Retorna ponteiro pra Pilha ou NULL se alocação não for bem sucedida.
Pilha* criar ();
void destruir (Pilha*);
int tamanho (Pilha*);
int cheia (Pilha*);
int vazia (Pilha*);
int inserir (Pilha*, struct aluno);
int remover(Pilha*);
int acessar(Pilha*, struct aluno*);


/*
pilhaEstatica.c */
#include <stdlib.h>
#include "pilhaEstatica.h"

struct pilha {
	int qtd;
	struct aluno dados[MAX];
};

Pilha* criar () {
	Pilha *pe;
	pe = (Pilha*)malloc(sizeof(Pilha)); //Para evitar acessar a estrutura que não existe por memória por não ter sido alocada corretamente
	if (pe!= NULL) { //para evitar acessar a estrutura que não existe por memória não ter sido alocada corretamente
		pe->qtd = 0;
	}
	return pe;
}

void destruir (Pilha* pe) {
	free(pe); //libera a pilha
}

int tamanho (Pilha* pe) {
	if (pe == NULL) { //se a pilha está vazia
		return -1; //retorna algo que eu não sei
	}
	return pe->qtd; //retorna a quantidade da lista
}

int cheia (Pilha* pe) {
	if (pe == NULL) { //se a pilha está vazia
		return -1; //retorna algo que eu não sei
	}
	else if (pe->qtd == MAX) { //se a quantidade de elementos for igual à constante máxima
		return 1; //retorna true
	}
	else {
		return 0; //retorna false
	}
}

int vazia (Pilha* pe) {
	if (pe == NULL) { //se a pilha está vazia
		return -1; //retornar algo que eu não sei
	}
	else if (pe->qtd == 0) { //se a quantidade de elementos for igual a zero
		return 1; //retorna true
	}
	else {
		return 0; //retorna false
	}
}

int inserir (Pilha* pe, struct aluno novo) {
	if (pe == NULL) //se a pilha estiver vazia
		return 0; //retorna false
	else if (cheia(pe)) //se a pilha estiver cheia
		return 0; //retorna false
	else {
		pe->dados[pe->qtd] = novo; //o último elemento recebe o novo elemento passado
		pe->qtd++; //qtd incrementa
		return 1; //retorna true
	}
}

int remover (Pilha* pe) {
	if (pe == NULL) //verifica se a lista existe
		return 0;
	else if (vazia(pe)) //verifica se a lista está vazia
		return 0;
	else {
		pe->qtd--; //decrementa na quantidade de elementos da lista
		return 1;
	}
}

int acessar (Pilha* pe, struct aluno* a) {
	if (pe == NULL) //verifica se a lista existe
		return 0;
	else if (pe->qtd == 0) //verifica se o número de elementos é igual à 0
		return 0;
	else {
		a* = pe->dados[pe->qtd-1]; //os dados do topo são passados à struct dada
		return 1;
	}
}
/*
main.c */

#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"

int main () {
	Pilha *pratos;
	pratos = NULL;
	pratos = criar();
	return 0:
}
*/