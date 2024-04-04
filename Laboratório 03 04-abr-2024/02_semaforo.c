/*Reescreva o código do programa do Exercício 02 de forma a resolver o problema da condição de corrida
utilizando locks mutex (02_mutex.c) e semáforos (02_semaforo.c).*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

// Variável compartilhada
int saldo = 0;
sem_t semaforo; // Variável para armazenar o semáforo


void* ajusta() {
    int x = 3;

    // Esperando o semáforo
    sem_wait(&semaforo);

    // Lê a variável compartilhada saldo
    int temp = saldo;

    // Aguarda um intervalo aleatório de tempo
    sleep(rand() % 3);

    // Ajusta o valor de saldo
    temp = temp + x;
    saldo = temp;
    printf("Saldo ajustado: %d\n", saldo);

    // Libera o semáforo
    sem_post(&semaforo);

    return NULL;
}

int main() {

    // Inicializa o semáforo
    sem_init(&semaforo, 0, 1);

    srand(time(NULL));

    // Número de threads
    int num_threads = 30;

    // Cria as threads
    pthread_t threads[num_threads];
    int args[num_threads];
    for (int i = 0; i < num_threads; i++) {
        args[i] = i;
        pthread_create(&threads[i], NULL, ajusta, NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    // Imprime o valor final de saldo
    printf("Saldo final: %d\n", saldo);

    // Destroi o semáforo
    sem_destroy(&semaforo);

    return 0;
}