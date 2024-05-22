#include "myScopedLock.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>


// std::scoped_lock introduced in C++17

std::mutex mutex1;
std::mutex mutex2;
std::mutex mutex3;


void countWithScopedLock(const std::string& threadName) {
    std::scoped_lock scopedLock(mutex1, mutex2, mutex3);
    for(int i = 1; i < 11; ++i)
        std::cout << threadName << ": " << i << std::endl;
}   // mutexes will be unlocked in std::scoped_lock destructor


void scopedLockExample() {
    
    std::string firstThreadName{"First thread"};
    std::string secondThreadName{"Second thread"};
    std::jthread thread1(countWithScopedLock, std::ref(firstThreadName));
    std::jthread thread2(countWithScopedLock, std::ref(secondThreadName));

}
