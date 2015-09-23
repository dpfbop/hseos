#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string> 

using namespace std;

bitset<32> getbits(float f) {
	union {
        float input;  
        unsigned int output;
    } data;
    data.input = f;	
    bitset<32> bits(data.output);
    return bits;
}

enum class FPClass
{
	ZERO, DENORMALIZED, NORMALIZED, INF, NAN
};


int main() {
	
    float f; 
    while (cin >> f) {
    	bits = getbits(f);
        unsigned int exponent = 0;
        for (int i = 0; i < 8; ++i) {
            exponent += bits[23 + i] * (1 << i);
        }
        unsigned int frac = 0;
        for (int i = 0; i < 23; ++i) {
            frac += bits[i] * (1 << i);
        }
        cout << dec << bits[31] << " " << exponent << " ";
        cout << hex << frac << endl;
    }   
}