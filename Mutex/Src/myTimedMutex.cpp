#include "myTimedMutex.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std::literals;
using namespace std::chrono;


std::timed_mutex timedMutex;


void outputWithTimedMutex(const std::string& theadName) {
    bool isLocked = false;
    isLocked = timedMutex.try_lock_for(2500ms);
    if (isLocked) {
        std::cout << theadName << " is locked for 2 seconds" << std::endl;
        std::this_thread::sleep_for(2000ms);
        timedMutex.unlock();
    }
}


void timedMutexExample() {

    std::string firstThreadName{"First thread"};
    std::string secondThreadName{"Second thread"};
    std::thread thread1(outputWithTimedMutex, std::ref(firstThreadName));
    std::thread thread2(outputWithTimedMutex, std::ref(secondThreadName));
    
    thread1.join();
    thread2.join();

}