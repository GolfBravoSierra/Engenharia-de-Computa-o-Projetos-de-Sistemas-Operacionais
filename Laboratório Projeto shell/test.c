#include <stdio.h>
#include <unistd.h>
    #include <sys/types.h> // Include the header file to define pid_t

int main() {


    pid_t pid = fork();

    if (pid < 0) {
        printf("Falha ao criar o processo filho\n");
    } else if (pid == 0) {
        printf("Este é o processo filho\n");
    } else {
        printf("Este é o processo pai, o ID do processo filho é %d\n", pid);
    }

    return 0;
}