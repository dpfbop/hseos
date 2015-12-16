#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
	char *cmd1 = argv[1];
	char *cmd2 = argv[2];
	char *cmd3 = argv[3];
	char *filename = argv[4];


	int fds[2];
	pipe(fds);
	if (!fork()) {
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		if (!fork()) {		
			execlp(cmd1, cmd1, NULL);
			exit(1);
		}
		wait(NULL);
		if (!fork()) {
			execlp(cmd2, cmd2, NULL);
			exit(1);	
		}
		wait(NULL);
		exit(0);
	} 
	if (!fork()) {
		// child 3
		int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		dup2(fd, 1);
		close(fd);
		dup2(fds[0], 0);
		close(fds[0]);
		close(fds[1]);
		execlp(cmd3, cmd3, NULL);
		exit(1);
	}
	close(fds[0]);
	close(fds[1]);
	wait(NULL);
	wait(NULL);

	return 0;
}