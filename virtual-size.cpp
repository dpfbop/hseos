#include <dlfcn.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int main(int argc, char *argv[]) {
	string s;
	long long ans = 0;
	unordered_set <unsigned int> directories;
	while (getline(cin, s)) {
		unsigned int l, r;
		sscanf(s.c_str(), "%x-%x", &l, &r);
		for (unsigned int i = (l >> 22); i <= (r >> 22); ++i) {
			if (!directories.count(i)) {
				directories.insert(i);
				ans++;
			} 
		}
	}	
	cout << (ans + 1) * 4096 << endl;
}
