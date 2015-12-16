
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <fstream>

using namespace std;


struct node
{
	int key;
	int left_idx;
	int right_idx;
};


struct node nodes[5] = {{2, 1, 2}, {1, 0, 0}, {5, 3, 4}, {3, 0, 0}, {7, 0, 0}};

bool write_byte(ofstream &fout) {
	// bitset<8 * 3> x(nodes[0]);
	for (int i = 0; i < 5; ++i) {
		fout.write( (char*)&nodes[i].key, sizeof(int));
		fout.write( (char*)&nodes[i].left_idx, sizeof(int));
		fout.write( (char*)&nodes[i].right_idx, sizeof(int));
	}
}


int main(int argc, char* argv[]) {	
	ofstream fin("input.txt");
	write_byte(fin);
}