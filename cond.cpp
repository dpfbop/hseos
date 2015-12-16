#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int run(char* cmd) {
	if (!fork()) {
		execlp(cmd, cmd, NULL);
		exit(1);
	}
	int status;
	wait(&status);
	if (WIFEXITED(status)) {
		return !WEXITSTATUS(status);
	} else {
		return 0;
	}
}


int main(int argc, char *argv[]) {

	return !((run(argv[1]) || run(argv[2])) && run(argv[3]));
}