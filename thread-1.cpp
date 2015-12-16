#include <iostream>
#include <cstdlib>
#include <pthread.h>


pthread_t threads[10];

void *thread_func(void *threadid)
{
   	int tid = (int)threadid;
   	if (tid != 0) {
   		pthread_join(threads[tid - 1], NULL);	
   	} 	
   
   	std::cout << tid << std::endl;
   	return NULL;
}

int main ()
{
   	for(int i = 0; i < 10; i++) {
      	pthread_create(&threads[i], NULL, thread_func, (void *)i);
   	}
   	pthread_join(threads[9], NULL);
   	return 0;
}
