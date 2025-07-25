#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
    char buffer[100]; // This is your "memory block"

    int fd = syscall(SYS_open, "SystemCall_Function", O_RDONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Pass the address of buffer as a parameter to syscall
    long bytes_read = syscall(SYS_read, fd, buffer, 100);

    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null terminate
        printf("Read: %s\n", buffer);
    } else {
        perror("read");
    }

    close(fd);
    return 0;
}
