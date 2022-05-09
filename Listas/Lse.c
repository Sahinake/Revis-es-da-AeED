#include <stdio.h>
#include <stdlib.h>

/* LISTAS

Lista � uma Estrutura de Dados Simples que possui um ou mais elementos do mesmo tipo organizados linearmente,
isto �, um existe ap�s o outro, sem ramifica��es.

Caso a lista tenha zero elementos, ela � dita vazia.

Aplica��es:
	- Cadastro de funcion�rios;
	- Itens em estoque;
	- Baralho de cartas;
	
OPERA��ES B�SICAS

* Criar a lista
* Inserir um elemento
* Excluir um elemento
* Acessar um elemento
* Destruir um elemento

TIPOS 

Uma lista pode ser:
	EST�TICA: se for implementada com vetores;
	DIN�MICA: se for implementada usando ponteiro para o pr�ximo elemento;
	
E tamb�m pode ser:
	HOMOG�NEA: se armazenar apenas um tipo de dado primitivo;
	HETEROG�NEA: caso contr�rio; //seria no caso, onde cada elemento seria uma struct;
	
LISTA SEQUENCIAL EST�TICA

Lista no qual o sucessor de um elemento ocupa a pr�xima posi��o de mem�ria, pois � implementada com um vetor.

Vantagens: 
	- Acesso r�pido e direto aos elementos pelo �ndice;
	- Tempo constante para acessar um elemento;
	- Facilidade em modificar informa�oes;

Desvantagens:
	- Defini��o pr�via do tamanho;
		* Mem�ria alocada em compila��o.
	- Limite de tamanho (MAX)
	- Dificuldade para inserir ou remover elementos no come�o da lista ou entre dois j� existentes;
		* Voc� precisa deslocar a lista inteira.

Implementa��o passo-a-passo de acordo com os arquivos usando TAD e as fun��es b�sicas necess�rias:
ARQUIVOS
	* main.c
	* listaSequencialEstatica(lse).c
	* listaSequencialEstatica (lse).h
FUN��ES B�SICAS
	* Criar a lista
	* Inserir um elemento
	* Excluir um elemento	
	* Acessar um elemento
	* Destruir a lista

listaSequencialEstatica.h */

#define MAX 50 //defini��o de uma constante

struct aluno {
	int matricula;
	char nome[50];
	float av1;
	float av2;
	float pr;
}; //nesse exemplo, cada elemento da lista ser� um struct com v�rios dados -> lista heterog�nea

typedef struct lista Lista; //defini��o do struct lista est� no arquivo .c

Lista* criar (); //assinatura/prot�tipo da fun��o que est� no arquivo .c
void destruir (Lista*);
int tamanho (Lista*);
int cheia (Lista*);
int vazia (Lista*);
int inserirFim (Lista*, struct aluno);
int inserirInicio (Lista*, struct aluno);
int removerFim (Lista*);
int removerInicio (Lista*);
int removerValor (Lista*, int);
int acessarIndice (Lista*, int, struct aluno*);
int acessarValor (Lista*, int, struct aluno*);

/*

listaSequencialEstatica.c */

#include <stdlib.h>
#include "listaSequencialEstatica.h" //precisa incluir .h por conta de:
										// Tamanho m�ximo, estrutura do Aluno e Novo tipo nomeado Lista
struct lista {
	int qtd;
	struct aluno dados[MAX];
};

Lista* criar () {
	Lista *lse;
	lse = (Lista*)malloc(sizeof(Lista));
	if (lse != NULL) { //para evitar acessar lse->qtd que n�o existe por mem�ria n�o ter sido alocada corretamente
		lse->qtd = 0;	
	}
	return lse;
}

void destruir (Lista *lse) { //desaloca e libera o espa�o;
	free(lse);
}

int tamanho (Lista* lse) { //verifica se a lista est� vazia e caso contr�rio, retorna seu tamanho;
	if (lse == NULL)
		return -1;
	else
		retunr lse->qtd;
}

int cheia (Lista* lse) { //verifica se a lista est� cheia, ou seja, chegou ao MAX, e retorna 1 para lista cheia ou 0 caso contr�rio;
	if (lse == NULL)
		return -1;
	else if (lse->qtd == MAX)
		return 1;
	else
		return 0;
}

int vazia (Lista* lse) { //veririca se a lista est� vazia (retornando -1 caso NULL e 1 caso 0) ou n�o (retornando 0)
	if (lse == NULL)
		return -1;
	else if (lse->qtd == 0)
		return 1;
	else
		return 0;
}

/* Para inserir um elemento, iremos elaborar tr�s fun��es, pois o elemento pode ser inserido em v�rias
posi��es da lista */

int inserirFim (Lista* lse, struct aluno novo) {
	if (lse == NULL)
		return 0;
	else if (cheia(lse))
		return 0;
	else {
		lse->dados[lse->qtd] = novo;
		lse->qtd++;
		return 1;
	}
}

int inserirInicio (Lista* lse, struct aluno novo) {
	if (lse == NULL)
		return 0;
	else if (cheia(lse)) //fun��o dentro de fun��o
		return 0;
	else {
		int i;
		for (i = (lse->qtd)-1; i >= 0; i--) {
			lse->dados[i+1] = lse->dados[i];
		}
		lse->dados[0] = novo;
		lse->qtd++;
		return 1;
	}
}

/* Uma maneira de criar uma INSER��O ORDENADA
	Passo 1: Encontra a posi��o
	Passo 2: Ap�s encontrar, mover elementos para abrir espa�o
	Passo 3: inserir novo n�mero no local "vago"
*/

int inserirOrdenado (Lista* lse, struct aluno novo) {
	if (lse == NULL) 
		return 0;
	else if (cheia(lse))
		return 0;
	else {
		int i, pos = 0; //auxiliar que usaremos para andar posi��es
		while (lse->dados[pos].matricula < novo.matricula && pos < lse->qtd) { //literalmente, vai andando os elementos com base na ordem crescente de matr�cula
			pos++;
		}
		for (i = (lse->qtd)-1; i >= pos; i--) {
			lse->dados[i+1] = lse->dados[i]; //o posterior recebe o anterior
		}
		lse->dados[pos] = novo; //o cara da posi��o pos recebe o novo elemento
		lse->qtd++;
		return 1;
	}
}
/*
Similarmente a inserir, a fun��o excluir tamb�m pode ocorrer no in�cio, meio e fim 
*/

int removerFim (Lista* lse) {
	if (lse == NULL) 
		return 0;
	else if (vazia(lse))
		return 0;
	else {
		lse->qtd--; //diminui em 1 a quantidade de elementos da lista
		return 1;
	}
}

int removerInicio (Lista* lse) {
	if (lse == NULL)
		return 0;
	else if (vazia(lse))
		return 0;
	else {
		int i;
		for (i = 0; i < (lse->qtd)-1; i++) { //o contador come�a no 0 e vai at� qtd -1
			lse->dados[i] = lse->dados[i+1]; //o elemento anterior (come�ando em 0) recebe o posterior
		}
		lse->qtd--; //qtd incrementa
		return 1;
	}
}

/*
O Remover Valor serve para remover um elemento espec�fico que pode estar no in�cio, meio ou fim da lista
	Passo 1: encontrar o elemento especificado
	Passo 2: caso n�o encontre o elemento, n�o � poss�vel remover
	Passo 3: ap�s encontrar, mover elementos da frente para ocupar seu espa�o
*/
int removerValor (Lista* lse, int x) {
	if (lse == NULL) 
		return 0;
	else if (vazia(lse))
		return 0;
	else {
		int i, pos = 0;
		while (lse->dados[pos].matricula != x && pos < lse->qtd) //condi��o de que enquanto o valor procurado for diferente e a posi��o for menor que o tamanho da lista
			pos++;												// andar a posi��o
		if (pos == lse->qtd) //se a posi��o for igual � qtd de elemento, o programa crasha
			return 0;
		
		for (i = pos; i < (lse->qtd)-1; i++) { // contador come�ando na pos do elemento procurado, i = tamanho da lista menos 1, i encrementa
			lse->dados[i] = lse->dados[i+1]; // elemento na posi��o desejada resebe o posterior at� o final da lista
		}
		lse->qtd--; //tamanho da lista incrementa
		return 1;
	}
}
/*

Podemos acessar um elemento pela sua posi��o (acesso direto) ou pelo seu valor (requer busca)

Acesso pela sua posi��o:
*/

int acessarIndice (Lista* lse, int pos, struct aluno* a) {
	if (lse == NULL) //checa se a lista est� vazia
		return 0; //condi��o satisfeita, retorna false
	else if (pos < 0 || pos >= lse->qtd) //se a posi��o dada for menor do que 0 ou se maior do que a quantidade da lista, retorna false
		return 0;
	else {
		*a = lse->dados[pos]; //retorna os dados da struct procurada
		return 1;
	}
}

/*
Acesso pelo valor: */

int acessarValor (Lista* lse, int x, struct aluno *a) {
	if (lse == NULL) //checa se a lista est� vazia
		return 0; //condi��o satisfeita, retorna false
	else {
		int pos = 0; //a posi��o inicial recebe o valor 0, para que comece a percorrer a lista do in�cio
		while (lse->dados[pos].matricula != x && pos < lse->qtd) //condi��o: se a matricula for diferente do valor dado E a posi��o for menor do que o tamanho da lista
			pos++;	//condi��o satisfeita, posi��o incrementa;
		if (pos == lse->qtd) //se posi��o chegar � quantidade da lista, quer dizer que o valor buscado n�o existe, e o programa d� pau
			return 0; //retornando false
		else {
			*a = lse->dados[pos]; //a busca � realizada com sucesso, retornando os dados procurados
			return 1;
		}
	}
}

/*
Finalizada a Lista Sequ�ncial Din�mica e suas fun��es! Agora vamos para o programa principal, que deve conter
as seguintes funcionalidades
	Duas listas, uma comum (n�o necess�riamente em ordem) e outra ordenada;
	Um menu retorn�vel que lhe permita realizar todas as opera��es b�sicas com as duas listas de modo que
	elas funcionem corretamente, isto �
		- que voc� cadastre alunos
		- que voc� consulte alunos
		- que voc� remova alunos
		
main.c */

#include <stdio.h>
#include <stdlib.h>
#include "listaSequencialEstatica.h"

int main () {
	Lista *aed, *aedo; //aed -> lista comum, aedo -> lista ordenada
	aed = NULL; //lista comum recebe NULL;
	aedo = NULL; //lista ordenada recebe NULL;
	aed = criar(); //cria��o de uma lista vazia!
	
	destruir (aed);
	return 0;
}

/*
Concluindo... quando devo usar?
	- Listas pequenas
	- Aplica��o que apenas insira e remova no final
	- Tamanho m�ximo bem definido
	- Opera��o mais frequente for acesso direto
	
*/

