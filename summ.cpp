#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ofstream ofs("script.py", std::ofstream::out);
	ofs << "#!/usr/bin/env python3" << endl;
	ofs << "print(";
	for (int i = 1; i < argc; ++i) {
		ofs << argv[i];
		if (i != argc - 1) {
			ofs << " * ";
		}
	}
	ofs << ")" << endl;
	ofs.close();
	chmod("script.py", 0700);
	execlp("./script.py", "/script.py", NULL);
	cout << "Error" << endl;
	exit(1);
}