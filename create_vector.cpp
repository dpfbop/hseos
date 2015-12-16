#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <atomic>
#include <memory>
#include <vector>
#include <iterator>

using namespace std;

const int N = 100;

vector<long long> vec;
pthread_mutex_t vec_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *ptr)
{
    int self = (int)(size_t)(ptr);

    for (int i = 0; i < 1000; ++i) {
        int val = (self * 1000) + i;
        pthread_mutex_lock(&vec_mutex);
        vec.push_back(val);
        pthread_mutex_unlock(&vec_mutex);
        sched_yield();
    }
    return NULL;
}

int main()
{
    unique_ptr<pthread_t[]> ids(new pthread_t[N]);
    
    for (int i = 0; i < N; ++i) {
        pthread_create(&ids[i], NULL, thread_func, (void*) (size_t) i);
    }

    for (int i = 0; i < N; ++i)
        pthread_join(ids[i], NULL);

    copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));

    return 0;
}