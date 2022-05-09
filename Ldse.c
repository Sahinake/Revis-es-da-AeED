#include <stdio.h>
#include <stdlib.h>

/*
LISTA DINÂMICA SIMPLESMENTE ENCADEADA

Lista no qual o sucessor de um elemento ocupa uma posição de memória acessada por um ponteiro no elemento atual

VANTAGENS

	- Melhor utilização da memória: não há alocação de memória para vários elementos de uma só vez
	- Sem definição de tamanho, logo sem limite: a memória é alocada durante a execução do programa
	- Insere ou remove elementos sem precisar deslocar outros

DESVANTAGENS

	- Tempo de acesso variável: depende do quão "fundo" na lista está o elemento
	- Sem acesso aos elementos por índice: é necessário percorrer todos os seus antecessores na lista
	
Faremos a implementação passo-a-passo de acordo com os arquivos usando TAD e as funções básicas necessárias

ARQUIVOS 

	- main.c
	- listaSimplesmenteEncandeada.c
	- listaSimplesmenteEncandeada.h
	
FUNÇÕES BÁSICAS

	- Criar a lista
	- Inserir um elemento
	- Excluir um elemento
	- Acessar um elemento
	- Destruir a lista

Antes de começar, é importante salientar que usaremos ponteiro de ponteiro aqui. Isto é, em vez de
struct algo* usaremos struct algo**, para poder alterar o início da lista das funções.

Com apenas um nível de ponteiro, não é possível alterar o ponteiro que desejo. Vamos à um exemplo: */

int *vetor = (int*)malloc(10*sizeof(int));

/*
Quando eu passo vetor por uma função, eu consigo alterar os valores dentro do vetor, mas não para quem o vetor aponta.
	- não é possível alterar o int* apenas o int.
	
Se eu quiser alterar o int* dentro de uma função, preciso de um int**, e é dessa maneira que faremos com as 
Listas Dinâmicas.

listaSimplesmenteEncadeada.h */

struct aluno {  //manteremos a estrutura de alunos como exemplo. Assim, cada elemento da lista será um struct com vários dados
	int matricula;
	char nome[50];
	float av1;
	float av2;
	float pr;
};

typedef struct elemento* Lista;  //definição do struct elemento está no arquivo.c. Perceba que dessa vez usamos ponteiro no
// typedef, isso serve para facilitar a criação e leitura do ponteiro de ponteiro no main ()

Lista* criar(); //assinatura/protótipo da função que está no arquivo.c
void destruir(Lista*);
int tamanho(Lista*);
int cheia(Lista*);
int vazia(Lista*);
int inserirFim(Lista*, struct aluno);
int inserirInicio(Lista*, struct aluno);
int inserirOrdenado(Lista*, struct aluno);
int removerFim(Lista*);
int removerInicio (Lista*);
int removerValor(Lista*, int);
int acessarIndice(Lista*, in, struct aluno*);
int acessarValor(Lista*, int, struct aluno*);
/*
listaSimplesmenteEncandeada.c */

#include <stdlib.h>
#include "listaSimplesmenteEncadeada.h" //precisa incluir o .h

struct elemento {
	struct aluno dados; //temos os dados e uma definição Recursiva que aponta para o próximo elemento da Lista;
	struct elemento* prox;
};

typedef struct elemento Elemento; //para facilitar as operações, definimos um novo tipo de dado para o Elemento em si

Lista* criar() {
	Lista *ldse;
	ldse = (Lista*)malloc(sizeof(Lista));
	if (ldse != NULL) {
		*ldse = NULL; //Se alocou a memória com sucesso, definir o ponteiro como nulo, pois não existem elementos na lista!
	}
	return ldse; //retorna a lista
}

int inserirInicio(Lista* ldse, struct aluno novosdados) {
	if (ldse == NULL) {  //se a lista existe
		return 0; //condição satisfeita, retorna false
	}
	else {
		Elemento *novo = (Elemento*)malloc(sizeof(Elemento)); //cria um novo elemento e aloca espaço na memória
		if (novo == NULL) //verifica se o elemento foi alocado com sucesso
			return 0; //condição satisfeita, retorna false e o programa crasha
		novo->dados = novosdados; //os dados do novo elemento recebe os dados passados na função
		novo->prox = *ldse; //o novo elemento aponta para NULL
		*ldse = novo; //e ldse aponta para o novo elemento
		return 1;
	}
}

int inserirFim(Lista* ldse, struct aluno novosdados) {
	if (ldse == NULL) { //verifica se a lista existe
		return 0; //condição satisfeita, o programa retorna false
	}
	else {
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento)); //cria um novo elemento
		if (novo == NULL) //verifica se ele foi alocado com sucesso
			return 0; //condição aceita, retorna false
		novo->dados = novosdados; //o elemento recebe os dados passados
		novo->prox = NULL; //e aponta para NULL
		if (vazia(ldse)) { //se a lista estiver vazia
			*ldse = novo; //o inicio já recebe o elemento
		}
		else { // se não
			Elemento *aux = *ldse; //criamos um auxiliar que recebe o inicio
			while (aux->prox != NULL) //enquanto o proximo elemento que o auxiliar aponta for diferente de NULL
				aux = aux->prox; //o auxiliar recebe o proximo elemento e verifica a condição novamente
			aux->prox = novo; //quando a condição é satisfeita, o auxiliar apontará para novo elemento;
		}
		return 1;
	}
}

int inserirOrdenado (Lista* ldse, struct aluno novosdados) {
	if (ldse == NULL) //verifica se a lista existe!
		return 0; //condição satisfeita, retorna false
	else {
		Elemento *novo = (Elemento*)malloc(sizeof(Elemento)); //alocação de um novo elemento
		if (novo == NULL) //verifica se a alocação aconteceu com sucesso
			return 0; //condição satisfeita, retorna false
		novo->dados = novosdados; //o campo dados do novo elemento, recebe os dados repassados
		if (vazia(ldse) || (*ldse)->dados.matricula > novo->dados.matricula); //se a lista estiver vazia ou se os dados do do elemento para quem ldse aponta é maior do que o do novo elemento
			novo->prox = *ldse; // o campo próximo do novo elemento aponta para o primeiro elemento
			*ldse = novo; //*ldse aponta para o novo elemento 
		}
		else {
			//Busca pelo local correto, aqui precisaremos de dois auxiliares
			Elemento *ant = *ldse; //criação do auxiliar anterior, que aponta para o primeiro elemento
			Elemento *aux = ant->prox; //criação do auxiliar que aponta para o elemento posterior ao do auxiliar anterior
			while (aux != NULL && aux->dados.matricula < novo->dados.matricula) { //enquanto o auxiliar for diferente de NULL e a matrícula do elemento pra que o auxiliar aponta for menor do que a matrícula do novo elemento
				ant = aux; //anterior aponta para auxiliar
				aux = aux->prox; //auxiliar aponta para o próximo elemento
			}
			ant->prox = novo; //o elemento anterior aponta para o novo elemento
			novo->prox = aux; //o novo elemento aponta para o próximo elemento
		}
		return 1; //retorna true
	}	
}

int tamanho (Lista *ldse) {
	if (vazia(ldse)) {
		return 0;
	}
	int cont = 0;
	Elemento *aux = *ldse;
	while (aux != NULL) {
		cont++;
		aux = aux->prox;
	}
	return cont;
}

int vazia(Lista* ldse) {
	if (ldse == NULL) //se a lista não existe
		return 1; //condição satisfeita, retorna true
	else if (*ldse == NULL)  //se a lista aponta para NULL
		return 1; //condição satisfeita, retorna true
	else
		return 0; //retorna false
}

int cheia (Lista *ldse) {
	return 0;
}

void destruir (Lista *ldse) {
	if (ldse != NULL) {
		Elemento *aux;
		while (*ldse != NULL) {
			aux = *ldse;
			*ldse = (*ldse)->prox;
			free(aux);
		}
		//free(ldse); Para de fato limpar toda a memória precisaria desse free, mas é melhor não fazer ele,
		//para não perder o NULL que indica que a lista está vazia.
	}
}

int removerInicio (Lista *ldse) {
	if (vazia(ldse)) { //se a lista estiver vazia
		return 0; //retorna false
	}
	else {
		Elemento *aux = *ldse; //criação do auxiliar apontando para o primeiro elemento
		*ldse = aux->prox; //a lista aponta para o segundo elemento
		free(aux); //o primeiro elemento é excluído e o auxiliar
		return 1; //retorna true
	}
}

int removerFim (Lista *ldse) {
	if (vazia(ldse)) { //se a lista estiver vazia
		return 0; //retorna false
	}
	else if ((*ldse)->prox == NULL) { //se a lista apontar para NULL
		Elemento *aux = *ldse; //criação do auxiliar apontando para o primeiro elemento
		*ldse = aux->prox; //a lista aponta para o segundo elemento
		free(aux); //o primeiro elemento é excluido junto com o auxiliar
		return 1; //retorna true
	}
	else { //se a lista não aponta para NULL
		//caminhando até o final da lista
		Elemento *ant = *ldse; //criação do auxiliar anterior apontando para o primeiro elemento
		Elemento *aux = ant->prox; //criação do auxiliar apontando para o segundo elemento
		while (aux->prox != NULL) { //enquanto elemento posterior ao auxiliar for diferente de NULL
			ant = aux; //o anterior aponta para o próximo
			aux = aux->prox; //o auxiliar aponta para o próximo
		}
		ant->prox = aux->prox; //o anterior aponta para NULL
		free(aux); //o último elemento é excluído junto com o auxiliar
		return 1; //retorna true
	}
}

int removerValor (Lista *ldse, int x) {
	if (vazia(ldse)) { //verifica se a lista está vazia
		return 0; //condição aceita, retorna false
	}
	else if ((*ldse)->dados.matricula == x) { //se o dado procurado for igual ao do primeiro elemento 
		Elemento *aux = *ldse; //criação do auxiliar apontando para o primeiro elemento
		*ldse = aux->prox; //a lista aponta para o segundo elemento
		free(aux); //o elemento é excluído junto com o auxiliar
		return 1; //retorna true
	}
	else {
		//buscando o elemento
		Elemento *ant = *ldse; //criação do auxíliar anterior apontando para o primeiro elemento
		Elemento *aux = ant->prox; //criação do auxiliar apontando para o segundo elemento
		while (aux != NULL && aux->dados.matricula != x) { //enquanto o aux apontar para algo diferente de NULL e os dados do elemento apontado for diferente de x
			ant = aux; //anterior recebe o auxiliar/próximo elemento elemento
			aux = aux->prox; //auxiliar aponta para o próximo elemento
		}
		if (aux == NULL) //se o auxiliar apontar para NULL
			return 0; //retorna false
		ant->prox = aux->prox; //fecha o buraco com o anterior apontando para o próximo do auxiliar
		free(aux); //o elemento é excluído juntamente com o auxíliar 
		return 1; //retorna true
	}
}
int acessarIndice (Lista *ldse, int pos, struct aluno *a) {
	if (vazia(ldse)) //se a lista estiver vazia
		return 0; //retorna false
	else if (pos < 0) //se a posição for menor do que zero
		return 0; //retorna false
	else {
		int cont = 0; //contador recebe 0;
		Elemento *aux = *ldse; //criação do auxiliar apontando para o primeiro elemento
		while (aux != NULL && pos != cont) { //enquanto o auxiliar apontar para diferente de NULL e a posição for diferente do contador
			aux = aux->prox; //auxiliar aponta para o próximo elemento
			cont++; //contador incrementa
		}
		if (aux == NULL) //se o auxiliar apontar para NULL
			return 0; //retorna false
		*a = aux->dados; //os dados são repassados para a struct dada
		return 1; //retorna true
	}
}

int acessarValor (Lista *ldse, int x, struct aluno *a) {
	if (vazia(ldse)) //se a lista estiver vazia
		return 0; //retorna false
	else {
		Elemento *aux = *ldse; //criação do auxiliar apontando para o primeiro elemento
		while (aux != NULL && aux->dados.matricula != x) { //enquanto o auxiliar apontar para algo diferente de NULL e os dados do elemento que o auxiliar aponta for diferente de x
			aux = aux->prox; //auxiliar aponta para o próximo elemento
		}
		if (aux == NULL) //se o auxiliar apontar para NULL
			return 0; //retorna false
		*a = aux->dados; //os dados são repassados para a struct dada
		return 1; //retorna true
	}
}

/*
main.c */

#include <stdio.h>
#include <stdlib.h>
#include "listaSimplesmenteEncadeada.h"

int main () {
	Lista *ead;
	aed = NULL;
	aed = criar(); //criação de uma lista vazia!
	return 0;
}
/*
Concluindo.. quando devo usar?
	- Listas ordenadas
	- Tamannho indefinido a priori
	- Operação mais frequente por acesso inserção e remoção (ordenada)
*/
