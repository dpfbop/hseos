#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h> 

using namespace std;

struct Item {
    Item *next;
    long long value;
};

class Arena {
    
};


int main(int argc, char *argv[]) {
    char str[] = "first line    \nsecond line";
    normalize_file(str);
    for (int i = 0; str[i] != '\0';i++){
       printf ("%c", str[i]);
    }
}   

