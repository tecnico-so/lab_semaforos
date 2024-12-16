#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAXLUGARES 5
#define MAX_CLIENTES 10

pthread_t t_cliente[MAX_CLIENTES];


void entrarNoParque(){

}

void sairDoParque(){

}

void ThreadCarro (){
	int espera;
	entrarNoParque();
	espera = rand() % 20;
	printf ("cliente estacionado. Vai demorar %d seg \n", espera);
	sleep (espera);
	sairDoParque();
	printf ("cliente saiu do parque \n");
   return;
}

int main () {
   int i;
   void * resul;
   time_t t;
   
   /* Inicializa o gerador de números aleatórios  */
   srand((unsigned) time(&t));

   /* Cria os clientes  */
   for (i=1; i < MAX_CLIENTES; i++)
   {
	    pthread_create(&t_cliente[i],0, (void*) ThreadCarro, NULL);
	    printf ("criou o cliente numero %d \n",i);
   };

   /* Espera que os clientes terminem  */
   for (i=1; i < MAX_CLIENTES; i++) {
		pthread_join(t_cliente[i], &resul);
		printf ("terminou cliente %d  \n", i);
   };    
   	
   printf (" sistema terminou \n");
}

