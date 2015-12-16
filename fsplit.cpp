#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string> 

using namespace std;

int main() {
    float f; 
    while (cin >> f) {
        union {
            float input;  
            struct {
                uint32_t frac : 23;
                uint32_t exponent : 8;
                uint32_t sign : 1;
            };
        } data;

        data.input = f;

        cout << dec << data.sign << " " << data.exponent << " ";
        cout << hex << data.frac << endl;
    }   
}