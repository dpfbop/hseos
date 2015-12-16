#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/mman.h>
#include <sched.h>

using namespace std;

int main(int argc, char *argv[]) {

	volatile int* counter = (int *)mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE , MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	*counter = 1;
	int n = strtoul(argv[1], NULL, 10);
	if (!fork()) {
		while (*counter <= n) {
			while ((*counter) % 2 == 0) {
				sched_yield();
			}
			if (*counter > n) 
				break;
			cout << 1 << " " << *counter << endl;
			++(*counter);
		}
		exit(0);
	} else if (!fork()) {
		while (*counter <= n) {
			while ((*counter) % 2 == 1) {
				sched_yield();
			}
			if (*counter > n) 
				break;
			cout << 2 << " " << *counter << endl;
			++(*counter);	

		}
		exit(0);
	}
	wait(NULL);
	wait(NULL);
	munmap((void *)counter, getpagesize());
	return 0;
}