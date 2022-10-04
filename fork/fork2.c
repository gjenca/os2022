
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main() {

	int fd;
	pid_t pid;
	int status;

	if ((pid=fork())>0) {
		printf("Parent; child pid = %d\n",pid);
		pid=wait(&status);
		printf("Parent; child pid = %d skoncil\n",pid);
		printf("Parent; status = %d\n",WEXITSTATUS(status));
	} else {
		sleep(2);
		fd=open("out.txt",O_CREAT|O_WRONLY,0666);
		dup2(fd,1);
		if (execl("/bin/ls","/bin/ls","-l",NULL)<0) {
			perror("execl");
		}
	}
}
