#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;

int main(int argc, char *argv[]) {
    for (size_t i = 1; i < (size_t) argc; ++i) {
        string filename(argv[i]);
        ifstream file(filename, ios::in | ios::binary);

        char * buffer = new char [4];
        do {
            file.read(buffer, 4);
            cout << buffer[0] << buffer[1] << buffer[2] << buffer[3] << endl;
            unsigned int x;   
            stringstream ss;
            ss << std::hex << buffer[0] << buffer[1] << buffer[2] << buffer[3];
            ss >> x;
            cout << x;
        } while (!file.eof());
    }
}

