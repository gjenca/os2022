
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>


int main() {

	pid_t pid;
	int status;
	int pipefd_A[2];
	int pipefd_B[2];
	char buf[10];

	pipe(pipefd_A);
	pipe(pipefd_B);
	if ((pid=fork())==0) {
		dup2(pipefd_A[0],0);
		dup2(pipefd_B[1],1);
		// Zavrieme nepotrebne konce rur
		close(pipefd_A[1]);
		close(pipefd_B[0]);
		execl("/usr/bin/bc","bc",NULL);
	} 
	else {
		// Zavrieme nepotrebne konce rur
		close(pipefd_A[0]);
		close(pipefd_B[1]);
		// pouzivame bc
		write(pipefd_A[1],"7*8\n",4);
		read(pipefd_B[0],buf,3);
		write(1,buf,3);
		close(pipefd_A[1]);
		wait(&status);
	}
}
