//
// Created by Vant on 18-9-23.
//

#include "FileTest.h"
#include "../utils/File.h"

#include <iostream>

using namespace std;
void FileTest::test() {
    char p[] = "/";
    File file(p);
    auto v = file.listFiles();
    for (const auto &item : v) {
        cout << item.toString() << endl;
    }
    cout << "file.canRead() = " << file.canRead() << endl;
    cout << "file.canWrite() = " << file.canWrite() << endl;
    cout << "file.canExecute() = " << file.canExecute() << endl;
    cout << "file.isDirectory() = " << file.isDirectory() << endl;
    cout << "file.exist() = " << file.exist() << endl;

}
