/*L�via Lutz dos Santos - 2211055 - 3WA - Tarefa 1*/

#include <stdlib.h>
#include <string.h>
#include "hospital.h"


/*Estrutura de dados que contem informa��es sobre a prioridade e o n�mero de chegada de cada paciente no hopital*/

struct paciente {
	/*Prioridade do paciente*/
	char* cor;

	/*N�mero de chegada do paciente na fila*/
	int numChegada;

	/*Nome do paciente*/
	char* nome;

	/*Ponteiro para o pr�ximo paciente*/
	Paciente* prox;
};

/*Fun��o que inicializa a lista encadeada de atendimento de pacientes*/

Paciente* criaLista(void) {

	/*Retorna o um ponteiro NULL para o primeiro elemento da lista*/

	return NULL;
}

/*Fun��o que imprime a lista de pacientes a serem atendidos*/

void imprimeLista(Paciente* l) {

	/*Ponteiro que percorre a lista at� o final*/
	Paciente* p;

	/*Loop que atualiza a vari�vel p at� o final da lista*/
	for (p = l; p != NULL; p = p->prox) {

		/*Imprime os dados de cada paciente*/

		printf("%d - %s - %s\n", p->numChegada, p->nome,p->cor);
	}

}

/*Fun��o que insere pacientes na lista usando a ordem de prioridades por cor - tem q fazer por numero de chegada tbm*/

Paciente* insereNaLista(char* n, int c,char* nome, Paciente* lista) {

	/*Novo e o ponteiro do novo elemento a ser inserido,
	  a guarda a refer�ncia para o elemento anterior e p percorre a lista*/

	Paciente* novo, * a = NULL, * p = lista;

	/*At� o final da lista e at� acharmos a primeira posic�o da prioridade do novo paciente
	  guardamos os ponteiros anteriores e andamos com a lista*/

	while (p != NULL && (numCor(p->cor) <= numCor(n))) {
		a = p;
		p = p->prox;
	}

	/*Alocando espa�o para o novo paciente e seus dados*/

	novo = (Paciente*)malloc(sizeof(Paciente));

	if (novo == NULL) {
		return NULL;
	}

	novo->cor = (char*)malloc((strlen(n) + 1) * sizeof(char));

	if (novo->cor == NULL) {
		return NULL;
	}

	strcpy(novo->cor, n);

	novo->nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));

	if (novo->nome == NULL) {
		return NULL;
	}

	strcpy(novo->nome, nome);

	novo->numChegada = c;

	/*Se o novo elemento for inserido no in�cio da lista, continuamos a lista ap�s ele*/

	if (a == NULL) {
		novo->prox = lista;
		lista = novo;
	}

	/*Inserindo o novo elemento no meio da lista*/

	else {
		novo->prox = p;
		a->prox = novo;
	}

	/*Retorna a lista atualizada*/

	return lista;

}

/*Fun��o que correlaciona a cor da prioridade do paciente com um n�mero para facilitar a ordena��o da fila de espera de atendimento*/

int numCor(char* c) {

	/*Atribuindo um valor num�rico a cada cor seguindo a seguinte regra:
	  Vermleha : Prioridade m�xima , menor n�mero para ser inserido no come�o da lista
	  Amarela : Prioridade m�dia
	  Verde : Priodidade baixa, maior n�mero para ser inserido no final da lista*/

	if (strcmp(c, "Vermelha") == 0) {
		return 1;
	}

	else if (strcmp(c, "Amarela") == 0) {
		return 2;
	}

	else {
		return 3;
	}
}

/*Fun��o que verifica se a lista de pacientes est� vazia*/

int listaVazia(Paciente* l) {

	/*Se o primeiro ponteiro for NULL, a lista est� vazia e o retorno � 0. 
	  Caso contr�rio retorna 1*/

	if (l != NULL) {
		return 0;
	}

	return 1;
}

/*Fun��o que libera a mem�ria ocupada pela lista de pacientes*/

void liberaLista(Paciente* l) {

	/*Ponteiros para guardar o pr�ximo elemento e percorrer a lista*/
	Paciente* p = l, * t;

	/*Loop percorre a lista at� o final*/

	while (p != NULL) {

		/*t guarda a refer�ncia para o pr�ximo elemento */
		t = p->prox;

		/*Libera a mem�ria ocupada pelo elemento*/
		free(p);

		/*Ponteiro p recebe a refer�ncia de t e continua o loop*/
		p = t;
	}

}

/*Fun��o que retira um paciente que j� foi atendido da lista de espera*/

Paciente* atendido(Paciente* lista) {

	/*p guarda refer�ncia para o primeiro elemento da lista*/
	Paciente* p = lista;

	/*A lista agora come�a do pr�ximo elemento*/
	lista = p->prox;

	/*A mem�ria ocupada pelo primeiro elemento � liberada*/
	free(p);

	/*Retorna a lista atualizada*/
	return lista;
}

/*Fun��o que conta a quantidade de pacientes por prioridade de cor*/

void contaCor(int* contaVermelho, int* contaAmarelo, int* contaVerde, Paciente* lista) {

	/*Ponteiro para percorrer a lista*/
	Paciente* p;

	/*Vari�veis de contadores para cada prioridade*/

	int contaV = 0, contaA = 0, contaG = 0;

	/*Loop para contar cada prioridade at� o final da lista*/

	for (p = lista; p != NULL; p = p->prox) {
		if (numCor(p->cor) == 1) {
			contaV++;
		}
		else if (numCor(p->cor) == 2) {
			contaA++;
		}
		else {
			contaG++;
		}
	}

	/*Guardando o valor de cada contador nas vari�veis passadas como par�metros por refer�ncia*/

	*contaVermelho = contaV;
	*contaAmarelo = contaA;
	*contaVerde = contaG;
}

/*Fun��o que remove o primeiro paciente de uma determinada cor*/

Paciente* removePacientePorCor(Paciente* l, int cor) {

	/*a guarda a refer�ncia para o elemento anterior e p percorre a lista*/

	Paciente* p=l,*a=NULL;

	/*At� o final da lista e at� acharmos a primeira posi��o da prioridade do paciente
	  guardamos os ponteiros anteriores e andamos com a lista*/

	while (p != NULL && numCor(p->cor) < cor) {
		a = p;
		p = p->prox;
	}

	/*Caso a lista chegue at� o final e n�o encontrarmos a cor, a fun��o retorna NULL*/

	if (p == NULL) {
		return NULL;
	}

	/*Caso o elemento procurado seja o primeiro, a lista come�a do pr�ximo elemento*/

	if (a == NULL) {
		l = p->prox;
	}

	/*Se o elemento estiver no meio da lista, o elemento anterior a ele aponta para seu pr�ximo */

	else {
		a->prox = p->prox;
	}

	/*Libera a mem�ria ocupada pelo elemento encontrado*/

	free(p);

	/*Retorna a lista atualizada*/

	return l;
}

/*Fun��o que remove um paciente de um determinado nome */

Paciente* retiraPacienteNome(Paciente* l, char* n) {

	/*a guarda a refer�ncia para o elemento anterior e p percorre a lista*/

	Paciente* p = l, * a = NULL;

	/*At� o final da lista e at� acharmos o nome do paciente
	  guardamos os ponteiros anteriores e andamos com a lista*/

	while (p != NULL && strcmp(p->nome,n) != 0) {
		a = p;
		p = p->prox;
	}

	/*Caso a lista chegue at� o final e n�o encontrarmos o nome, a fun��o retorna NULL*/

	if (p == NULL) {
		return NULL;
	}

	/*Caso o elemento procurado seja o primeiro, a lista come�a do pr�ximo elemento*/

	if (a == NULL) {
		l = p->prox;
	}

	/*Se o elemento estiver no meio da lista, o elemento anterior a ele aponta para seu pr�ximo */

	else {
		a->prox = p->prox;
	}

	/*Libera a mem�ria ocupada pelo elemento encontrado*/

	free(p);

	/*Retorna a lista atualizada*/

	return l;
}



