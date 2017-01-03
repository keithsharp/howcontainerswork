#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * To compile:
 *		gcc -o fork-example fork-example.c
 *
 * To run:
 *		./fork-example
 */

int main(void)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) { // Child process
		printf("CHILD: Process ID: %d\n", getpid());
		printf("CHILD: Parent Process ID: %d\n", getppid());
		exit(0);
	} else if (pid < 0) { // Fork failed
		printf("Fork failed!\n");
		exit(1);
	} else { // Parent process
		printf("PARENT: Process ID: %d\n", getpid());
	}

	waitpid(pid, &status, 0); // Defeat Zombies!
	exit(0);
}
