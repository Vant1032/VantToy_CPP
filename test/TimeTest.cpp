//
// Created by Vant on 18-9-29.
//

#include <ctime>
#include <stdio.h>
#include <cstring>
#include "TimeTest.h"

void TimeTest::test() {
    time_t t;
    time(&t);
    printf("%lld\n", t);
    printf("%s\n", ctime(&t));
    tm *tm = new struct tm;
    memcpy(tm, gmtime(&t), sizeof(tm));
    printf("minute = %d\n", tm->tm_min);
    delete tm;
}
