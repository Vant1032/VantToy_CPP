//
// Created by vant on 18-9-22.
//

#include <cstdio>
#include <unistd.h>
#include <vector>
#include "ForkTest.h"

using namespace std;



void ForkTest::test() {
    pid_t pid;
    char *message;
    int n;
    printf("fork program starting\n");
    pid = fork();
    switch (pid) {
        case -1:
            perror("fork failed");
            break;
        case 0:
            message = const_cast<char *>("this is the child");
            n = 5;
            break;
        default:
            message = const_cast<char *>("this is the parent");
            n = 3;
            break;
    }

    while (n > 0) {
        puts(message);
        sleep(1);
        n--;
    }
}
