# Linux-System-Calls
Makefile to compile two source files into two separate executables.

# Project: Compiling Source Files into Executables
This project is aimed at compiling two source files into two separate executables. One of the executables, `oss`, will be generated at least partially from the source file `oss.c`. The other executable, `worker`, will be generated at least partially from the source file called `worker.c`.

## Author
* Name: Divine Akinjiyan (completed on: 02/07/2023)

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

## Makefile
A makefile has been created to compile and create the executables. Type `make` to tun the project. The makefile uses the `all` command to compile multiple executables from the same makefile.

## Executables
### OSS
The `oss` executable is used to launch the `worker` executable with specific parameters.

### Worker
The `worker` executable is never executed directly. Instead, it is launched by the `oss` executable. The `worker` takes in one command line argument, which indicates the number of iterations over a loop that it should perform.

When the `worker` is executing, it outputs its PID, its parent's PID, and the iteration of the loop it is in. After outputting this information, the `worker` sleeps for one second and then outputs the same information again, but with "after sleeping" added to the end.

## Usage
To compile the source files into executables, simply run the makefile with the command `make`. This will compile both the `oss` and `worker` executables. To launch the `worker` executable with a specific number of iterations, call the `oss` executable with the desired number as a command line argument.

Example:
```bash
./oss 5
```

This will launch the worker executable with 5 iterations.

## Note
Make sure to use the correct syntax when running the executables and makefile.

## License
The project is licensed under the MIT License: <https://opensource.org/licenses/MIT>.

## Acknowledgements
* Mark Hauschild, Associate Teaching Professor Ph.D. in Applied Mathematics, University of Missouri-St. Louis, 2013, hauschildm@umsl.edu
