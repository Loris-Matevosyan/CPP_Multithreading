#include "noMutex.h"
#include <iostream>
#include <string>
#include <thread>


void countWithoutMutex(const std::string& theadName) {
    for(int i = 1; i < 11; ++i) {
        std::cout << theadName << ": " << i << std::endl;
    }
}


void noMutexExample() {

    std::string firstThreadName{"First thread"};
    std::string secondThreadName{"Second thread"};
    std::thread thread1(countWithoutMutex, std::ref(firstThreadName));
    std::thread thread2(countWithoutMutex, std::ref(secondThreadName));
    
    thread1.join();
    thread2.join();

}