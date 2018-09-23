//
// Created by vant on 18-9-23.
//

#ifndef LINUX_FILE_H
#define LINUX_FILE_H

#include <string>
#include <sys/stat.h>
#include <vector>

class File {
public:
    explicit File(char *path);

    explicit File(std::string &path);

    File(const File &file);

    File(File &&file) noexcept;

    File &operator=(const File &file);

    File &operator=(File &&file) noexcept;


    virtual ~File();

    bool exist() const;

    bool canWrite() const;

    bool canRead() const;

    bool canExecute() const;

    bool isFile() const;

    bool isDirectory() const;

    bool deleteFile() const;

    std::string toString() const;

    std::vector<File> listFiles() const;


private:
    char *path;
};


#endif //LINUX_FILE_H
