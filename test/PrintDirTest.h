//
// Created by vant on 18-9-23.
//

#ifndef LINUX_PRINTDIRTEST_H
#define LINUX_PRINTDIRTEST_H

#include "Testable.h"

class PrintDirTest : public Testable {
public:
    void test() override;

    void printDir(char *dir, int depth);
};


#endif //LINUX_PRINTDIRTEST_H
