//
// Created by Vant on 18-9-25.
//

#include <unistd.h>
#include <fcntl.h>
#include <cstdio>
#include <sys/stat.h>

int main() {
    const size_t s = 8024;
    char *content = new char[s];
    int fd = open("./main2.txt", O_RDWR | O_CREAT, S_IRWXU);
    struct stat stat1;
    fstat(fd, &stat1);

    if (fd == -1) {
        perror("");
        return -1;
    }
    ssize_t red;
    while ((red = read(fd, content, s) > 0)) {
        write(1, content, red * sizeof(char));
//        write(fd, content, red * sizeof(char));
    }
    close(fd);
}