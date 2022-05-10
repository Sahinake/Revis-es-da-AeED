struct aluno {
	char nome[50];
	int matricula;
	int telefone;
};

typedef struct elemento Lista*;

Lista* criar();
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
int informacoes(Lista*, struct informacoes);
