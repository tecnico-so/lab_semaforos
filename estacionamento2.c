#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAXLUGARES 5
#define MAX_CLIENTES 20
#define DOCENTE 0
#define FUNCIONARIO 1
#define ALUNO 2


pthread_t t_cliente[MAX_CLIENTES];
int lista_tipos[MAX_CLIENTES];
int counter, fila[3];
const char* tipos_to_str[3];

void entrarNoParque(int tipo){

}

void sairDoParque(){

}

void ThreadCarro (void* ptr){
	int espera;
    int i = *(int*)ptr;
    printf ("criou um cliente tipo %s \n",tipos_to_str[i]);
	entrarNoParque(i);
	espera = rand() % 20;
	printf ("cliente tipo %s estacionado. Vai demorar %d seg \n",tipos_to_str[i], espera);
	sleep (espera);
	sairDoParque();
	printf ("cliente tipo %s saiu do parque \n",tipos_to_str[i]);
}

int main () {
    int i;
    void * resul;
    time_t t;
    int tipo;

    tipos_to_str[0] = "DOCENTE";
    tipos_to_str[1] = "FUNCIONARIO";
    tipos_to_str[2] = "ALUNO";
   
    /* Inicializa o gerador de números aleatórios  */
    srand((unsigned) time(&t));

    /* Cria os clientes  */
    for (i=1; i < MAX_CLIENTES; i++)
    {
        tipo = rand() % 3;
        lista_tipos[i] = tipo;
	    pthread_create(&t_cliente[i],0, (void*)ThreadCarro, &lista_tipos[i]);
    };

    /* Espera que os clientes terminem  */
    for (i=1; i < MAX_CLIENTES; i++) {
		pthread_join(t_cliente[i], &resul);
    };    
   	
    printf (" sistema terminou \n");
}