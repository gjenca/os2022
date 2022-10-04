
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>


int main() {

	int n;
	pid_t pid;
	int status;
	int pipefd_A[2];
	int pipefd_B[2];
	char *buf;
	size_t buf_len;
	FILE *zadanie;
	FILE *vysledok;

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
		zadanie=fdopen(pipefd_A[1],"w");
		vysledok=fdopen(pipefd_B[0],"r");
		// pouzivame bc
		buf=NULL;
		for (n=0;n<11;n++) {
			fprintf(zadanie,"%d*8\n",n);
			fflush(zadanie);
			getline(&buf,&buf_len,vysledok);
			printf("%s",buf);
		}
		close(pipefd_A[1]);
		wait(&status);
	}
}
