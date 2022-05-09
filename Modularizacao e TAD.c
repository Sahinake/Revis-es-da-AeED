#include <stdio.h>
#include <stdlib.h>

/* PROGRAMA��O MODULAR EM C

Uma caracter�stica especial de uma linguagem estruturada � a compartimentaliza��o do c�digo e dos dados, 
isto �, a capacidade de seccionar e encapsular partes do programa. Diante disso, o principal componente em 
C que possui essa caracter�stica � a fun��o. Com a fun��o � poss�vel modularizar um programa, permitindo 
codificar, separadamente, uma determinada tarefa. Al�m disso, tal procedimento traz algumas vantagens como a
reutiliza��o de c�digo, compila��o individual de c�digo, e a estrutura do c�digo fica mais clara, por exemplo.

O DESIGN ESTRUTURADO

O projeto em um programa em C segue uma abordagem Top-Down. Essa abordagem � caracterizada por estruturar o
projetoo a partir da rotina de n�vel mais alto at� as rotinas de n�vel mais baixo. Um esbo�o de uma determinada
parte do programa come�a com a descri��o geral e caminha em dire��o da particulariza��o.

Diante disso, o design estruturado corresponde a uma decomposi��o funcional de uma aplica��o num conjunto de 
m�dulos bem definidos. Esses m�dulos cooperam para desemprenhar a funcionalidade definida pela aplica��o.

"Programa��o Estruturada: um m�todo de escrever um programa que utiliza (1) an�lise Top-Down para solu��o de
problemas, (2) modulariza��o para estruturar e organizar o programa, e (3) estrutura��o do c�digo em m�dulos
individuais.

M�DULOS

Um m�dulo na linguagem C pode ser criado utilizando arquivos de cabe�alho e de implementa��o. Abaixo segue
a defini��o de cada tipo de arquivo:

Arquivo de cabe�alho: Os arquivos '.h' s�o utilizados para especificar assinatura de fun��es, defini��es de 
constantes, tipos de dados criados pelo usu�rio etc. De modo geral, os arquivos de cabe�alho t�m como fun��o
definir a interface de um m�dulo.

Arquivo de implementa��o: Os arquivos '.c' implementam as fun��es definidas na interface. De modo geral, esses
arquivos s�o compostos por diversas fun��es e estruturas de dados utilizadas internamente.

Para criar aplica��es seguras que n�o entrem em conflito com outros m�dulos, os conceitos apresentados sobre 
modificadores de armazenamento e o pr�-processador podem ser aplicados. Exemplo disso � a utiliza��o de header
guards, outro � a utiliza��o de modificadores static e extern.

Basicamente, a aplica��o de header guards � realizada para evitar que o c�digo presente no arquivo de 
cabe�alho seja copiado para o fonte que fez sua inclus�o. J� os modificadores podem ser empregados para limitar
o escopo de fun��es e vari�veis que s�o utilizadas somente dentro do m�dulo, tornando "p�blico" somente o que �
necess�rio.

* As bibliotecas s�o um tipo de modulariza��o;
* � poss�vel tamb�m ter m�ltiplos arquivos .c;
* ATEN��O: mas nunca mais do que um main ()!
* Cada arquivo .c � compilado em um arquivo objeto .o ou ,obj;
* Um LIGADOR une os arquivos objeto para gerar �nico arquivo execut�vel;

MOTIVA��O Flash

	- �til para projeto grandes;
	- Facilita trabalho em equipe;
	- Segmentos podem ser lidados isoladamente;
	- Facilita corre��o de erros;
	- Facilita testes;
	- Segmentos podem ser usados em diferentes programas;
	- Facilita reuso;
	
TAD - Tipos de Dados Abstratos

Nada mais � do que uma t�cnica para modularizar seu programa. Geralmente, um m�dulo define um NOVO TIPO
de dado e o conjunto de OPERA��ES para manipular dados desse tipo. Esse tipo de dado � chamado de Abstrato:
	- significando que foi "esquecida a forma de implementa��o";
	- Tipo ser� descrito pela finalidade do tipo e de suas opera��es, e n�o pela forma como est� implementado;
Isto �, o programador vai usar as fun��es do m�dulo, em vez de manipular o dado diretamente.

* Similar ao Encapsulamento e m Orienta��o � Objetos

prog.c => cont�m seu programa principal
arquivo.c => cont�m a implementa��o
arquivo.h => cont�m apenas cabe�alhos

* Recomenda-se inserir coment�rios, pois esse � o arquivo que ir� manter o "v�u" para o programador;
Desse modo, � necess�rio que ele conhe�a exatamente o que cada fun��o faz e como funciona



*/
