
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>


int main() {

	int fd;
	int i;
	pid_t pid;
	int status;
	if ((pid=fork())==0) {
		fd=open("out.txt",O_CREAT|O_WRONLY|O_TRUNC,0666);
		dup2(fd,1);
		close(fd);
		execl("/bin/ls","ls",NULL);
	} 
	else {
		wait(&status);
	}
}
