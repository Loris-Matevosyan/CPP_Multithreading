#include "myUniqueLock.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>


std::mutex mutexOne;


void countWithUniqueLock(const std::string& threadName) {
    std::unique_lock<std::mutex> uniqueLock(mutexOne);
    for(int i = 1; i < 11; ++i)
        std::cout << threadName << ": " << i << std::endl;
    uniqueLock.unlock();
}   // if not unlocked explicitly mutex will be unlocked in std::unique_lock destructor


void uniqueLockExample() {
    
    std::string firstThreadName{"First thread"};
    std::string secondThreadName{"Second thread"};
    std::jthread thread1(countWithUniqueLock, std::ref(firstThreadName));
    std::jthread thread2(countWithUniqueLock, std::ref(secondThreadName));

}