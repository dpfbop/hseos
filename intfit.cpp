#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;

bool isProperlyRepresented(unsigned int n) {
    if (n <= 16777216) {
            return 1; 
    }
    bool bits[32];
    for (size_t k = 0; k < 32; ++k) {
        unsigned int shifted = n >> k;
        if (shifted & 1) {
            bits[k] = 1;
        } else {
            bits[k] = 0;
        }
    }
    int left_shift = 0, right_shift = 32;
    for (int i = 0; i < 32; ++i) {
        if (bits[i] == 1) {
            right_shift = i;
        }
    }    
    for (int j = 31; j >= 0; --j) {
        if (bits[j] == 1) {
            left_shift = j;
        }
    }
    // cout << left_shift << " " << right_shift << endl;
    if (right_shift - left_shift + 1 > 24) {
        return 0;
    }
    return 1;
}

int main() {
    unsigned int n; 

    while (cin >> n) {
        // float f = (float) n;
        // unsigned int nn = (unsigned int) f;
        // cout << n << " " << nn << endl;
        // cout << bitset<32>(n) << endl;
        cout << (isProperlyRepresented(n) ? "1\n":"0\n");
    }
    
    // for (int i = 2000000000; i < 9000000000; ++i) {
    //     float f = (float) i;
    //     int ii = (int) f;
    //     if (i != ii && isProperlyRepresented(i)) {
    //         cout << i << " " << ii << "wuuut" << endl;
    //     }
    //     // cout << (isProperlyRepresented(n) ? "1\n":"0\n");
    // }
}