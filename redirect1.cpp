#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char *argv[]) {
	int pid;
	pid = fork();

	char *prog = argv[1];
	char *input = argv[2];
	char *output = argv[3];

	if (!pid) {
		int input_fd = open(input, O_RDONLY);
		int output_fd = open(output, O_WRONLY | O_CREAT| O_TRUNC, 0666);

		dup2(output_fd, 1);
		dup2(input_fd, 0);

		execlp(prog, prog, NULL);

		close(output_fd);
		close(input_fd);
		cout << "Error" << endl;
		
	}
	wait(NULL);
	return 0;
}