#include "myLockGuard.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>


std::mutex mutex;


void countWithLockGuard(const std::string& threadName) {
    std::lock_guard<std::mutex> lockGuard(mutex);
    for(int i = 1; i < 11; ++i)
        std::cout << threadName << ": " << i << std::endl;
} // mutex will be unlocked in std::lock_guard destructor


void lockGuardExample() {

    std::string firstThreadName{"First thread"};
    std::string secondThreadName{"Second thread"};
    std::jthread thread1(countWithLockGuard, std::ref(firstThreadName));
    std::jthread thread2(countWithLockGuard, std::ref(secondThreadName));

}