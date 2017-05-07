#MAC 121 – Algoritmos e Estruturas de Dados I
##Segundo semestre de 2016##
Tabelas de símbolos – Entrega: 7 de novembro de 2016

Nome: Eduardo Hashimoto nº USP 6514136

####Introdução

Para execução do EP foram criados três arquivos separados do main, um para cada estrutura de dados.
A estrutura data visa armazenar a palavra e o contador em um único item.

####Textos de Teste
Para o teste de eficiência foram usados 4 arquivos diferentes a saber:

- t1.txt com 182299 characteres 
- t2.txt com 365284 characteres
- t3.txt com 731834 characteres
- t4.txt com 1463592 characteres

distribuidos em palavras de um mesmo texto retirado do Project Guttemberg.

#####Vetores
Os vetores foram feitos com uma estrutura auxiliar que além do próprio vetor (ponteiro para data) continha o espaço máximo destinado na memória e a última posição ocupada.

As duas principais funções são:

    vetor *insereOrdenadoV(vetor *p, char *c){
    	
    	char* c2 = malloc(1024);
    	strcpy(c2, c);
    
    	int indice = buscaBinaria(p, c2, 0, p->ultimo - 1);
    
    	if (p->ultimo == indice || strcmp(p->data[indice].palavra, c2) != 0){
    		rearranjaV(p, indice);
    		p->data[indice].palavra = c2;
    		p->data[indice].contador = 1;
    		p->ultimo++;
    	}
    	else {
    		p->data[indice].contador++;
    	}
    	return p;
    } 

Que busca a palavra a ser inserida no vetor e caso a encontre devolve seu índice e aumenta seu contator. Se não a encontrar, o vetor é rearranjado de modo a dar espaço a nova palavra a ser inserida.
Em minha análise, *insereOrdenadoV* tem complexidade linear no pior caso, devido a função *rearranjaV*, que copia todo o vetor para um outro vetor auxiliar.
No melhor caso tem complexidade logarítmica, uma vez que a função *buscaBinaria* será a única a ser executada.

	vetor *insereDesordenadoV(vetor *p, char *c){

	int i;
	char *c2;
	
	c2 = malloc(1024);
	strcpy(c2, c);

	for (i = 0; i < p->ultimo; i++){
		if (strcmp(p->data[i].palavra, c2) == 0){
			p->data[i].contador++;
			return p;
		}
	}

	if (p->ultimo == p->max - 1)
		rearranjaV(p, i);
	p->data[i].palavra = c2;
	p->data[i].contador = 1;
	p->ultimo++;

	return p;
	}

Nesse caso, a função performa uma busca linear pela palavra, e caso não a encontre insere como a última palavra do vetor. O rearranjamento só é feito se o vetor estiver cheio (diferentemente do vetor ordenado que precisa "abrir" espaço para a palavra a ser inserida no meio). Assim, *InsereDesordenadoV* tem complexidade linear ou sub-linear, caso a palavra já se encontre no vetor.

#####Listas Ligadas
As listas ligadas foram feitas com estrutura idêntica a estrutura aprendida em sala de aula (a menos que foi considerado o dado ou informação como sendo outra estrutura com dois dados).

Analogamente ao vetor as duas principais funções são:

	apontador insereOrdenadoL(apontador inicio, char *c){

		apontador p, ant, novo;
	
		char* c2 = malloc(1024);
		strcpy(c2, c);
	
		novo = malloc(sizeof(celula));
		novo->data.palavra = c2;
	
		p = inicio;
		ant = NULL;
	
		while (p != NULL && strcmp(p->data.palavra, c2) < 0){
			ant = p;
			p = p->prox;
		}
	
		if (p != NULL && strcmp(p->data.palavra, c2) == 0){
			free(novo);
			p->data.contador++;
			return inicio;
		}
	
		if (ant == NULL){
			novo->prox = inicio;
			inicio = novo;
			novo->data.contador = 1;
		}
	
		else {
			novo->prox = ant->prox;
			ant->prox = novo;
			novo->data.contador = 1;
		}
	
		return inicio;
	}

Observa-se que, diferentemente, do vetor ordenado, a lista ligada ordenada tem que performar uma busca linear em seus elementos para verificar se determinada palavra já se encontra lá. Caso a encontre apenas incrementa seu contador, senão a inserção é imediata (pois um novo nó é criado e os ponteiros remanejados). Assim, *insereOrdenadoL* tem complexidade linear ou sub-linear, caso a palavra já se encontre na estrutura.

	apontador insereDesordenadoL(apontador inicio, char *c){

		apontador p, ant, novo;
	
		char* c2 = malloc(1024);
		strcpy(c2, c);
	
		novo = malloc(sizeof(celula));
		novo->data.palavra = c2;
	
		p = inicio;
		ant = NULL;
	
		while (p != NULL && strcmp(p->data.palavra, c2) != 0){
			ant = p;
			p = p->prox;
		}
	
		if (p != NULL && strcmp(p->data.palavra, c2) == 0){
			free(novo);
			p->data.contador++;
			return inicio;
		}
	
		novo->prox = inicio;
		inicio = novo;
		novo->data.contador = 1;
	
		return inicio;
	}
	
A função *insereDesordenadoL* perfoma uma busca linear pela palavra e se a encontrar apenas incrementa o contador, caso contrário insere como a primeira palavra da lista. Desse modo *insereDesordenadoL* tem complexidade sempre linear ou sub-linear caso a palavra já se encontre no vetor.

#####Arvore de Busca Binaria

Diferentemente das outras estruturas na arvore de busca binária a inserção é sempre ordenada. A função, tipicamente recursiva, tem complexidade logarítimica (pois repetidamente divide a árvore em uma arvore menor de tamanho igual a metade da original).

	apontadorA insereAB(apontadorA raiz, char *c){
	
		char *c2 = malloc(1024);
		strcpy(c2, c);
	
		if (raiz == NULL){
			raiz = novaCelula(c2);
			return raiz;
		}
	
		else if (strcmp(raiz->data.palavra, c2) > 0)
			raiz->esq = insereAB(raiz->esq, c2);
		else if (strcmp(raiz->data.palavra, c2) < 0)
			raiz->dir = insereAB(raiz->dir, c2);
		else
			raiz->data.contador++;
	
		return raiz;
	} 

Em todos os casos concluído os modos de inserção na estrutura, procede-se ao modo para organizar essa estrutura por ocorrência ou ordem alfabética dos dados.
Para o vetor essa ordenação se dá diretamente atraves da função *qsort* da bibliotec <stdlib.h>
Para a lista ligada e para a arvore de busca binária é preciso criar um vetor auxiliar que armazenara os dados da estrutura em questão. Esse vetor então é organizado atraves da função *qsort* e inserido novamente na estrutura.
Assim, a ordenação da estrutura no caso da lista ligada e da arvore de busca binária tem um impacto maior que no caso do vetor.

#####Análise dos tempos e conclusão

O resultado dos testes foi o seguinte:

			t1.txt		t2.txt		t3.txt		t4.txt
	VO O	0.12		0.23		0.62		0.80
	VO A	0.15		0.25		0.67		0.85
	
	VD O	0.77		1.60		7.08		13.95
	VD A	0.79		1.64		6.92		13.98
	
	LO O	1.06		3.58		23.47		67.93
	LO A	1.07		3.65		23.55		70.96
	
	LD O	1.70		5.58		29.52		
	LD A	1.72		5.50		28.43
	
	AB O	0.23		0.47		1.01
	AB A	0.23		0.51		1.00

Observa-se que o código está pouco organizado requerendo um refatoramente urgente, o qual não foi feito por falta de tempo e inteligência. Ademais, infelizmente, a estruturação do código parece não ser abordada nas salas de aula, deixando o aluno "à deriva" para escrever um código limpo. Feita essa ressalva observa-se que o código apresenta muitas funções similares nas estruturas e que, talvez, pudessem ser condensadas. 
O corpo da função *main.c* é pior. O mesmo código é repetido diversas vezes dependendo da escolha do usuário. 


####Observações sobre trechos dos códigos
1) O trecho:

    	char* c2 = malloc(1024);
    	strcpy(c2, c);

repetido em todas as funções de inserção, visa criar uma cópia do string a ser lido no texto. Caso contrário, toda vez que a função fosse chamada o mesmo string seria inserido na estrutura, fornecendo uma tabela de símbolos com um único símbolo.

2) A função *qsort* da <stdlib.h> foi usada para organizar a estrutura, tanto alfabeticamente (*compareA*) quanto por número de ocorrências (*compareO*), observando que se ela já se encontra ordenada alfabeticamente então não é preciso performar o sort.

