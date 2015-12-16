#include <iostream>
#include <time.h>


using namespace std;

int main(int argc, char *argv[]) {
    time_t current_timestamp = time(0);
    int days;
    while (cin >> days) {
        time_t timestamp = current_timestamp + days * 60 * 60 * 24;
        int overflow_check_int = current_timestamp + days * 60 * 60 * 24;
        long long overflow_check_long = (long long)current_timestamp + (long long)days * 60 * 60 * 24;
        if (overflow_check_long != overflow_check_int) {
            cout << "OVERFLOW\n";
            continue;
        }
        struct tm * timeinfo = localtime(&timestamp);
        char buf[20];
        strftime(buf, 20, "%F", timeinfo);
        printf("%s\n", buf);
    }
    

}

