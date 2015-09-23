#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;


void normalize_path(char *buf) {
    int cur = 0;
    bool is_slash = false;
    for (int pos = 0; buf[pos] != '\0'; ++pos) {
        if (!is_slash && buf[pos] == '/') {
            buf[cur] = '/';
            is_slash = true;
            ++cur;
        } else if (buf[pos] != '/') {
            buf[cur] = buf[pos];
            ++cur;
            is_slash = false;
        }
    }
    buf[cur] = '\0';
}

int main(int argc, char *argv[]) {
    char str[] = "///a//b///c/";
    normalize_path(str);
    for (int i = 0; str[i] != '\0';i++){
       printf ("%c", str[i]);
    }
}   

