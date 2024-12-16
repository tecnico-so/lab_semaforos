# Guião 6: Sincronização com semáforos

![IST](img/IST_DEI.png)  

## Objetivos

No final deste guião, deverá ser capaz de:

- Coordenar tarefas utilizando semáforos
- Simular comportamento de mutexes com semáforos

## Requisitos

- Sistema operativo Linux Ubuntu 20.04 LTS (se não o tiverem disponível no vosso computador pessoal, podem utilizar os computadores do laboratório).

## Coordenação entre tarefas utilizando semáforos
 1. Faça clone deste reposítório e analise o programa [barbeiro.c]().
 Este programa implementa o problema do barbeiro em sincronização de tarefas:
    - Um barbeiro corta o cabelo de um cliente de cada vez
    - Os clientes têm 5 cadeiras para esperarem a sua vez após entrarem na loja

2. Tendo em conta a análise do programa, para que servem os semáforos `SemaforoClientes` e `SemaforoBarbeiro` ?

3. Por que razão é necessário o trinco `mutex` ?

4. Abra o ficheiro [estacionamento.c](). Nele encontra-se uma implementação do problema do estacionamento dado nas aulas teóricas, exceto as funções `entrarNoParque()` e `sairDoParque()`.

5. Complete a implementação do problema recorrendo a semáforos de modo a que fique correto do ponto de vista da sincronização de tarefas. Faça uso da biblioteca `<semaphore.h>`.

6. Abra agora o ficheiro [estacionamento2.c]() e extenda a funcionalidade do programa para o seguinte caso:
    - Existêm 3 tipos de utilizadores do parque: docentes, funcionários e alunos
    - Enquanto há lugares livres, a ordem de entrada é por ordem de chegada.
    - Quando o parque fica cheio, é dada prioridade à entrada de docentes, depois funcionários e por final alunos.

    Para tal implemente novamente as funções `entrarNoParque()` e `sairDoParque()` bem como adicione as estruturas de dados necessárias.

7. Observe uma execução correta do programa


## Conclusão

Neste guião vimos como funcionam os semáforos e como podem ser utilizados para coordenar tarefas.

Uma tarefa que pretenda aceder a uma secção crítica ou fazer uso de um recurso limitado chama `sem_wait`:
- Caso o valor do semáforo esteja a 0 a tarefa é colocada na fila e bloqueia-se à espera 
- Caso o valor do semáforo seja superior a 0: decrementa o valor e procede a execução

Após a secção crítica ou a libertação do recurso limitado a tarefa chama `sem_post`:
- Se existirem tarefas à espera na fila do semáforo, acorda a primeira
- Caso contrário incrementa o valor do semáforo

Agora pode aplicar estes conhecimentos noutros projetos, que necessitem de acessos a recursos partilhados e limitados.

