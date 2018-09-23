//
// Created by vant on 18-9-23.
//

#include "PrintDirTest.h"

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>
#include <stdio.h>

void PrintDirTest::test() {
    printDir(get_current_dir_name(), 0);
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


