#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int iterations = atoi(argv[1]);
    int i;
    for (i = 0;i < iterations; i++) {
        printf("WORKER PID:%d PPID:%d Iteration:%d before sleeping\n", getpid(), getppid(), i);
        sleep(1);
        printf("WORKER PID:%d PPID:%d Iteration:%d after sleeping\n", getpid(), getppid(), i);
    }
    return 0;
}

