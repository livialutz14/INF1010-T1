Um hospital gerencia os atendimentos de pacientes da emergência utilizando uma única lista contendo
pulseiras indicativas de sua prioridade no atendimento. A prioridade é dada por cores (estado do
paciente) e números (ordem de chegada na emergência). As cores de prioridade são:

• Vermelha – pacientes em estado crítico, que requerem atendimento imediato.
• Amarela – pacientes que requerem atenção. São atendidos quando não há mais pacientes
em estado crítico.
• Verde – pacientes que requerem menos atenção. São atendidos quando não há mais
paciente em estado crítico e também não há pacientes que requerem atenção.

Portanto, a prioridade deve obedecer primeiramente ao estado do paciente, seguido pela ordem de
sua chegada na emergência. Assim, em um dado momento, a ordem de chegada poderia ser:

1 - Verde, 2 - Vermelha, 3 - Verde, 4 - Amarela, 5 - Vermelha.

E a lista gerada computacionalmente de acordo com a prioridade seria:

2 - Vermelha, 5 - Vermelha, 4 - Amarela, 1 - Verde, 3 - Verde.

Se chegar um novo paciente com prioridade Amarela, a lista ficará:

2 - Vermelha, 5 - Vermelha, 4 - Amarela, 6 – Amarela, 1 - Verde, 3 - Verde.

À medida em que os pacientes são atendidos, a prioridade do paciente é retirada da lista. Por cada
paciente atendido, a lista deve ser exibida, mostrando a quantidade de pacientes atuais por cada tipo
de prioridade. 

Entrada:

a) Pacientes chegando no hospital:
1 – João – Verde
2 – Maria – Vermelha
3 – Felipe – Verde
4 – August – Amarela
5 – Lorenzo – Vermelha
6 – Romeu – Vermelha
7 – Carlos – Verde
8 – Clara - Vermelha

Saída:

a) Lista gerada computacionalmente:
2 – Maria – Vermelha
5 – Lorenzo – Vermelha
6 – Romeu – Vermelha
8 – Clara - Vermelha
4 – August – Amarela
1 – João – Verde
3 – Felipe – Verde
7 – Carlos – Verde

b) Primeiro paciente com prioridade atendido
b) Lista atualizada:

5 – Lorenzo – Vermelha
6 – Romeu – Vermelha
8 – Clara - Vermelha
4 – August – Amarela
1 – João – Verde
3 – Felipe – Verde
7 – Carlos – Verde


c) Primeiro paciente Amarelo enviado para ser
atendido em outro consultório
c) Lista atualizada:

5 – Lorenzo – Vermelha
6 – Romeu – Vermelha
8 – Clara - Vermelha
1 – João – Verde
3 – Felipe – Verde
7 – Carlos – Verde

d) Chegada de novos pacientes:

9 – Homer – Verde
10 – Renzo – Amarela
11 – Joaquim – Vermelha
12 – Manoela – Amarela

d) Lista atualizada:

5 – Lorenzo – Vermelha
6 – Romeu – Vermelha
8 – Clara - Vermelha
11 – Joaquim – Vermelha
10 – Renzo – Amarela
12 – Manoela - Amarela
1 – João – Verde
3 – Felipe – Verde
7 – Carlos – Verde
9– Homer – Verde

e) Próximos dois pacientes com prioridade
Vermelha atendidos
e) Lista atualizada:

8 – Clara - Vermelha
11 – Joaquim – Vermelha
10 – Renzo – Amarela
12 – Manoela - Amarela
1 – João – Verde
3 – Felipe – Verde
7 – Carlos – Verde
9– Homer – Verde
f) Paciente “Felipe (verde)” desiste do
atendimento e sai

g) Lista atualizada:

8 – Clara - Vermelha
11 – Joaquim – Vermelha
10 – Renzo – Amarela
12 – Manoela - Amarela
1 – João – Verde
7 – Carlos – Verde
9 – Homer – Verde
