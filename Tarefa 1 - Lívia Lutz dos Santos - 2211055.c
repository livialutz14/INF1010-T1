/*Lívia Lutz dos Santos - 2211055 - 3WA - Tarefa 1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital.h"


int main(void) {

	/*Variáveis inteiras que guardam contadores e a condição de parada do loop*/

	int qtdPaciente = 0, pedido = 1, contaVermelho = 0, contaAmarelo = 0, contaVerde = 0;

	/*Variáveis de char para guardar a prioridade e nome de cada paciente*/

	char cor[51],nome[81];

	Paciente* lista;

	/*Inicializando a lista de pacientes */

	lista = criaLista();

	/*Começando o cadastro de pacientes*/

	printf("Deseja ser atendido? sim (1) ou nao (0): \n");

	scanf("%d", &pedido);

	/*Enquanto tiver pacientes requisitando atendimento, adicionamos todos na lista de espera por ordem de prioridade de cor
	Neste mesmo loop, contamos a quantidade de pacientes a serem atendidos*/

	while (pedido != 0) {

		/*Guardando a prioridade do paciente*/

		printf("Digite sua prioridade (Vermelha,Amarela ou Verde):\n");

		scanf("%s", cor);

		/*Guardando o nome de cada paciente*/

		printf("Digite seu nome:\n");

		scanf("%s", nome);

		/*Inserindo o paciente na lista.
		  Sua posição na fila é o valor do contador da quantidade de pacientes, que inicialmente é 0,
		  acrescido de 1*/

		lista = insereNaLista(cor, qtdPaciente + 1, nome, lista);

		/*Acrescentando 1 ao contador de pacientes*/

		qtdPaciente++;

		/*Mensagem para continuar o input do usuário*/

		printf("Deseja ser atendido? sim (1) ou nao (0): \n");

		scanf("%d", &pedido);
	}


	/*Se a lista de espera não for vazia, o atendimento começa*/

	if (listaVazia(lista) == 0) {


		/*a) mostrar a lista de pacientes gerada computacionalmente,nao ordena por num so por cor*/

		printf("Lista de atendimento:\n");

		/*Contamos a quantidade de pacientes em cada prioridade na lista de espera*/

		contaCor(&contaVermelho, &contaAmarelo, &contaVerde, lista);

		printf("\n");

		/*Imprime a lista e a quantidade de pacientes em cada prioridade*/

		imprimeLista(lista);

		printf("\n");

		printf("%d pacientes com prioridade vermelha %d pacientes com prioridade amarela e %d pacientes com prioridade verde\n", contaVermelho, contaAmarelo, contaVerde);
		
		printf("\n");

		/*Parte b) Paciente com maior prioridade foi atendido */

		printf("Paciente com maior prioridade atendido\n");

		/*Remove o primeiro paciente da lista*/

		lista = atendido(lista);

		contaCor(&contaVermelho, &contaAmarelo, &contaVerde, lista);

		printf("\n");

		/*Imprime a lista e a quantidade de pacientes em cada prioridade*/

		imprimeLista(lista);

		printf("\n");

		printf("%d pacientes com prioridade vermelha %d pacientes com prioridade amarela e %d pacientes com prioridade verde\n", contaVermelho, contaAmarelo, contaVerde);
		
		printf("\n");

		/*Parte c) primeiro paciente amarelo foi enviado para outro consultório*/

		printf("Paciente amarelo foi para outro consultorio\n");

		/*Remove o primeiro paciente amarelo*/

		lista = removePacientePorCor(lista, numCor("Amarela"));

		contaCor(&contaVermelho, &contaAmarelo, &contaVerde, lista);

		printf("\n");

		/*Imprime a lista e a quantidade de pacientes em cada prioridade*/

		imprimeLista(lista);

		printf("\n");

		printf("%d pacientes com prioridade vermelha %d pacientes com prioridade amarela e %d pacientes com prioridade verde\n", contaVermelho, contaAmarelo, contaVerde);
		
		printf("\n");


		/*Parte d)Chegada de novos pacientes*/

		/*Mensagem de início do input de dados pelo Usuário*/

		printf("Deseja ser atendido? sim (1) ou nao (0): \n");

		scanf("%d", &pedido);

		while (pedido != 0) {

			/*Guardando a prioridade do paciente*/

			printf("Digite sua prioridade (Vermelha,Amarela ou Verde):\n");

			scanf("%s", cor);

			/*Guardando o nome de cada paciente*/

			printf("Digite seu nome:\n");

			scanf("%s", nome);

			/*Inserindo o paciente na lista.
		    Sua posição na fila é o valor do contador da quantidade de pacientes acrescido de 1*/

			lista = insereNaLista(cor, qtdPaciente + 1, nome, lista);

			/*Acrescentando 1 ao contador de pacientes*/

			qtdPaciente++;

			/*Mensagem para continuar o input do usuário*/

			printf("Deseja ser atendido? sim (1) ou nao (0): \n");

			scanf("%d", &pedido);
		}

		/*Contamos a quantidade de pacientes em cada prioridade na lista de espera*/

		contaCor(&contaVermelho, &contaAmarelo, &contaVerde, lista);

		printf("Lista com novos pacientes\n");

		printf("\n");

		/*Imprime a lista e a quantidade de pacientes em cada prioridade*/

		imprimeLista(lista);

		printf("\n");

		printf("%d pacientes com prioridade vermelha %d pacientes com prioridade amarela e %d pacientes com prioridade verde\n", contaVermelho, contaAmarelo, contaVerde);
		
		printf("\n");

		/*Parte e) Atender 2 pacientes na prioridade*/

		/*Loop que funciona 2 vezes para atender os 2 pacientes*/

		for(int i=0;i<2;i++){

			/*Retira o primeiro paciente da lista*/

			lista = atendido(lista);

			/*Conta quantos pacientes temos em cada prioridade*/

			contaCor(&contaVermelho, &contaAmarelo, &contaVerde, lista);

			/*Exibe a quantidade de pacientes atendidos, que é o contador da quantidade de loops,
			  que inicialmente é 0, acrescido de 1*/

			printf("%d pacientes na prioridade foram atendidos\n",i+1);

			printf("\n");

			/*Exibe a lista atualizada com a quantidade de pacientes em cada prioridade a cada loop*/

			imprimeLista(lista);

			printf("\n");

			printf("%d pacientes com prioridade vermelha %d pacientes com prioridade amarela e %d pacientes com prioridade verde\n", contaVermelho, contaAmarelo, contaVerde);
			
			printf("\n");
		}

		/*Parte f) Paciente Felipe (verde) desiste*/

		/*Retira o paciente de nome Felipe da lista*/

		lista = retiraPacienteNome(lista,"Felipe");

		/*Conta quantos pacientes tem em cada prioridade*/

		contaCor(&contaVermelho, &contaAmarelo, &contaVerde, lista);

		/*Imprime a lista atualizada após a remoção do paciente com a quantidade de pacientes por prioridade*/

		printf("Paciente Felipe(Verde) desistiu\n");

		printf("\n");

		imprimeLista(lista);

		printf("\n");

		printf("%d pacientes com prioridade vermelha %d pacientes com prioridade amarela e %d pacientes com prioridade verde\n", contaVermelho, contaAmarelo, contaVerde);
		
		printf("\n");

		/*No final do atendimento, liberamos a memória ocupada pela lista de espera*/

		liberaLista(lista);
	}

	return 0;
}

