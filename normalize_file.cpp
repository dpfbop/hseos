// #include <iostream>
// #include <fstream>
// #include <sstream>
#include <ctype.h> 

// using namespace std;

void normalize_file(char *buf) {
    if (*buf == '')
        return;
    int cur = 0;
    int pos = 0;
    int spaces_started = -1;
    while (pos == 0 || *(buf + pos - 1) != '\0') {
        if (*(buf + pos) == '\n' || *(buf + pos) == '\0') {
            if (*(buf + pos) == '\0') {
                if (*(buf + pos - 1) != '\n') {
                    *(buf + cur++) = '\n';
                    *(buf + cur++) = '\0';
                } else {
                    *(buf + cur++) = '\0';
                }
                break;
            } else {
                *(buf + cur++) = '\n';
            }
            spaces_started = -1;
        } else if (isspace(*buf + pos)) {
            if (spaces_started == -1) {
                spaces_started = pos;
            }
        } else {
            if (spaces_started != -1) {
                for (int j = spaces_started; j <= pos; ++j) {
                    *(buf + cur++) = *(buf + j);
                }
                spaces_started = -1;
            } else {
                *(buf + cur++) = *(buf + pos);
            }
        }
        ++pos;
    }
}



// int main(int argc, char *argv[]) {
//     char str[] = "first line    \nsecond line";
//     normalize_file(str);
//     for (int i = 0; str[i] != '\0';i++){
//        printf ("%c", str[i]);
//     }
// }   

