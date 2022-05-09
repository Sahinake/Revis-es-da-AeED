#include <stdio.h>
#include <stdlib.h>

/* LISTAS

Lista é uma Estrutura de Dados Simples que possui um ou mais elementos do mesmo tipo organizados linearmente,
isto é, um existe após o outro, sem ramificações.

Caso a lista tenha zero elementos, ela é dita vazia.

Aplicações:
	- Cadastro de funcionários;
	- Itens em estoque;
	- Baralho de cartas;
	
OPERAÇÕES BÁSICAS

* Criar a lista
* Inserir um elemento
* Excluir um elemento
* Acessar um elemento
* Destruir um elemento

TIPOS 

Uma lista pode ser:
	ESTÁTICA: se for implementada com vetores;
	DINÂMICA: se for implementada usando ponteiro para o próximo elemento;
	
E também pode ser:
	HOMOGÊNEA: se armazenar apenas um tipo de dado primitivo;
	HETEROGÊNEA: caso contrário; //seria no caso, onde cada elemento seria uma struct;
	
LISTA SEQUENCIAL ESTÁTICA

Lista no qual o sucessor de um elemento ocupa a próxima posição de memória, pois é implementada com um vetor.

Vantagens: 
	- Acesso rápido e direto aos elementos pelo índice;
	- Tempo constante para acessar um elemento;
	- Facilidade em modificar informaçoes;

Desvantagens:
	- Definição prévia do tamanho;
		* Memória alocada em compilação.
	- Limite de tamanho (MAX)
	- Dificuldade para inserir ou remover elementos no começo da lista ou entre dois já existentes;
		* Você precisa deslocar a lista inteira.

Implementação passo-a-passo de acordo com os arquivos usando TAD e as funções básicas necessárias:
ARQUIVOS
	* main.c
	* listaSequencialEstatica(lse).c
	* listaSequencialEstatica (lse).h
FUNÇÕES BÁSICAS
	* Criar a lista
	* Inserir um elemento
	* Excluir um elemento	
	* Acessar um elemento
	* Destruir a lista

listaSequencialEstatica.h */

#define MAX 50 //definição de uma constante

struct aluno {
	int matricula;
	char nome[50];
	float av1;
	float av2;
	float pr;
}; //nesse exemplo, cada elemento da lista será um struct com vários dados -> lista heterogênea

typedef struct lista Lista; //definição do struct lista está no arquivo .c

Lista* criar (); //assinatura/protótipo da função que está no arquivo .c
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
										// Tamanho máximo, estrutura do Aluno e Novo tipo nomeado Lista
struct lista {
	int qtd;
	struct aluno dados[MAX];
};

Lista* criar () {
	Lista *lse;
	lse = (Lista*)malloc(sizeof(Lista));
	if (lse != NULL) { //para evitar acessar lse->qtd que não existe por memória não ter sido alocada corretamente
		lse->qtd = 0;	
	}
	return lse;
}

void destruir (Lista *lse) { //desaloca e libera o espaço;
	free(lse);
}

int tamanho (Lista* lse) { //verifica se a lista está vazia e caso contrário, retorna seu tamanho;
	if (lse == NULL)
		return -1;
	else
		retunr lse->qtd;
}

int cheia (Lista* lse) { //verifica se a lista está cheia, ou seja, chegou ao MAX, e retorna 1 para lista cheia ou 0 caso contrário;
	if (lse == NULL)
		return -1;
	else if (lse->qtd == MAX)
		return 1;
	else
		return 0;
}

int vazia (Lista* lse) { //veririca se a lista está vazia (retornando -1 caso NULL e 1 caso 0) ou não (retornando 0)
	if (lse == NULL)
		return -1;
	else if (lse->qtd == 0)
		return 1;
	else
		return 0;
}

/* Para inserir um elemento, iremos elaborar três funções, pois o elemento pode ser inserido em várias
posições da lista */

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
	else if (cheia(lse)) //função dentro de função
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

/* Uma maneira de criar uma INSERÇÃO ORDENADA
	Passo 1: Encontra a posição
	Passo 2: Após encontrar, mover elementos para abrir espaço
	Passo 3: inserir novo número no local "vago"
*/

int inserirOrdenado (Lista* lse, struct aluno novo) {
	if (lse == NULL) 
		return 0;
	else if (cheia(lse))
		return 0;
	else {
		int i, pos = 0; //auxiliar que usaremos para andar posições
		while (lse->dados[pos].matricula < novo.matricula && pos < lse->qtd) { //literalmente, vai andando os elementos com base na ordem crescente de matrícula
			pos++;
		}
		for (i = (lse->qtd)-1; i >= pos; i--) {
			lse->dados[i+1] = lse->dados[i]; //o posterior recebe o anterior
		}
		lse->dados[pos] = novo; //o cara da posição pos recebe o novo elemento
		lse->qtd++;
		return 1;
	}
}
/*
Similarmente a inserir, a função excluir também pode ocorrer no início, meio e fim 
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
		for (i = 0; i < (lse->qtd)-1; i++) { //o contador começa no 0 e vai até qtd -1
			lse->dados[i] = lse->dados[i+1]; //o elemento anterior (começando em 0) recebe o posterior
		}
		lse->qtd--; //qtd incrementa
		return 1;
	}
}

/*
O Remover Valor serve para remover um elemento específico que pode estar no início, meio ou fim da lista
	Passo 1: encontrar o elemento especificado
	Passo 2: caso não encontre o elemento, não é possível remover
	Passo 3: após encontrar, mover elementos da frente para ocupar seu espaço
*/
int removerValor (Lista* lse, int x) {
	if (lse == NULL) 
		return 0;
	else if (vazia(lse))
		return 0;
	else {
		int i, pos = 0;
		while (lse->dados[pos].matricula != x && pos < lse->qtd) //condição de que enquanto o valor procurado for diferente e a posição for menor que o tamanho da lista
			pos++;												// andar a posição
		if (pos == lse->qtd) //se a posição for igual à qtd de elemento, o programa crasha
			return 0;
		
		for (i = pos; i < (lse->qtd)-1; i++) { // contador começando na pos do elemento procurado, i = tamanho da lista menos 1, i encrementa
			lse->dados[i] = lse->dados[i+1]; // elemento na posição desejada resebe o posterior até o final da lista
		}
		lse->qtd--; //tamanho da lista incrementa
		return 1;
	}
}
/*

Podemos acessar um elemento pela sua posição (acesso direto) ou pelo seu valor (requer busca)

Acesso pela sua posição:
*/

int acessarIndice (Lista* lse, int pos, struct aluno* a) {
	if (lse == NULL) //checa se a lista está vazia
		return 0; //condição satisfeita, retorna false
	else if (pos < 0 || pos >= lse->qtd) //se a posição dada for menor do que 0 ou se maior do que a quantidade da lista, retorna false
		return 0;
	else {
		*a = lse->dados[pos]; //retorna os dados da struct procurada
		return 1;
	}
}

/*
Acesso pelo valor: */

int acessarValor (Lista* lse, int x, struct aluno *a) {
	if (lse == NULL) //checa se a lista está vazia
		return 0; //condição satisfeita, retorna false
	else {
		int pos = 0; //a posição inicial recebe o valor 0, para que comece a percorrer a lista do início
		while (lse->dados[pos].matricula != x && pos < lse->qtd) //condição: se a matricula for diferente do valor dado E a posição for menor do que o tamanho da lista
			pos++;	//condição satisfeita, posição incrementa;
		if (pos == lse->qtd) //se posição chegar à quantidade da lista, quer dizer que o valor buscado não existe, e o programa dá pau
			return 0; //retornando false
		else {
			*a = lse->dados[pos]; //a busca é realizada com sucesso, retornando os dados procurados
			return 1;
		}
	}
}

/*
Finalizada a Lista Sequêncial Dinâmica e suas funções! Agora vamos para o programa principal, que deve conter
as seguintes funcionalidades
	Duas listas, uma comum (não necessáriamente em ordem) e outra ordenada;
	Um menu retornável que lhe permita realizar todas as operações básicas com as duas listas de modo que
	elas funcionem corretamente, isto é
		- que você cadastre alunos
		- que você consulte alunos
		- que você remova alunos
		
main.c */

#include <stdio.h>
#include <stdlib.h>
#include "listaSequencialEstatica.h"

int main () {
	Lista *aed, *aedo; //aed -> lista comum, aedo -> lista ordenada
	aed = NULL; //lista comum recebe NULL;
	aedo = NULL; //lista ordenada recebe NULL;
	aed = criar(); //criação de uma lista vazia!
	
	destruir (aed);
	return 0;
}

/*
Concluindo... quando devo usar?
	- Listas pequenas
	- Aplicação que apenas insira e remova no final
	- Tamanho máximo bem definido
	- Operação mais frequente for acesso direto
	
*/

