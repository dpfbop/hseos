#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <iostream>


int main(int argc, char* argv[]) {
	char *filename = argv[1];
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		return -1;
	}
	unsigned short num;
	while (std::cin >> num) {
		char buf[2];
		buf[0] = num >> 8;
		buf[1] = num % 256;
		std::cout << buf[0] << " " << buf[1] << std::endl; 
		ssize_t err = write(fd, buf, 2);
		if (err == -1) {
			return -1;
		}
	}
}