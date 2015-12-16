#include <iostream>
#include <time.h>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    string s;  
    ifstream ifs(argv[1], ifstream::in);
    bool first = 1;
    time_t last_timestamp = 0;

    while (ifs >> s) {
        struct tm tm1;
        struct tm tm2;
        memset(&tm1, 0, sizeof(struct tm));
        memset(&tm2, 0, sizeof(struct tm));

        strptime(s.c_str(), "%Y/%m/%d", &tm1);
        ifs >> s;
        strptime(s.c_str(),  "%H:%M:%S", &tm2);

        tm1.tm_hour = tm2.tm_hour;
        tm1.tm_min = tm2.tm_min;
        tm1.tm_sec = tm2.tm_sec;
        tm1.tm_isdst = -1;
        time_t timestamp = mktime(&tm1);
        if (first) {
            last_timestamp = timestamp;
            first = 0;
        } else {
            cout << (int)difftime(timestamp, last_timestamp) << endl;
            last_timestamp = timestamp;
        }
    }
    

}

