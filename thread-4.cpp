#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>

using namespace std;

pthread_t threads[2];
unsigned long n;
unsigned long last = 1;
int state = 0;

void *thread_func(void *threadid)
{
    int tid = (long)threadid;
    while (true) {
        if (last >= n) {
            return 0;
        }
        while (state == tid % 2) {
            sched_yield();
        }
        cout << tid << " " << last << endl;
        ++last;
        state = !state; 
    }
}

int main (int argc, char* argv[])
{   
    n = strtoul(argv[1], NULL, 10);
    if (n == 1) {
        cout << "1 1" << endl;
        return 0;
    }

    pthread_create(&threads[0], NULL, thread_func, (void *)1);
    pthread_create(&threads[1], NULL, thread_func, (void *)2);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

   	return 0;
}
