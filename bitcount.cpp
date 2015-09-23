#include <iostream>
#include <string> 

using namespace std;

int main(int argc, char *argv[]) {
    for (size_t i = 1; i < (size_t) argc; ++i) {
        string str(argv[i]);
        unsigned int number;
        size_t pos = 0;
        size_t arg_len = str.size();
        try {
            number = stoul(str, &pos);    
        }
        catch (...) {
            cout << -1 << endl;
            continue;
        }
        if (pos != arg_len) {
            cout << -1 << endl;
            continue;
        }
        // first method
        unsigned int bitscount = 0;
        for (size_t k = 0; k < 32; ++k) {
            unsigned int shifted = number >> k;
            if (shifted == 0) {
                break;
            }
            if (shifted & 1) {
                ++bitscount;
            }
        }
        // second method
        unsigned int bitscount2 = __builtin_popcount(number);
        if (bitscount == bitscount2)
            cout << bitscount << endl;
        else 
            cout << "-1";
    }
}

