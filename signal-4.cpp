#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>

int p[2], pid;

volatile sig_atomic_t usrflag = 1;
volatile sig_atomic_t pid1 = -1;
volatile sig_atomic_t pid2 = -1;
int n;


void handler(int s)
{
 	if (s != SIGUSR1)
 		return;   
	int v;
    read(p[0], &v, sizeof(v));
    if (pid2 == -1) {
        pid1 = getpid();
        pid2 = v;
        usrflag = 0;
        int tmp = 1;
        write(p[1], &tmp, sizeof(tmp));
        kill(pid1, SIGUSR1);
        return;
    }
    if (v <= n) {
        std::cout << (usrflag % 2) + 1 << " " << v << std::endl;
    }
    ++v;
    write(p[1], &v, sizeof(v));
    if (usrflag % 2 == 0) {
        kill(pid2, SIGUSR1);  
    } else {
        kill(pid1, SIGUSR1);
    }
    if (v > n) {
        write(p[1], &v, sizeof(v));
        exit(0);
    }
}

int main(int argc, char* argv[])
{
	n = strtol(argv[1], NULL, 10);
    if (n == 0) {
        return 0;
    }
    --n;
    pipe(p);
    signal(SIGUSR1, handler);
    if (!(pid1 = fork())) {
        // child 1
        while (true) {
            pause();
        }
    } else if (!(pid2 = fork())) {
        // child 2
        pid2 = getpid();
        int p2 = (int)pid2;
        write(p[1], &p2, sizeof(pid2));
        kill(pid1, SIGUSR1);
        while (true) {
            pause();
        }
    }
    wait(NULL);
    wait(NULL);
    std::cout << "Done" << std::endl;

}