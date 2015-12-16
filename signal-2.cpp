#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

using namespace std;

volatile int state = 0;

void handler(int s) {
	if (s == SIGUSR1) {
		state = 0;
	} else if (s == SIGUSR2) {
		state = 1;
	}
	
}

int main(int argc, char *argv[]) {
	cout << getpid() << endl;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal(SIGINT, handler);
	int num;
	while (cin >> num) {
		if (state) {
			cout << num * num << endl;	
		} else {
			cout << -num << endl;
		}
	}
}	