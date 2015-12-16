#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

pthread_t threads[100000];
int last_thread = 0;  

void *thread_func(void *threadid)
{
    int n;
    if (cin >> n) {
        int tid = (long)threadid;
        pthread_create(&threads[tid + 1], NULL, thread_func, (void *)(tid + 1));
        pthread_join(threads[tid + 1], NULL);  
        cout << n << endl;
    }
   	pthread_exit(NULL);
}

int main ()
{   
    pthread_create(&threads[0], NULL, thread_func, (void *)0);
    pthread_join(threads[0], NULL); 

   	pthread_exit(NULL);
}
