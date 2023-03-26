/*Lívia Lutz dos Santos - 2211055 - 3WA - Tarefa 1*/

typedef struct paciente Paciente;

int numCor(char* c);

Paciente* criaLista(void);

Paciente* insereNaLista(char* c, int n, char* nome,Paciente* lista);

Paciente* atendido(Paciente* lista);

int listaVazia(Paciente* l);

void imprimeLista(Paciente* l);

void liberaLista(Paciente* l);

void contaCor(int* contaVermelho, int* contaAmarelo, int* contaVerde, Paciente* lista);

Paciente* removePacientePorCor(Paciente* l, int cor);

Paciente* retiraPacienteNome(Paciente* l, char* n);

