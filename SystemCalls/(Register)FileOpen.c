#include <fcntl.h>
#include <stdio.h>


int main () {
    const char * pathname = "SystemCall_Function";
    int flags = O_RDONLY;
    mode_t mode = 0644;

    int fd = open (pathname , flags , mode); // Passing to the register , but it is limited ... 
    printf("fd : %d\n" , fd);
    if (fd == -1) {
        printf("Error in Opening file \n");
    } else {
        printf("File is Opened");
    }
}