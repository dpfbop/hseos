// #include <iostream>

// using namespace std;


unsigned satsum(unsigned v1, unsigned v2) {
    unsigned v3 = v1 + v2;
    if (v3 < v1) {
        return -1;
    } else {
        return v3;    
    }
}
