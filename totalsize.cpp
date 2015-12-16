#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main(int argc, char *argv[]) {
    long long sumsize = 0;
    char *dir_path = argv[1];

    struct dirent *dirp;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        return 1;
    }
    char *fullpath = new char[1000];
    int dirlen = strlen(dir_path);
    strcpy(fullpath, dir_path);
    if (fullpath[dirlen] != '/') {
        fullpath[dirlen] = '/';
        fullpath[dirlen+1] = '\0';
    }
    dirlen++;
    while ((dirp = readdir(dp)) != NULL) {
        struct stat buf; 
        
        strcpy(fullpath + dirlen, dirp->d_name);

        int err = lstat(fullpath, &buf);
        if (err == -1)
            continue;
        if (S_ISREG(buf.st_mode)) {
            sumsize += buf.st_size;
        }
    }
    cout << sumsize << endl;
}

