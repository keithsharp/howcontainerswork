#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

/*
 * To compile:
 *		gcc -o pid-namespaces pid-namespaces.c
 *
 * To run:
 *		./pid-namespaces
 */

static char child_stack[1048576];

static int childfn() {
	printf("CHILD: My Process ID: %d\n", getpid());
	return 0;
}

int main() {
	pid_t pid;
	int status;

	printf("PARENT: My Process ID: %d\n", getpid());
	pid = clone(childfn, child_stack+1048576, CLONE_NEWPID | SIGCHLD, NULL);
	if (pid < 0) { // Clone failed
		perror("Clone failed");
		exit(1);
	} else {
		printf("PARENT: The Child Process ID: %d\n", pid);
	}

	waitpid(pid, &status, 0);
	exit(0);
}
