#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

void square() {
	char * buf = new char[7];	
	read(0, buf, 7);
	long long  x = strtoll(buf, NULL, 10);
	cout << x * x << endl;
	cout.flush();
}

int main() {
	if (!fork()) {
		square();
		return 0;
	} 
	wait(NULL);
	if (!fork()) {
		square();
		return 0;
	} 
	wait(NULL);
	if (!fork()) {
		square();
		return 0;
	}
	wait(NULL);
}