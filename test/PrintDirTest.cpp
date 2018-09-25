//
// Created by vant on 18-9-23.
//

#include "PrintDirTest.h"

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>
#include <memory>
#include <stdio.h>

void PrintDirTest::test() {
    char *p = get_current_dir_name();//因此不推荐使用get_current_dir_name
    printDir(p, 0);
    free(p); //要对应,不是用delete,而是用free
}

void PrintDirTest::printDir(char *dir, int depth) {
    DIR *dp;
    struct dirent *entry;
    struct stat statBuf;

    if ((dp = opendir(dir)) == nullptr) {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while ((entry = readdir(dp)) != nullptr) {
        lstat(entry->d_name, &statBuf);
        if (S_ISDIR(statBuf.st_mode)) {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
                continue;
            }
            printf("%*s%s/\n", depth, "", entry->d_name);
            printDir(entry->d_name, depth + 4);
        } else {
            printf("%*s%s\n", depth, "", entry->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}


