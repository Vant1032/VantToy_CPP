//
// Created by vant on 18-9-22.
//

#include "SystemTest.h"
#include <iostream>

using namespace std;
void SystemTest::test() {
    cout << "Running ps with system\n";
    auto a = system("ps ax");
    cout << a << endl;
    cout << "done";
}
