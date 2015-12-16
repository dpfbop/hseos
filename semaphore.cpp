#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>


class Semaphore {

    std::condition_variable cv;
    std::mutex mtx;
    int value;

public:
    Semaphore(int initial_value): value(initial_value) {}

    int up() {
        std::lock_guard<std::mutex> lock(mtx);
        if (++value > 0)
            cv.notify_one();
        return value;
    }

    int down() {
        std::unique_lock<std::mutex> lock(mtx);
        while (value <= 0) {
            cv.wait(lock);
        }
        if (--value > 0) {
            cv.notify_one();
        }
        return value;
    }
};

Semaphore s(10);

void thread_func(unsigned int id)
{
    for (int i = 0; i < 10000; ++i) {
        printf("%d\n", s.down());
        sched_yield();
        printf("%d\n", s.up());
    }
}



int main (int argc, char* argv[])
{   
    int n = 20;
    std::vector <std::thread> threads(n);
    for (int i = 0; i < n; ++i) {
        threads[i] = std::thread(thread_func, i);
    }
    for (int i = 0; i < n; ++i) {
        threads[i].join();
    }

   	return 0;
}
