#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

using namespace std;

int main() {
	int n;
	if (cin >> n) {
		for (int i = 0; i < n; ++i) {
			if (fork() != 0) {
				cout << i + 1;
				((i == n - 1) ? cout << endl : cout << " ");
				cout.flush();
				wait(NULL);
				break;
			}
		}
	}
}