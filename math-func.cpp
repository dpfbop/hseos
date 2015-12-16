#include <dlfcn.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef void (*func_ptr_t)(void);

int main(int argc, char *argv[]) {

    char *str = argv[1];

    void *dl = dlopen("/lib/libm.so.6", RTLD_NOW);
    void *sym = dlsym(dl, str);
    

    
    double x;
    while (cin >> x) {
        printf("%.10g\n", ((double (*)(double)) sym)(x));
    }

    dlclose(dl);
}
