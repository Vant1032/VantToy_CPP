//
// Created by Vant on 18-9-29.
//

#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include "EnvironTest.h"

extern char **environ;

void EnvironTest::test() {
    printf("开始打印环境变量\n");
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("结束打印环境变量\n");


    char *tmp = "Test=good";
    putenv(tmp);

    char * p = getenv("PATH");
    printf("Path=%s\n", p);
    printf("Test=%s\n", getenv("Test"));

    pid_t pid = fork();
    if (pid == 0) {
        printf("这是子线程,Test=%s\n,子进程进程继承了父进程,实现了进程间通信", getenv("Test"));
    }
}
