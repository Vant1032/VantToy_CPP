//
// Created by vant on 18-9-23.
//

#include "File.h"

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



bool File::exist() {
    return opendir(path) != nullptr;
}

File::File(char *path) : path(path) {}

File::File(std::string &path) {
    memcpy(this->path, path.c_str(), path.length() * sizeof(char));
}

bool File::canWrite() {

}

std::string File::toString() {
    return std::string(path);
}

bool File::getStat(struct stat stat1) {
    DIR *dp;
    if ((dp = opendir(path)) == nullptr) {
        return false;
    }
    chdir(path);

}
