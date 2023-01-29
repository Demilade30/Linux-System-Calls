#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int iterations = 5;
    char *arg = malloc(sizeof(char) * 2);
    sprintf(arg, "%d", iterations);

    pid_t pid = fork();
    if (pid == 0) {
        execl("./worker", "worker", arg, (char *)NULL);
    } else {
        wait(NULL);
    }
    return 0;
}

