#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <iostream>

void copy_file(int in_fd, int out_fd) {
	size_t buffer_size = 4096;
	char buffer[buffer_size];
	while (1) {
		ssize_t read_bytes = read(in_fd, buffer, buffer_size);
		if (read_bytes == -1) {
			return;
		} else if (read_bytes == 0) {
			break;
		}
		ssize_t writted_bytes = 0;
		while (writted_bytes != read_bytes) {
			ssize_t write_bytes = write(out_fd, buffer + writted_bytes, read_bytes - writted_bytes);
			if (write_bytes == -1) {
				return;
			}
			writted_bytes += write_bytes;	
		}
	}
}

// int main(int argc, char* argv[]) {	
// 	int in_fd = open("tmp.in", O_RDONLY);
// 	int out_fd = open("tmp.out", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
// 	copy_file(in_fd, out_fd);
// }