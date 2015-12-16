#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;

void besum(istream& file)
{
    long long sum = 0;
    char * buffer = new char [4];
    while (!file.eof()) {
        file.read(buffer, 4);
        if (file.eof()) {
            break;
        }
        unsigned int number = 0;
        for (int i = 0; i < 4; ++i) {
            number += (unsigned int)buffer[i] * (1 << (i * 8));
        }
        sum += number;
    } 
    cout << sum << endl;
}

int main(int argc, char *argv[]) {
    for (size_t i = 1; i < (size_t) argc; ++i) {
        string filename(argv[i]);
        if (filename == "-") {
            besum(cin);
        } else {
            ifstream file(filename);
            besum(file);
        }

        
    }
}

