/*Reescreva o código do programa do Exercício 02 de forma a resolver o problema da condição de corrida
utilizando locks mutex (02_mutex.c) e semáforos (02_semaforo.c).*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Variável compartilhada
int saldo = 0;

pthread_mutex_t mutex; // Variável para armazenar o mutex

void* ajusta() {
    int x = 3;

    // Bloqueia o mutex antes de acessar o contador
    pthread_mutex_lock(&mutex);

    // Lê a variável compartilhada saldo
    int temp = saldo;

    // Aguarda um intervalo aleatório de tempo
    sleep(rand() % 3);

    // Ajusta o valor de saldo
    temp = temp + x;
    saldo = temp;
    printf("Saldo ajustado: %d\n", saldo);

    // Desbloqueia o mutex após o acesso
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {

    // Inicializa o mutex
    pthread_mutex_init(&mutex, NULL);

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

    return 0;
}