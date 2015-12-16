#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

using namespace std;

int main() {
	int n = 0;	
	for (int i = 0; cin >> n; ++i) {
		pid_t pid = fork();
		if (pid < 0) {
			cout << -1 << endl;
			exit(1);
		}
		if (!pid) {	
			continue;	
		}
		int s;
		wait(&s);
		if (WIFEXITED(s) && WEXITSTATUS(s)) {
			if (i == 0) {
				exit(0);
			}
			exit(1);
		} else { 
			cout << n << endl;	
			exit(0);
		}

	}
	return 0;
}