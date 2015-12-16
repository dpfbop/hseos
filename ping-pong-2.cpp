#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

void pinger(int fdin, int fdout, int proc_num, unsigned long n) {
	unsigned long cnt = 0;
	while (read(fdin, &cnt, sizeof(cnt))) {
		if (cnt > n) {
			break;
		}
		cout <<  proc_num << " "  << cnt << endl;
		++cnt;
		write(fdout, &cnt, sizeof(cnt));
	}
	close(fdin);
	close(fdout);
	exit(0);
}

int main(int argc, char *argv[]) {
	int fds1[2];
	int fds2[2];

	pipe(fds1);
	pipe(fds2);
	
	unsigned long n = strtoul(argv[1], NULL, 10);

	if (!fork()) {
		int start = 1;
		write(fds2[1], &start, sizeof(start));
		close(fds2[1]);
		close(fds1[0]);
		pinger(fds2[0], fds1[1], 1, n);
	} 
	if (!fork()) {
		close(fds2[0]);
		close(fds1[1]);
		pinger(fds1[0], fds2[1], 2, n);
	}
	close(fds1[0]);
	close(fds1[1]);
	close(fds2[0]);
	close(fds2[1]);
	wait(NULL);
	wait(NULL);

	exit(0);
}