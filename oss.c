#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

#define BUFSIZE 20

void helpMenu(){
	printf("Usage: ./oss [-h] [-n proc] [-s simul] [-t iter]\n");
        printf("-h describes how the project should run and then, terminates.\n ");
        printf("-n proc: the number of total children worker processes to launch.\n");
        printf("-s simul: the number of children processes that can be running simultaneously and.\n");
	printf("-t iter: the number of iterations to pass to the worker process that the workers do.\n");
	exit(0);
}

int main(int argc, char** argv) {
	int proc = 0;
	int opt = 0;
	int i = 0;
	int j = 0;
	int running = 0;
	int status;
	int simul = 0;
	int iter = 0;
	pid_t pid;
	char buffer [BUFSIZE];
	char* prog_name = argv[0];	
	
	while ((opt = getopt(argc, argv, "hn:s:t:")) > 0){
		switch (opt){
    			case 'h':
      				helpMenu();
     		 		return -1;
    			case 'n':
				proc = atoi(optarg);
				break;
			case 's':
				simul = atoi(optarg);
				break;
			case 't':
				iter = atoi(optarg);
                                break;
			case '?':
                                fprintf(stderr, "%s: ERROR: Unrecognized option: -%c\n",prog_name,optopt);
                                return -1;
			default:
      				helpMenu();
      				return -1;
		}
	}
	
	for (i = 0; i < proc; i++){
		if (running < simul) {
			pid = fork();
			if (pid == 0) {
				snprintf(buffer, BUFSIZE, "%d", iter);
				execl("./worker", "worker", buffer, (char *)NULL);
				exit(0);
			} else {
				running++;
			}	
		} else {
			wait (&status);
			running--;
		}
	}
	while (j < running) {
		wait(&status);
		j++;
	}

	return 0;
}

