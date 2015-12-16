#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <stdio.h>

using namespace std;


struct node
{
	int key;
	int left_idx;
	int right_idx;
};



bool fullread(int fd, node *p) {
	ssize_t already_read = 0;
	while (already_read != sizeof(node)) {
		ssize_t read_bytes = read(fd, p + already_read, sizeof(node) - already_read);
		if (read_bytes == 0 || read_bytes == -1) {
			return 0;
		}
		already_read += read_bytes;
	}
	return 1;
}

void print_tree(int fd, int index) {
	node p;
    lseek(fd, index * sizeof(node), SEEK_SET);
    fullread(fd, &p);
    if (p.right_idx) {
        print_tree(fd, p.right_idx);
    }
    printf("%d\n", p.key);
    if (p.left_idx) {
        print_tree(fd, p.left_idx);
    }
}


int main(int argc, char* argv[]) {	

	int in_fd = open(argv[1], O_RDONLY);

	print_tree(in_fd, 0);
}