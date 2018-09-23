//
// Created by Vant on 18-9-23.
//

#include "FileTest.h"
#include "../utils/File.h"

#include <iostream>

using namespace std;
void FileTest::test() {
    File file(const_cast<char *>("/"));
    auto v = file.listFiles();
    for (const auto &item : v) {
        cout << item.toString() << endl;
    }
}
