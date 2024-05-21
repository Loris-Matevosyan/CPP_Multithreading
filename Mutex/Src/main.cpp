#include <iostream>
#include <string_view>
#include "myMutexes.h"


void indenting(std::string_view mutexType) {
    std::cout << "\n\n============  " << mutexType << "  ============\n\n" << std::endl;
} 


int main() {

    indenting("WITHOUT MUTEX");
    noMutexExample();

    indenting("MUTEX");
    mutexExample();
    
    indenting("RECURSIVE MUTEX");
    recursiveMutexExample();

    indenting("TIMED MUTEX");
    timedMutexExample();

    indenting("SHARED MUTEX");
    sharedMutexExample();

return 0;
}