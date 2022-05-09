#include <stdio.h>
#include <stdlib.h>

/* 
TAD - Tipo Abstrato de Dado

# Algoritmo #

O que é um Algoritmo?

Informalmente, um algoritmo é um procedimento computacional bem definido que:
	- recebbe um conjunto de valores como ENTRADA e
	- produz um conjunto de valores como SAÍDA.
Equivalentemente, um algoritmo é uma ferramenta para resolver um PROBLEMA COMPUTACIONAL. Este problema define a 
relação precisa que deve existir entre a entrada e a saída do algoritmo.

	# Estrutura de Dados #
"Estrutura de Dados" é o ramo da computação que estuda os diversos mecanismos de organização de dados para atender aos 
diferentes requisitos de processamento.

Uma estrutura de dados pode ser dividida em dois pilares fundamentais: 
	- DADO: elemento que possui valor agregado e que pode ser utilizado para solucionar problemas computacionais.
	Os dados possuem tipos específicos. 
	TIPOS DE DADOS:
		- Inteiro (int)
		- Texto (string)
		- Caracter (char)
		- Ponto flutuante (float)
		- Ponto flutuante (double)

	- ESTRUTURA: elemento estrutural que é resposável por carregar as informações dentro de uma estrutura de software.
	TIPOS DE ESTRUTURAS:
		- Vetores
		- Multidimensionais
		- Pilhas 
		- Filas 
		- Listas
	
A linguagem C possui diversos tipos de dados nativos e disponíveis ao programador, como int, float, double, long, char e entre outros. Um 
programador pode utilizar estes tipos de dados na forma de variáveis para representar informações em seus programas. Em algumas situações, porém,
os tipos de dados nativos não representam adequadamente as informações que o programador precisa representar.

Tipos abstratos de dados são tipos de dados que podem ser criados pelo próprio programador C para conseguir representar informações de uma forma
mais direta que utilizando apenas os tipos nativos da linguagem C. Existem várias formas de criar tipos abstratos de dados.

1. Enumeração

Uma enumeração em C é um tipo de dado que suporta apenas um conjunto finito de valores. A forma de uma enumeração é 

	enum diaSemana {domingo, segunda, terça, quarta, quinta, sexta, sábado}; // definição de enumeração
	enum mes {janeiro, fevereiro, março, abril, maio, junho, julho, agosto, setembro, outubro, novembro, dezembro};
	enum cor {branca, amarela, azul, verde, vermelha, preta};
	
Neste exemplo, criou-se três enumerações diasema, mes e cor. As enumerações criadas podem ser utilizadas para criar variáveis que somente
aceitem como valores os elementos que foram listados entre chaves. No exemplo abaixo, utilizou-se uma enumeração para criar uma variável e depois
atribuir um determinado valor a esta variável. Mais tarde o valor da variável é testado para saber se vale sexta. Tabti sexta quanto segunda são
valores válidos, pois foram listados entre chaves na definição da enumeração. Internamente uma enumeração é representada por um número. Ou seja,
no exemplo da primeira enumeração a palavra domingo vale a mesma coisa que 0 (valor padrão), segunda vale 1, terça 2, e assim por diante. Quando
atribuimos um valor Minha_Variavel = segunda, na realidade ela está recebendo o valor 1. Já na comparação, estamos comparando com o valor 5. */

enum diaSemana Minha-Variavel; // uso da enumeração para criar uma variável.

Minha_Variavel = segunda;

if (Minha_Variavel == sexta) {
	printf("Amanhã não tem aula!");
}
else {
	printf("Ainda não chegou a sexta...");
}

/*
Perceba que para criar uma variável, é necessário utilizar a palavra enum seguida do nome da enumeração criada e o nome da variável. Felizmente,
existe uma forma de tornar o uso de uma enumeração semelante ao de um tipo nativo da linguagem C, através do typedef. */

	enum diaSemana {domingo, segunda, terca, quarta, quinta, sexta, sabado}; // definição de enumeração
	enum mes {janeiro, fevereiro, marco, abril, maio, junho, julho, agosto, setembro, outubro, novembro, dezembro};
	enum cor {branca, amarela, azul, verde, vermelha, preta};
	
	typedef enum diaSemana diasemana;
	
	diasemana Minha_Variavel;
	
	Minha_Variavel = segunda;

/*	
Os valores não precisam ser necessariamente sequenciais iniciando-se em 0. Podemos ajustar o valor de um dos dias da semana para ser, digamos,
5. Todos os elementos seguintes ao elemento que foi ajustado terão valores uma unidade maior e a sequência continua. No exemplo, domingo vale 0,
segunda vale 1, terça vale 5, quarta vale 6, quinta vale 7, sexta vale 22 e sábado 23.

2. Estruturas nãos homogêneas

As vezes precisamos trabalhar com um conjunto de informações como se fosse apenas uma. Vamos pensar nos registros de pessoas numa agenda telefônica.
Um registro da agenda descreve uma pessoa. O registro será composto tipicamente por nome, endereço e telefone.

Na linguagem C podemos criar um registro com a palavra reservada struct, tal como mostrado abaixo. Podemos criar variáveis utilizando posterior-
mernte a palavra struct com o nome da estrutura que foi criada pelo programador e o nome da variável. Agora temos uma variável chamada 
Variavel_V1 que internamente possui 3 campos (nome, endereço e telefone) que podem ser acessados utilizando-se um ponto. */

struct Registro_de_pessoa {
	char nome [20];
	char endereco [20];
	int telefone;
};

struct Registro_de_pessoa Variavel_V1;

Variavel_V1.telefone = 324567;
strcpy(Variavel_V1.nome, "Ana Maria"); 
	// strcpy (string_destino, string_origem);é uma função que copia a string-origem para a string-destino.
strcpy(Variavel_V1.endereco, "Getúlio Vargas 1234");

printf("Mostra os dados completos\n");
printf("Nome = %s \n Endereço = %s \n Telefone = %d \n\n", Variavel_V1.nome, Variavel_V1.endereço, Variavel_V1.telefone);

/*
No exemplo, utilizamos o ponto para acessar o campo telefone, e como telefone é um inteiro, conseguimos atribuir diretamente um valor para
o mesmo. Já para o caso dos campos nome e endereço, que são strings, na linguagem C não é possível atribuir diretamente. Assim, precisamos
utilizar uma função de cópia de string, strcpy() para este fim. Posteriormente, mostramos na tela os valores dos campos usando um print.
A forma de declarar variáveis que são uma estrutura é semelhante ao enum no sentido de ser necessário escrever a palavra reservada novamente.
Podemos adotar a mesma solução que antes e usar o typedef para criar um nome novo para o struct Registro_de_pessoa. Agora, a forma de declarar
variáveis ficou semelhante ao uso dos tipos nativos da linguagem C. */

struct Registro_de_pessoa {
	char nome [20];
	char endereco [20];
	int telefone;
};

typedef struct Registro_de_pessoa Registro_ de_pessoa;

// tipo de dad    nome da variável
Registro_de_pessoa Variavel_V1;
int                  xxx;

Variavel_V1.telefone = 324567;
strcpy(Variavel_V1.nome, "Ana Maria");
strcpy(Variavel_V1.endereco, "Getulio Vargas 1234");
 
/*
Ao criarmos os campos de uma struct podemos utilizar os tipos nativos da linguagem C e também outros tipos que tenham sido criados pelo
programador.

Podemos também combinar a struct e o typedef para criar um novo tipo de dado: */

typedef struct XXXX {
	char nome[5];
	int codigo;
	char sexo;
	int c;
	char opcao;
} Dados_Cliente;

void main ( ) {
	Dados_Cliente Cliente;
	
	Cliente.codigo = 12345; Cliente.sexo = F;
	printf("Código: %d \n", Cliente.codigo);
	printf("Sexo: %x \n", Cliente.sexo);
}
	
/*
3. Inicialização estática de estruturas

É possível inicializar uma estrutura no mesmo momento no qual uma variável é criada. No exemplo abaixo, Dados_Cliente é composto por 2 campos.
A variável cliente é criada como sendo do tipo Dados_Cliente mas seu valor não é explicitado. Já a variável Pedro, é criada e o calor de seus dois
campos é explicitado na mesma ordem em que foram declarados dentro do struct. */

#include <stdio.h>
#include <string.h>

typedef int Meu_Inteiro;
typedef char String[100];

typedef struct {
	char Nome[5];
	int Codigo;
} Dados_Cliente;

void main () {
	Meu_Inteiro xx;
	String a;
	Dados_Cliente Cliente;
	Dados_Cliente Pedro = {"teste",123};
}
 /*
 4. Uniões
 
 Uniões são similares a structs no sentido de que podemos criar um registro composto por várias variáveis. Mas existe uma grande diferença entre
 registros e uniões em relação a como os campos ficam localizados na memória. Ao utilizar uniões, os campos que aparecem dentro da união ocuparão
 a mesma posição de memória. Ex: */
 
union {
	float numero_float;
	int numero_inteiro;
} Tipo_Variavel;

void main () {
	Tipo_Variavel x;
	x.numero_float = 3.0102;
	printf("%f\n", x.numero_float);
	x.numero_inteiro = 45;
	printf("%d\n", x.numero_inteiro);
}
 /*
 5. Modificando campos de uma estrutura
 
 Sabemos que para acessar um campo de uma estrutura é necessário usar o operador .. Ocorre que se tivermos uma função e o parâmetro desta função
 é uma estrutura, cuidados especiais devem ser tomados. Veja um exemplo que NÃO FUNCIONA. */
 
#include <stdio.h>
struct Teste {
	int codigo;
	int CPF;
};
// o programador acredita que assim, modificará o campo CPF, mas para modificar o parâmetro da função, este precisa ser passado por referência
// e não por valor...

void muda_CPF (struct TEST xx) {
	xx.CPF = 100;
}
void mais () {
	struct Teste T;
	
	T.codigo = 123;
	T.CPF = 34;
	muda_CPF(T);
	printf("CPF = %d\n",T.CPF);
}
 /*
 Agora veja o próximo exemplo, onde o parâmetro da função muda_CPF é passado por referência (passa-se o endereço onde a variável está na memória).
 Para alterar um campo dessa estrutura, precisamos usar a notação (*variável_estrutura).nome_do_campo = VALOR; Como mostrado no exemplo: */
 
 #include <stdio.h>
 struct Teste {
 	int codigo;
 	int CPF;
 };
 void muda_CPF (struct Teste *xx) {
 	(*xx).CPF = 100;
 }
 void main () {
 	structu Teste T;
 	
 	T.codigo = 123;
 	T.CPF = 34;
 	muda_CPF(&T);
 	printf("CPF = %d\n", T.CPF);
 }
 /*
 A notação (*xx).CPF assusta algumas pessoas, por isso, existe uma notação equivalente xx->CPF, ou seja, ao invés de . usa-se -> (seta). 
Em resumo: Quando você precisa alterar campos de uma estrutura DENTRO DE UMA FUNÇAO, a estrutura deve ser passada por REFERÊNCIA e os 
campos devem ser acessados usando o ->.

* Retornos 0 e 1

Na função principal: 
	retornar 0 significa que o programa foi executado com sucesso;
	o retorno 1 significa que o programa não foi executado com êxito e que ocorreu algum erro.

Em uma função definida pelo usuário:
	return 0 significa que a função definida pelo usuário está retornando false.
	return 1 significa que a função definida pelo usuário está retornando true.
*/


