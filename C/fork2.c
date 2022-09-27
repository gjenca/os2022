#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int main() {

	pid_t pid_chld;
	int status;
	
	pid_chld=fork();
	if (!pid_chld) {
		// Child
		while (1) {
			printf("Child bezi\n");
			usleep(100000);
		}
	} 
	else {
		// Parent
		while (1) {
			printf("Parent bezi\n");
			usleep(100000);
		}
	}

}
