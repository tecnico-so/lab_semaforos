#include <semaphore.h>
#include <pthread.h>

#define NCADEIRAS 5



sem_t* SemaforoClientes;
sem_t* SemaforoBarbeiro;
pthread_mutex_t mutex;
int waiting = 0;

void threadBarbeiro(){
    while(1){
        sem_wait(SemaforoClientes);
        pthread_mutex_lock(&mutex);
        waiting--;
        sem_post(SemaforoBarbeiro);
        pthread_mutex_unlock(&mutex);
        //CortaCabelo();
    }
}

void threadCliente(){
    pthread_mutex_lock(&mutex);
    if(waiting < NCADEIRAS){
        waiting++;
        sem_post(SemaforoClientes);
        pthread_mutex_unlock(&mutex);
        sem_wait(SemaforoBarbeiro);
        //RecebeCorte();
    } else {
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    sem_init(SemaforoClientes, 0, 0);
    sem_init(SemaforoBarbeiro, 0, 0);
    pthread_mutex_init(&mutex, NULL);
}