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

	int fds[2];
	pipe(fds);
	if (!fork()) {
		/* child 1*/
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		execlp(cmd1, cmd1, NULL);
		exit(1);
	} 
	if (!fork()) {
		// child 2
		dup2(fds[0], 0);
		close(fds[0]);
		close(fds[1]);
		execlp(cmd2, cmd2, NULL);
		exit(1);
	}
	close(fds[0]);
	close(fds[1]);
	wait(NULL);
	wait(NULL);


	return 0;
}