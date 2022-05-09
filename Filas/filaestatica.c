#include <stdio.h>
#include <stdlib.h>

/*
FILAS

Fila é una Estrutura de Dados Simples que possui um ou mais elementos do mesmo tipo
organizados linearmente, isto é, um existe após o outro, sem ramificações.
Em uma Fila existe algumas restrições de operações, sendo possível apenas Inserir no final
da Fila e Remover no começo da Fila.

APLICAÇÕES

	Qualquer fila, meus jovens

Tal qual as Listas, uma Fila pode ser
	ESTÁTICA: se for implementada com vetores
	DINÂMICA: se for implementada usando ponteiro para o próximo elemento

ARQUIVOS

	main.c
	filaEstatica.c
	filaEstatica.h

FUNÇÕES BÁSICAS
	Criar a fila
	Inserir um elemento no final da fila
	Remover um elemento no começo da fila
	Acessar o elemento no começo da fila
	Destruir a fila

filaEstatica.h */

#define MAX 50 //definição de uma constante

struct aluno {
	int matricula;
	char nome[50];
	float av1;
	float av2;
	float pr;
};

typedef struct fila Fila; //definição do struct está no arquivo.c

Fila* criar(); //Assinatura/protótipo da função está no arquivo.c

/*
filaEstatica.c */

#include <stdlib.h>
#include "filaEstatica.h"

struct fila {
	int qtd, inicio, fim; //teremos todas essas informações para facilitar a inserção e remoção da Fila
	struct aluno dados[MAX]; //caso contrário, o processamento seria elevado
};

Fila* criar() {
	Fila* fe;
	fe = (Fila*)malloc(sizeof(Fila));
	if (fe != NULL) { //para evitar acessar a estrutura que não existe por memória não ter sido alocada corretamente
		fe->qtd = 0;
		fe->inicio = 0;
		fe->fim = 0;
	}
	return fe;
}
/*
main.c */

#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

int main () {
	Fila* guilhotina;
	guilhotina = NULL;
	guilhotina = criar();
	return 0;
}
*/