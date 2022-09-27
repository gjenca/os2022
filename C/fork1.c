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
		sleep(1);
		printf("Child dobehol\n");
		exit(1);
	} 
	else {
		// Parent
		printf("PID child procesu: %d\n",pid_chld);
		wait(&status);
		printf("Child proces skončil, status: %d\n",WEXITSTATUS(status));
	}

}
