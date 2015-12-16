#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include <list>

using namespace std;

bool exit_flag = false;


template<typename Iterator, typename Func>
void process(Iterator from, Iterator to, Func f)
{
    for (auto it = from; it != to; ++it) {
        *it = f(*it);
    }   
}

template<typename Iterator, typename Func>
void parallel_for_each(Iterator begin, Iterator end, Func f) {
    int num_threads = thread::hardware_concurrency();
    if (num_threads == 0) {
        num_threads = 2;
    }
    const int nums_per_thread = (end - begin) / num_threads + (((end - begin) % num_threads == 0) ?0:1);
    list<thread> threads;
    
    for (auto i = 0; i < num_threads; ++i) {
        Iterator from = begin + i * nums_per_thread;
        Iterator to = (end - (begin + (i + 1) * nums_per_thread)) >= 0 ? begin + (i+1)*nums_per_thread : end;

        threads.push_back(thread(bind(process, from, to, f)));
    }
    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
}

int main (int argc, char* argv[])
{   
    int num;
    vector<int> vec;
    while (cin >> num) {
        vec.push_back(num);
    }
    parallel_for_each(vec.begin(), vec.end(), [](int x){ return -x; });
    copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));
   	return 0;   
}
