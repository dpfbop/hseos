#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

using namespace std;

volatile int flag = 0;

void handler(int s) {
	if (s == SIGINT) {
		flag = 1;
	}
}

int main(int argc, char *argv[]) {

	

	cout << getpid() << endl;
	

	sigset_t ss, os;

	sigemptyset(&ss);
	sigaddset(&ss, SIGINT);

	sigprocmask(SIG_BLOCK, &ss, &os);
	signal(SIGINT, handler);
	
	int cnt = 0;
	while (1) {
		sigsuspend(&os);
		if (flag) {
			cout << cnt << endl;
			flag = 0;
			if (++cnt == 4) {
				exit(0);
			}
		}
	}
	
}	