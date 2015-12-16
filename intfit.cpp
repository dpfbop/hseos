#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;

bool isProperlyRepresented(unsigned int n) {
    int left_shift = -1, right_shift = -1;
    for (int shift = 0; shift < 9; ++shift) {
        if (right_shift == -1 && ((n >> (31 - shift)) & 1)) {
            right_shift = 31 - shift;
        } 
        if (left_shift == -1 && ((n >> shift) & 1)) {
            left_shift = shift;
        }
        if (left_shift != -1 && right_shift != -1) 
            break;
    }
    if (left_shift == -1 || right_shift == -1) {
        return true;
    }
    if (right_shift - left_shift + 1 > 24) {
        return false;
    }
    return true;
}

int main() {
    unsigned int n; 

    while (cin >> n) {
        cout << (isProperlyRepresented(n) ? "1\n":"0\n");
    }
}