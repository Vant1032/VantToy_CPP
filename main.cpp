/**
 * 此程序使用的是C++17标准
 */


#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <vector>
#include <memory>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <cmath>

#include "test/Testable.h"
#include "test/ForkTest.h"
#include "test/SystemTest.h"
#include "test/LambdaTest.h"
#include "test/PrintDirTest.h"

using namespace std;


vector<shared_ptr<Testable>> v;

void addTestable();

void run();

void testEvent();

void work() {
    FILE *f;
    int i;
    double x = 4.5;

    f = tmpfile();
    for (int i = 0; i < 10000; ++i) {
        fprintf(f, "Do some output\n");
        if (ferror(f)) {
            fprintf(stderr, "Error writing to temporary file\n");
            exit(1);
        }
    }
    for (int j = 0; j < 100000; ++j) {
        x = log(x * x + 3.21);
    }
}


int main() {
    DIR *dp = opendir("..");
    cout << get_current_dir_name() << endl;
    cout << dp << endl;
    dirent *dir = readdir(dp);
    cout << dir->d_name << endl;
    cout << readdir(dp)->d_name << endl;
    cout << readdir(dp)->d_name << endl;
    cout << readdir(dp)->d_name << endl;
    cout << readdir(dp)->d_name << endl;


//    rusage rusage1;
//    rlimit rlimit1;
//    int priority;
//    work();
//
//    getrusage(RUSAGE_SELF, &rusage1);
//
//    testEvent();
}

void testEvent() {
    addTestable();

    run();
}

void run() {
    for (auto k : v) {
        k->test();
    }
}

/**
 * 将要测试的类放入此处
 */
void addTestable() {
    v.push_back(shared_ptr<Testable>(new SystemTest()));
    v.push_back(shared_ptr<Testable>(new ForkTest()));
    v.push_back(shared_ptr<Testable>(new LambdaTest()));
    v.push_back(shared_ptr<Testable>(new PrintDirTest()));
}
