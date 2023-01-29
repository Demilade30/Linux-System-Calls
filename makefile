all: oss worker

oss: oss.c
	gcc -o oss oss.c -lpthread

worker: worker.c
	gcc -o worker worker.c

help:
	@echo "Usage: oss [-h] [-n proc] [-s simul] [-t iter]"
	@echo "Options:"
	@echo " -h: Display this help message"
	@echo " -n proc: Number of total children to launch"
	@echo " -s simul: Number of children to allow to run simultaneously"
	@echo " -t iter: Number to pass to the worker process"
clean:
	rm -f oss worker
