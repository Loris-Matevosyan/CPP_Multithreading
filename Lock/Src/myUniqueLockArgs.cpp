#include "myUniqueLock.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>


std::mutex mutex_one;
std::mutex mutex_two;
std::mutex mutex_three;
std::mutex mutex_four;


void countWithUniqueLockDefer(const std::string& threadName) {
    std::unique_lock uniqueLockDefer(mutex_two, std::defer_lock);
    uniqueLockDefer.lock();
    std::cout << threadName << " locked" << std::endl;
    for(int i = 1; i < 6; ++i)
        std::cout << threadName << ": " << i << std::endl;
    uniqueLockDefer.unlock();
}   // if not unlocked explicitly mutex will be unlocked in std::unique_lock destructor


void countWithUniqueLockAdopt(const std::string& threadName) {
    std::lock(mutex_two, mutex_three);
    std::cout << threadName << " locked" << std::endl;
    for(int i = 1; i < 6; ++i)
        std::cout << threadName << ": " << i << std::endl;
    std::unique_lock uniqueLockAdopt1(mutex_two, std::adopt_lock);
    std::unique_lock uniqueLockAdopt2(mutex_three, std::adopt_lock);
}   // mutexes will be unlocked in destructors


void countWithUniqueLockTryToLock(const std::string& threadName) {
    std::unique_lock uniqueLockTryToLock(mutex_four, std::try_to_lock);
    bool isLocked = uniqueLockTryToLock.owns_lock();
    if (isLocked) {
        std::cout << threadName << " locked" << std::endl;
        for(int i = 1; i < 6; ++i)
            std::cout << threadName << ": " << i << std::endl;
    }
}   // mutex will be unlocked in std::unique_lock destructor


void title(const std::string& argType) {
    std::cout << "\n\n===============" << argType << "===============\n" << std::endl;
}


void uniqueLockArgsExample() {
    
    std::string firstThreadName{"First thread"};
    std::string secondThreadName{"Second thread"};
    std::string thirdThreadName{"Third thread"};
    std::string fourthThreadName{"Fourth thread"};
    std::string fifthThreadName{"Fifth thread"};
    std::string sixthThreadName{"Sixth thread"};

    title("std::defer_lock");
    std::jthread thread1(countWithUniqueLockDefer, std::ref(firstThreadName));
    std::jthread thread2(countWithUniqueLockDefer, std::ref(secondThreadName));

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    title("std::adopt_lock");
    std::jthread thread3(countWithUniqueLockAdopt, std::ref(thirdThreadName));
    std::jthread thread4(countWithUniqueLockAdopt, std::ref(fourthThreadName));

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    title("std::try_to_lock");
    std::jthread thread5(countWithUniqueLockTryToLock, std::ref(fifthThreadName));
    std::jthread thread6(countWithUniqueLockTryToLock, std::ref(sixthThreadName));

}