#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <iostream>


bool read_file(const char *path, std::vector<unsigned char> &vec) {
	int fd = open(path, O_RDONLY);
	size_t buffer_size = 4096;
	char buffer[buffer_size];
	while (1) {
		ssize_t read_bytes = read(fd, buffer, buffer_size);
		if (read_bytes == -1) {
			return -1;
		} else if (read_bytes == 0) {
			break;
		}
		for (ssize_t i = 0; i < read_bytes; ++i) {
			vec.push_back(buffer[i]);
		}
	}
	return 0;
}

// int main() {
// 	std::vector<unsigned char> vec;
// 	char path[] = "/Users/dpfbop/HSE/hseos/tmp.txt";	
// 	read_file(path, vec);
// 	for (int i = 0; i < vec.size(); ++i) {
// 		std::cout << vec[i];
// 	}
// }