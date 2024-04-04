//ENUNCIADO:
/*Desenvolva um programa em C (01_race.c) em que várias threads tentam acessar e modificar uma mesma
variável saldo, compartilhada, de forma concorrente. A thread principal do programa inicializa o valor da variável
compartilhado saldo e então lança a execução concorrente de várias threads. Cada thread de deve executar uma
função ajusta(x), que lê a variável compartilhada saldo, aguarda um intervalo aleatório de tempo (veja a função
sleep(s)), e depois escreve o valor ajustado de saldo somando o parâmetro x. Ao final, imprima o valor final de
saldo na thread principal*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Variável compartilhada
int saldo = 0;


void* ajusta() {
    int x = 3;


    // Lê a variável compartilhada saldo
    int temp = saldo;

    // Aguarda um intervalo aleatório de tempo
    sleep(rand() % 3);

    // Ajusta o valor de saldo
    temp = temp + x;
    saldo = temp;
    printf("Saldo ajustado: %d\n", saldo);

    return NULL;
}

int main() {

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
//RESPOSTA A QUETÃO:
/*Explique, através da observação do comportamento do programa, a ocorrência de uma condição de corrida.
Adicione sua explicação como um comentário no topo do arquivo 01_race.c.*/
// A condição de corrida ocorre quando duas ou mais threads acessam e modificam,ao mesmo temo, uma variavel compartilhada. Com isso podendo gerar 
// resultados incorretos pois a ordem de execução das threads não é garantida. 