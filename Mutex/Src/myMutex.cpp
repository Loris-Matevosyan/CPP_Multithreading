#include "myMutex.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>


std::mutex mutex;


void countWithMutex(const std::string& theadName) {
    mutex.lock();
    for(int i = 1; i < 11; ++i) {
        std::cout << theadName << ": " << i << std::endl;
    }
    mutex.unlock();
}


void mutexExample() {

    std::string firstThreadName{"First thread"};
    std::string secondThreadName{"Second thread"};
    std::thread thread1(countWithMutex, std::ref(firstThreadName));
    std::thread thread2(countWithMutex, std::ref(secondThreadName));
    
    thread1.join();
    thread2.join();

}