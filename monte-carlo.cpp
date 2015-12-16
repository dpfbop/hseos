#include <iostream>
#include <thread>
#include <stdlib.h>
#include <vector>
#include <atomic>


unsigned long n, m;
std::atomic<long long> total;
std::atomic<long long> hit;

void thread_func(unsigned int id)
{
    double x, y;
    long long sum = 0, cnt = 0;
    for (unsigned i = 0; i < m; ++i) {
        x = (double)rand_r(&id) / (double)RAND_MAX;
        y = (double)rand_r(&id) / (double)RAND_MAX;
        if (x * x + y * y <= 1) {
            ++cnt;
        }
        ++sum;
    }
    total += sum;
    hit += cnt;
}


int main (int argc, char* argv[])
{   
    n = strtoul(argv[1], NULL, 10);
    m = strtoul(argv[2], NULL, 10);
    total.store(0);
    hit.store(0);
    std::vector <std::thread> threads(n);
    for (unsigned i = 0; i < n; ++i) {
        threads[i] = std::thread(thread_func, i);
    }
    for (unsigned i = 0; i < n; ++i) {
        threads[i].join();
    }
    double pi = (double)hit / total * 4;
    printf("%0.5f\n", pi);

   	return 0;
}
