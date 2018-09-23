//
// Created by vant on 18-9-23.
//

#include <iostream>
#include "LambdaTest.h"


using namespace std;
void LambdaTest::test() {
    auto l = [=] (){ return 100;};
    cout << l() << endl;
}
