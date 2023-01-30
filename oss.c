#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char** argv) {
	int opt;
	int numofProcesses;
	int simul;
	int iterations;
	char* prog_name = argv[0];	
	
	while ((opt = getopt(argc, argv, "hn:s:t:")) > 0){
		switch (opt){
    			case 'h':
      				printf ("h");
     		 		return -1;
    			case 'n':
				numofProcesses = atoi(optarg);
				printf("%d",numofProcesses);
				break;
			case 's':
				simul = atoi(optarg);
                                printf("%d",simul);
				break;
			case 't':
				iterations = atoi(optarg);
                                printf("%d",iterations);
                                break;
		}
	}
	return 0;
}

