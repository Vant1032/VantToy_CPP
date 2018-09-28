//
// Created by Vant on 18-9-28.
//

#include <cstdio>
#include <unistd.h>

int main() {
    printf("开始运行\n");
    pid_t pid = fork();
    int t;
    switch (pid) {
        case -1:
            perror("fork 出现错误\n");
            break;
        case 0:
            printf("我是子进程\n");
            t = execl("/bin/touch", "-c", "/home/touched.txt2", nullptr);
            perror("");
            break;
        default:
            printf("我是父进程,子进程pid = %d\n", pid);
            break;
    }

}