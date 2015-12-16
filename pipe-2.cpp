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

	int fds[2];
	pipe(fds);
	if (!fork()) {
		/* child 1*/
		close(fds[1]);
		if (!fork()) {
			/* child of child*/

			long long sum = 0;
			int x;
			while (read(fds[0], &x, sizeof(x)) != 0) {
				sum += x;
			}
			cout << sum << endl;
			close(fds[0]);
			exit(0);
		}
		wait(NULL);
		close(fds[0]);
		exit(0);
	} 
	int t;
	while (cin >> t) {
		write(fds[1], &t, sizeof(t));
	}
	close(fds[0]);
	close(fds[1]);
	wait(NULL);

	return 0;
}