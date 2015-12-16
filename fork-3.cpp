#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

using namespace std;

int main() {
	if (fork() != 0) {
		cout << "1 ";
		cout.flush();
	} else {
		if (fork() != 0) {
			cout << "2 ";
			cout.flush();
		} else {
			cout << "3";
			cout.flush();
		}
		wait(NULL);
	}
	
	wait(NULL);
}