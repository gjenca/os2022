#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>

int main() {

	pid_t pid_chld;
	int status;
	
	pid_chld=fork();
	if (!pid_chld) {
		// Child
		printf("Child bezi\n");
		execl("/bin/ls","ls","/neexistuje",NULL);
		printf("Toto sa nikdy nevykona\n");
	} 
	else {
		// Parent
		printf("PID child procesu: %d\n",pid_chld);
		wait(&status);
		printf("Child proces skončil, status: %d\n",WEXITSTATUS(status));
	}

}
