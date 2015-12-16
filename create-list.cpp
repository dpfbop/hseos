#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <atomic>
#include <memory>

using namespace std;

const int N = 100;

struct Item
{
    struct Item *next;
    long long value;
};

atomic<Item*> last(nullptr);
Item* liststart = nullptr;


void *thread_func(void *ptr)
{
    int self = (int)(size_t)(ptr);

    for (int i = 0; i < 1000; ++i) {
        auto newitem = new Item();
        newitem->value = (self * 1000) + i;
        auto old = last.exchange(newitem);
        if (!old) {
            liststart = newitem;
        } else {
            old->next = newitem;
        }

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

    auto current = liststart;
    while (current->next) {
        cout << current->value << " ";
        current = current->next;
    } 
    cout << current->value;

    return 0;
}