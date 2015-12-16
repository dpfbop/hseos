#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>

using namespace std;

bool exit_flag = false;


void *thread_func(void *threadid)
{
    int num;
    long long local_sum = 0;
    while (scanf("%d", &num) != EOF) {
        local_sum += num;
        if (exit_flag) {
            break;
        }
        sched_yield();
    }
    exit_flag = true;
    return (void *)local_sum;
}

int main (int argc, char* argv[])
{   
    unsigned long n = strtoul(argv[1], NULL, 10);
    unsigned long i;

    pthread_t *threads = new pthread_t[n];
    for(i = 0; i < n; i++) {
        threads[i] = (pthread_t)i;
        pthread_create(&threads[i], NULL, thread_func, (void *)threads[i]);
    }
    long long global_sum = 0;
    for (i = 0; i < n; i++) {
        void *ans;
        pthread_join(threads[i], &ans);
        global_sum += (long long)ans;
    }   
    cout << global_sum << endl;

    delete[] threads;
   	return 0;
}
