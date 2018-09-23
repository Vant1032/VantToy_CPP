//
// Created by vant on 18-9-23.
//

#ifndef LINUX_FILE_H
#define LINUX_FILE_H

#include <string>
#include <sys/stat.h>

class File {
public:
    File(char *path);
    File(std::string& path);

    bool exist();
    bool canWrite();
    bool canRead();
    bool canExecute();
    bool isFile();
    bool isDirectory();
    bool deleteFile();
    std::string toString();
    bool getStat(struct stat stat1);

private:
    char * path;

};


#endif //LINUX_FILE_H
