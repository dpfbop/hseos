#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

using namespace std;

volatile int cnt = 0;

void handler(int s) {
	if (s == SIGINT) {
		cout << cnt << endl;
		++cnt;
		if (cnt == 4) {
			exit(0);
		}
	}
}

int main(int argc, char *argv[]) {
	cout << getpid() << endl;
	signal(SIGINT, handler);
	while (1) 
		pause();
}	