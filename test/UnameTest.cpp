//
// Created by Vant on 18-9-27.
//

#include <sys/utsname.h>
#include <stdio.h>
#include "UnameTest.h"

void UnameTest::test() {
    utsname n;
    uname(&n);
    printf("%s\n", n.machine);
    printf("%s\n", n.sysname);
    printf("%s\n", n.release);
    printf("%s\n", n.version);
    printf("%s\n", n.domainname);
    printf("%s\n", n.nodename);

}
