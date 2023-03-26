/*Lívia Lutz dos Santos - 2211055 - 3WA - Tarefa 1*/

#include <stdlib.h>
#include <string.h>
#include "hospital.h"


/*Estrutura de dados que contem informações sobre a prioridade e o número de chegada de cada paciente no hopital*/

struct paciente {
	/*Prioridade do paciente*/
	char* cor;

	/*Número de chegada do paciente na fila*/
	int numChegada;

	/*Nome do paciente*/
	char* nome;

	/*Ponteiro para o próximo paciente*/
	Paciente* prox;
};

/*Função que inicializa a lista encadeada de atendimento de pacientes*/

Paciente* criaLista(void) {

	/*Retorna o um ponteiro NULL para o primeiro elemento da lista*/

	return NULL;
}

/*Função que imprime a lista de pacientes a serem atendidos*/

void imprimeLista(Paciente* l) {

	/*Ponteiro que percorre a lista até o final*/
	Paciente* p;

	/*Loop que atualiza a variável p até o final da lista*/
	for (p = l; p != NULL; p = p->prox) {

		/*Imprime os dados de cada paciente*/

		printf("%d - %s - %s\n", p->numChegada, p->nome,p->cor);
	}

}

/*Função que insere pacientes na lista usando a ordem de prioridades por cor - tem q fazer por numero de chegada tbm*/

Paciente* insereNaLista(char* n, int c,char* nome, Paciente* lista) {

	/*Novo e o ponteiro do novo elemento a ser inserido,
	  a guarda a referência para o elemento anterior e p percorre a lista*/

	Paciente* novo, * a = NULL, * p = lista;

	/*Até o final da lista e até acharmos a primeira posicão da prioridade do novo paciente
	  guardamos os ponteiros anteriores e andamos com a lista*/

	while (p != NULL && (numCor(p->cor) <= numCor(n))) {
		a = p;
		p = p->prox;
	}

	/*Alocando espaço para o novo paciente e seus dados*/

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

	/*Se o novo elemento for inserido no início da lista, continuamos a lista após ele*/

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

/*Função que correlaciona a cor da prioridade do paciente com um número para facilitar a ordenação da fila de espera de atendimento*/

int numCor(char* c) {

	/*Atribuindo um valor numérico a cada cor seguindo a seguinte regra:
	  Vermleha : Prioridade máxima , menor número para ser inserido no começo da lista
	  Amarela : Prioridade média
	  Verde : Priodidade baixa, maior némero para ser inserido no final da lista*/

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

/*Função que verifica se a lista de pacientes está vazia*/

int listaVazia(Paciente* l) {

	/*Se o primeiro ponteiro for NULL, a lista está vazia e o retorno é 0. 
	  Caso contrário retorna 1*/

	if (l != NULL) {
		return 0;
	}

	return 1;
}

/*Função que libera a memória ocupada pela lista de pacientes*/

void liberaLista(Paciente* l) {

	/*Ponteiros para guardar o próximo elemento e percorrer a lista*/
	Paciente* p = l, * t;

	/*Loop percorre a lista até o final*/

	while (p != NULL) {

		/*t guarda a referência para o próximo elemento */
		t = p->prox;

		/*Libera a memória ocupada pelo elemento*/
		free(p);

		/*Ponteiro p recebe a referência de t e continua o loop*/
		p = t;
	}

}

/*Função que retira um paciente que já foi atendido da lista de espera*/

Paciente* atendido(Paciente* lista) {

	/*p guarda referência para o primeiro elemento da lista*/
	Paciente* p = lista;

	/*A lista agora começa do próximo elemento*/
	lista = p->prox;

	/*A memória ocupada pelo primeiro elemento é liberada*/
	free(p);

	/*Retorna a lista atualizada*/
	return lista;
}

/*Função que conta a quantidade de pacientes por prioridade de cor*/

void contaCor(int* contaVermelho, int* contaAmarelo, int* contaVerde, Paciente* lista) {

	/*Ponteiro para percorrer a lista*/
	Paciente* p;

	/*Variáveis de contadores para cada prioridade*/

	int contaV = 0, contaA = 0, contaG = 0;

	/*Loop para contar cada prioridade até o final da lista*/

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

	/*Guardando o valor de cada contador nas variáveis passadas como parâmetros por referência*/

	*contaVermelho = contaV;
	*contaAmarelo = contaA;
	*contaVerde = contaG;
}

/*Função que remove o primeiro paciente de uma determinada cor*/

Paciente* removePacientePorCor(Paciente* l, int cor) {

	/*a guarda a referência para o elemento anterior e p percorre a lista*/

	Paciente* p=l,*a=NULL;

	/*Até o final da lista e até acharmos a primeira posição da prioridade do paciente
	  guardamos os ponteiros anteriores e andamos com a lista*/

	while (p != NULL && numCor(p->cor) < cor) {
		a = p;
		p = p->prox;
	}

	/*Caso a lista chegue até o final e não encontrarmos a cor, a função retorna NULL*/

	if (p == NULL) {
		return NULL;
	}

	/*Caso o elemento procurado seja o primeiro, a lista começa do próximo elemento*/

	if (a == NULL) {
		l = p->prox;
	}

	/*Se o elemento estiver no meio da lista, o elemento anterior a ele aponta para seu próximo */

	else {
		a->prox = p->prox;
	}

	/*Libera a memória ocupada pelo elemento encontrado*/

	free(p);

	/*Retorna a lista atualizada*/

	return l;
}

/*Função que remove um paciente de um determinado nome */

Paciente* retiraPacienteNome(Paciente* l, char* n) {

	/*a guarda a referência para o elemento anterior e p percorre a lista*/

	Paciente* p = l, * a = NULL;

	/*Até o final da lista e até acharmos o nome do paciente
	  guardamos os ponteiros anteriores e andamos com a lista*/

	while (p != NULL && strcmp(p->nome,n) != 0) {
		a = p;
		p = p->prox;
	}

	/*Caso a lista chegue até o final e não encontrarmos o nome, a função retorna NULL*/

	if (p == NULL) {
		return NULL;
	}

	/*Caso o elemento procurado seja o primeiro, a lista começa do próximo elemento*/

	if (a == NULL) {
		l = p->prox;
	}

	/*Se o elemento estiver no meio da lista, o elemento anterior a ele aponta para seu próximo */

	else {
		a->prox = p->prox;
	}

	/*Libera a memória ocupada pelo elemento encontrado*/

	free(p);

	/*Retorna a lista atualizada*/

	return l;
}



