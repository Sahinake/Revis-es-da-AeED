#include <stdio.h>
#include <stdlib.h>

/* PROGRAMAÇÃO MODULAR EM C

Uma característica especial de uma linguagem estruturada é a compartimentalização do código e dos dados, 
isto é, a capacidade de seccionar e encapsular partes do programa. Diante disso, o principal componente em 
C que possui essa característica é a função. Com a função é possível modularizar um programa, permitindo 
codificar, separadamente, uma determinada tarefa. Além disso, tal procedimento traz algumas vantagens como a
reutilização de código, compilação individual de código, e a estrutura do código fica mais clara, por exemplo.

O DESIGN ESTRUTURADO

O projeto em um programa em C segue uma abordagem Top-Down. Essa abordagem é caracterizada por estruturar o
projetoo a partir da rotina de nível mais alto até as rotinas de nível mais baixo. Um esboço de uma determinada
parte do programa começa com a descrição geral e caminha em direção da particularização.

Diante disso, o design estruturado corresponde a uma decomposição funcional de uma aplicação num conjunto de 
módulos bem definidos. Esses módulos cooperam para desemprenhar a funcionalidade definida pela aplicação.

"Programação Estruturada: um método de escrever um programa que utiliza (1) análise Top-Down para solução de
problemas, (2) modularização para estruturar e organizar o programa, e (3) estruturação do código em módulos
individuais.

MÓDULOS

Um módulo na linguagem C pode ser criado utilizando arquivos de cabeçalho e de implementação. Abaixo segue
a definição de cada tipo de arquivo:

Arquivo de cabeçalho: Os arquivos '.h' são utilizados para especificar assinatura de funções, definições de 
constantes, tipos de dados criados pelo usuário etc. De modo geral, os arquivos de cabeçalho têm como função
definir a interface de um módulo.

Arquivo de implementação: Os arquivos '.c' implementam as funções definidas na interface. De modo geral, esses
arquivos são compostos por diversas funções e estruturas de dados utilizadas internamente.

Para criar aplicações seguras que não entrem em conflito com outros módulos, os conceitos apresentados sobre 
modificadores de armazenamento e o pré-processador podem ser aplicados. Exemplo disso é a utilização de header
guards, outro é a utilização de modificadores static e extern.

Basicamente, a aplicação de header guards é realizada para evitar que o código presente no arquivo de 
cabeçalho seja copiado para o fonte que fez sua inclusão. Já os modificadores podem ser empregados para limitar
o escopo de funções e variáveis que são utilizadas somente dentro do módulo, tornando "público" somente o que é
necessário.

* As bibliotecas são um tipo de modularização;
* É possível também ter múltiplos arquivos .c;
* ATENÇÃO: mas nunca mais do que um main ()!
* Cada arquivo .c é compilado em um arquivo objeto .o ou ,obj;
* Um LIGADOR une os arquivos objeto para gerar único arquivo executável;

MOTIVAÇÃO Flash

	- Útil para projeto grandes;
	- Facilita trabalho em equipe;
	- Segmentos podem ser lidados isoladamente;
	- Facilita correção de erros;
	- Facilita testes;
	- Segmentos podem ser usados em diferentes programas;
	- Facilita reuso;
	
TAD - Tipos de Dados Abstratos

Nada mais é do que uma técnica para modularizar seu programa. Geralmente, um módulo define um NOVO TIPO
de dado e o conjunto de OPERAÇÕES para manipular dados desse tipo. Esse tipo de dado é chamado de Abstrato:
	- significando que foi "esquecida a forma de implementação";
	- Tipo será descrito pela finalidade do tipo e de suas operações, e não pela forma como está implementado;
Isto é, o programador vai usar as funções do módulo, em vez de manipular o dado diretamente.

* Similar ao Encapsulamento e m Orientação à Objetos

prog.c => contém seu programa principal
arquivo.c => contém a implementação
arquivo.h => contém apenas cabeçalhos

* Recomenda-se inserir comentários, pois esse é o arquivo que irá manter o "véu" para o programador;
Desse modo, é necessário que ele conheça exatamente o que cada função faz e como funciona



*/
