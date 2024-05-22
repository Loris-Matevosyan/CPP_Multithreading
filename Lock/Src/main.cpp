#include <iostream>
#include <string_view>
#include "myLocks.h"

void indenting(std::string_view lockType) {
    std::cout << "\n\n==============" << lockType << "==============\n\n" << std::endl;
}

int main() {

    indenting("LOCK GUARD");
    lockGuardExample();

    indenting("UNIQUE LOCK");
    uniqueLockExample();

    indenting("UNIQUE LOCK ARGUMENTS");
    uniqueLockArgsExample();

    indenting("SCOPED LOCK");
    scopedLockExample();

return 0;
}