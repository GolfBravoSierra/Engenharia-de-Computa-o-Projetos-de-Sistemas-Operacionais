#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Declaração de Funcções ===================================
char* cdfunction(char path[]);
char* pathfunction(char input[], char path[]);
int somafunction(int numero1, int numero2);
// ==========================================================

int main(){

    // Declarando variaveis =================================
    char input [30], output[50], path[30];
    // ======================================================

    // Laço infinito ========================================
    while(strcmp(input, "exit") != 0)
    {

        // Limpando o Terminal ==============================
        system("clear");
        // ==================================================

        // Recebendo input do usuario =======================
        printf("\n >");
        scanf("%s", input);
        // ==================================================

        // Tratamento de entrada ============================
        if (strcmp(input, "cd") == 0)
        {   
            // Chamando a função CD ==========================
            cdfunction(path);
            // ===============================================
        }
        else if (strcmp(input, "path") == 0)
        {
            pathfunction(input, path);
        }
        // ==================================================
    }   
    // ======================================================

    // Limpando o Terminal ==================================
    system("clear");
    // ======================================================

    // Finalizando o programa ===============================
    printf("obrigado volte sempre \n");
    // ======================================================

    return 0;
}

// Função CD ================================================
char* cdfunction(char path[]){

    // Declarando variaveis =================================
    char* path2 = path;
    int flag = 0;
    // ======================================================

    // Recebendo o caminho do diretório =====================
    printf("\n cd>");
    scanf("%s", path);
    // ======================================================



return path2;
}
// ==========================================================


// Função PATH ==============================================
char* pathfunction(char input[],char path[]){

    printf("ola vc esta np path");    


return path;
}
// ==========================================================


// Função SOMA ==============================================
int somafunction(int numero1, int numero2){

    printf("ola vc esta np soma");    


return numero1 + numero2;
}
// ==========================================================


// partes do codigo que foram comentadas para serem implementadas depois
// ou que deram errado mesmo
/*
    // Crinado processo para funcão CD ==============
    pid_t pid = fork();
    // ==============================================

    // Verificando se o processo foi criado =========
    if (pid < 0)
    {
        perror("fork");
        return NULL;
    }
    // ==============================================

    // Processo filho executa cd ====================
    if (pid == 0)
    {
        printf("ola vc esta np cd");
        exit(0);
    }
    else
    {
        wait(NULL);
    }
    // ============================================== 

    // Verificando se o diretório existe ====================
    while(flag == 1)
    {
        if(chdir(path) != 0) 
        {
            perror("chdir");
            flag = 1;
            printf("Diretório não encontrado, tente novamente:\n>");
            scanf("%s", path);
        }
    }
    // ======================================================
    printf("Agora você está no diretório %s\n", path);
*/