#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_FILOSOFOS 5
#define PENSANDO 2
#define FAMINTO 1
#define COMENDO 0
#define ESQUERDA (num_filosofo + 4) % NUM_FILOSOFOS
#define DIREITA (num_filosofo + 1) % NUM_FILOSOFOS

void *filosofo(void *num);
void pegar_garfos(int);
void colocar_garfos(int);
void testar(int);

sem_t mutex;
sem_t S[NUM_FILOSOFOS];
int estado[NUM_FILOSOFOS];
int filosofo_num[NUM_FILOSOFOS];

int main() {
    int i;
    pthread_t thread_id[NUM_FILOSOFOS];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_FILOSOFOS; i++) {
        sem_init(&S[i], 0, 0);
        filosofo_num[i] = i;
    }

    for (i = 0; i < NUM_FILOSOFOS; i++) {
        pthread_create(&thread_id[i], NULL, filosofo, &filosofo_num[i]);
        printf("Filosofo %d está pensando\n", i + 1);
    }

    for (i = 0; i < NUM_FILOSOFOS; i++)
        pthread_join(thread_id[i], NULL);
}

void *filosofo(void *num) {
    while (1) {
        int *i = num;
        sleep(1);
        pegar_garfos(*i);
        sleep(0);
        colocar_garfos(*i);
    }
}

void pegar_garfos(int num_filosofo) {
    sem_wait(&mutex);
    estado[num_filosofo] = FAMINTO;
    printf("Filosofo %d está faminto\n", num_filosofo + 1);
    testar(num_filosofo);
    sem_post(&mutex);
    sem_wait(&S[num_filosofo]);
    sleep(1);
}

void colocar_garfos(int num_filosofo) {
    sem_wait(&mutex);
    estado[num_filosofo] = PENSANDO;
    printf("Filosofo %d colocou os garfos %d e %d\n", num_filosofo + 1, ESQUERDA + 1, num_filosofo + 1);
    printf("Filosofo %d está pensando\n", num_filosofo + 1);
    testar(ESQUERDA);
    testar(DIREITA);
    sem_post(&mutex);
}

void testar(int num_filosofo) {
    if (estado[num_filosofo] == FAMINTO && estado[ESQUERDA] != COMENDO && estado[DIREITA] != COMENDO) {
        estado[num_filosofo] = COMENDO;
        sleep(2);
        printf("Filosofo %d pegou os garfos %d e %d\n", num_filosofo + 1, ESQUERDA + 1, num_filosofo + 1);
        printf("Filosofo %d está comendo\n", num_filosofo + 1);
        sem_post(&S[num_filosofo]);
    }
}