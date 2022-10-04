
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>


int main() {

	int i;
	pid_t pid;
	int status;
	
	for (i=0;i<3;i++) {
		
		if ((pid=fork())==0) {
			// child
			printf("C %d mypid=%d\n",i,getpid());
		} 
		else {
			// parent
			wait(&status);
			printf("W %d for pid=%d\n",i,pid);
		}
	}
	exit(0);
}
