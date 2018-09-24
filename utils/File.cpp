//
// Created by Vant on 18-9-23.
//

#include "File.h"

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>

using namespace std;

bool File::exist() const {
    return access(path, F_OK) == 0;
}

File::File(char *path) {
    size_t len = strlen(path);
    this->path = new char[len + 1];
    strcpy(this->path, path);
}

File::File(std::string &path) {
    memcpy(this->path, path.c_str(), path.length() * sizeof(char));
}

bool File::canWrite() const {
    return access(path, W_OK) == 0;
}

std::string File::toString() const {
    return std::string(path);
}

bool File::canRead() const {
    return access(path, R_OK) == 0;
}

bool File::canExecute() const {
    return access(path, X_OK) == 0;
}


bool File::isFile() const {
    struct stat stat1{};
    int t = stat(path, &stat1);
    if (t == -1) {
        return false;
    }
    return (S_ISREG(stat1.st_mode));
}

bool File::isDirectory() const {
    struct stat stat1{};
    int t = stat(path, &stat1);
    if (t == -1) {
        return false;
    }
    return (S_ISDIR(stat1.st_mode));
}

/**
 * 如果是目录,则只有目录为空的时候才可以删除
 * @return true若删除成功,否则为false
 */
bool File::deleteFile() const {
    return remove(path) == 0;
}

std::vector<File> File::listFiles() const {
    std::vector<File> v;
    DIR *dp;
    cout << path << endl;
    if (nullptr == (dp = opendir(path))) {
        return v;
    }
    dirent *dir;
    while ((dir = readdir(dp)) != nullptr) {
        v.emplace_back(dir->d_name);
    }
    closedir(dp);
    return v;
}

File::~File() {
    delete [] path;
}

File::File(const File &file) {
    size_t len = strlen(file.path);
    this->path = new char[len + 1];
    strcpy(this->path, file.path);
}

File::File(File &&file) noexcept {
    this->path = file.path;
    file.path = nullptr;
}

File &File::operator=(const File &file) {
    delete [] this->path;
    size_t len = strlen(file.path);
    this->path = new char[len + 1];
    strcpy(this->path, file.path);
}

File &File::operator=(File &&file) noexcept {
    if (this == &file) {
        return *this;
    }
    delete [] path;
    this->path = file.path;
    file.path = nullptr;
    return *this;
}
