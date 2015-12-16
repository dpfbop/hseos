#include <iostream>
#include <string> 
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    long long sumi = 0;
    double sumd = 0;
    int countd = 0;
    long long sums = 0;
    for (size_t i = 1; i < (size_t) argc; ++i) {
        char *str = argv[i];
        
        if (str[0] == 'i') {
            long long number = 0;
            if (str[1] == '-') {
                number = strtoul(str + 2, 0, 10);
                number = -number;
            } else {
                number = strtoul(str + 1, 0, 10);
            }
            sumi += number;
        } else if (str[0] == 'd') {
            double number = strtod(str + 1, 0);
            sumd += number;
            countd += 1;
        } else {
            sums += strlen(str);
        }
    }
    cout.precision(10);
    cout << (countd == 0?0:sumd / countd) << " " << sumi << " " << sums << endl;
}

