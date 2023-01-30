# the makefile uses the all command to compile both the oss and worker executables at the same time

all: oss worker

# the oss executable is generated from the oss.c source file
oss: oss.c
	gcc -o oss oss.c -lpthread

# the worker executable is generated from the worker.c source file
worker: worker.c
	gcc -o worker worker.c

# the help command displays usage information
help:
	@echo "Usage: oss [-h] [-n proc] [-s simul] [-t iter]"
	@echo "Options:"
	@echo " -h: Display this help message"
	@echo " -n proc: Number of total children to launch"
	@echo " -s simul: Number of children to allow to run simultaneously"
	@echo " -t iter: Number to pass to the worker process"

# the clean command is used to remove the executables and the object files
clean:
	rm -f oss worker *.o
