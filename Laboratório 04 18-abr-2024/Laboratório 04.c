#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


// Funções ========================================

//função para criar uma fila randomico
void createFilaRandomico(int *fila) {
    int seed = 22007263; // seed para geraçõa do vetor randomico
    srand(seed); 

    for(int i = 0; i < 1000; i++) 
    {
        fila[i] = rand() % 5000;// gera um número aleatório acima de 100 e armazena na chave
        //printf("%d\n", fila[i]);//teste de preenchimento
    }
}

//função que implementa o algoritmo FCFS
void fcfs(int *fila) {
    int val = 0;
    int resu = 0;
    int dif = 0;

    for(int i = 0; i < 1000; i++)
    {
        dif = abs(fila[i] - val);
        resu += dif;
        val = fila[i];
    }
    printf("FCFS: %d\n", resu);
}

//função que implementa o algoritmo SCAN
void scan(int *fila){
    int menorVal = fila[0];

    int resu = 0;
    for(int i = 1; i < 1000; i++) 
    {
        if(fila[i] < menorVal) 
        {
            menorVal = fila[i];
        }
    }// atualiza menorVal se o valor atual for menor

    resu = (4999 - menorVal) + 4999;
    printf("SCAN: %d\n", resu);
    
}

// ================================================

// Função principal================================
int main(){

    int fila[1000];

    createFilaRandomico(fila);
        /*for(int i = 0; i < 1000; i++) {
            printf("%d\n", fila[i]);}*/
    fcfs(fila);// chama a função fcfs

    scan(fila);// chama a função scan


    return 0;
}