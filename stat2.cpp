#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>


using namespace std;

int main(int argc, char *argv[]) {
    long long sumsize = 0;
    for (size_t i = 1; i < (size_t) argc; ++i) {
        char *str = argv[i];
        struct stat buf; 

        int err = lstat(str, &buf);
        if (err)
            continue;

        if (S_ISREG(buf.st_mode)) {
            if (access(str, X_OK) == 0) {
                sumsize += buf.st_size;
            }
        }
    }
    cout << sumsize << endl;
}

