#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int mysys(const char *str) {
	int status;
	int pid = fork();
	if (!pid) {
		execlp("/bin/sh", "/bin/sh", "-c", str, NULL);	
		exit(-1);
	}
	wait(&status);
	if (WIFEXITED(status)) {
		return WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status)) {
		return 128 + WTERMSIG(status);
	}
	return 1;
}

// int main(int argc, char *argv[]) {
	
// 	cout << mysys("ls -laj");
// 	return 0;
// }