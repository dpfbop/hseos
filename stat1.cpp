#include <iostream>
#include <string> 
#include <stdlib.h>
#include <cstring>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[]) {
    long long sumsize = 0;
    for (size_t i = 1; i < (size_t) argc; ++i) {
        char *str = argv[i];
        struct stat buf; 

        int err = lstat(str, &buf);
        if (err == -1) {
            continue;
        }
        if (S_ISREG(buf.st_mode) && buf.st_nlink == 1) {
            sumsize += buf.st_size;
        }
    }
    cout << sumsize << endl;
}

