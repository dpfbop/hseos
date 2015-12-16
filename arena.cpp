// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <ctype.h> 

// using namespace std;

// struct Item {
//     Item *next;
//     long long value;
// };

class Arena {
public:
    Arena(size_t size = 16) {
        numberOfElements = size / sizeof(Item);
        items = new Item[numberOfElements];
        freeItems = new bool[numberOfElements];
    }

    Item *get() {
        for (int i = 0; i < numberOfElements; ++i) {
            if (freeItems[i] == 0) {
                freeItems[i] = 1;
                return &items[i];
            }
        }
        return nullptr;
    }

    void put(Item* item) {
        int pos = (item - items);
        freeItems[pos] = 0; 
    }

    ~Arena()
    {
        delete[] items;
        delete[] freeItems;
    }

private:
    int numberOfElements;
    Item* items;
    bool* freeItems;
    Arena(const Arena&) = delete;
    void operator=( const Arena& ) = delete;
};


// int main(int argc, char *argv[]) {
//     Arena arena(64);
//     Item *f = arena.get();
//     f->value = 1;
//     Item *s = arena.get();
//     s->value = 2;
//     Item *i3 = arena.get();
//     i3->value = 3; 
//     Item *i4 = arena.get();
//     i4->value = 4;
//     arena.put(i3);
//     arena.put(s);
//     i3 = arena.get();
//     cout << i3->value << endl;
// }   

