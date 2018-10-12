#include <memory>

/**
 * 此程序使用的是C++17标准
 */


#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <cstdlib>
#include <vector>
#include <memory>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <cmath>
#include <boost/lexical_cast.hpp>
#include <array>

#include "../test/Testable.h"
#include "../test/ForkTest.h"
#include "../test/SystemTest.h"
#include "../test/LambdaTest.h"
#include "../test/PrintDirTest.h"
#include "../test/FileTest.h"
#include "../test/UnameTest.h"
#include "../test/EnvironTest.h"
#include "../test/TimeTest.h"

using namespace std;


vector<shared_ptr<Testable>> v;

void addTestable();

void run();

void testEvent();

void writeTest();

int main() {
//    using namespace std;
//    FILE *fpw = popen("./Linux2", "w");
//    fprintf(fpw, "hahahhhahahhhah");
//    fflush(fpw);
//    fclose(fpw);


//    writeTest();


    testEvent();
}

void writeTest() {
    const char *buf = "124345454894964196411416416\n";
    write(1, buf, strlen(buf) * sizeof(char));

    int fd = open("/dev/null", O_RDWR);
    if (fd == -1) {
        perror("");
    }
    write(fd, buf, strlen(buf) * sizeof(char));
    ssize_t k = read(fd, (void *)buf, strlen(buf) * sizeof(char));
    cout << k << endl;
    close(fd);
}

void testEvent() {
    addTestable();

    run();
}

void run() {
    for (const auto &k : v) {
        k->test();
    }
}

/**
 * 将要测试的类放入此处
 */
void addTestable() {
//    v.push_back(make_shared<SystemTest>());
//    v.push_back(make_shared<ForkTest>());
//    v.push_back(make_shared<LambdaTest>());
//    v.push_back(make_shared<PrintDirTest>());
//    v.push_back(std::make_shared<FileTest>());
//    v.push_back(std::make_shared<UnameTest>());
//    v.push_back(std::make_shared<EnvironTest>());
    v.push_back(std::make_shared<TimeTest>());
}
