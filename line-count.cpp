#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>


int main(int argc, char *argv[]) {
    

    int pagesize = 0;

    for (size_t i = 1; i < (size_t) argc; ++i) {


        char *str = argv[i];
        struct stat buf; 

        int err = lstat(str, &buf);
        if (err == -1) {
            continue;
        }


        pagesize = buf.st_size;

        int fd = open(str, O_RDONLY, 0);
        void *mp = mmap(NULL, pagesize, PROT_READ, MAP_SHARED, fd, 0);

        char *chr = (char *)mp;
        int cnt = 0;

        if (pagesize > 0) {
            for (int offset = 0; offset < pagesize; ++offset) {
                if (chr[offset] == '\n') {
                    cnt ++;
                }
            }
            if (chr[pagesize - 1] != '\n') {
                ++cnt;
            }
        }
        
        printf("%d\n", cnt);
    }
    
}
