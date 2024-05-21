#include "mySharedMutex.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <shared_mutex>

using namespace std::literals;
using namespace std::chrono;


// std::shared_mutex introduced in C++17
// std::jthread introduced in C++20

std::shared_mutex sharedMutex;
std::string name{"John Smith"};


void writer(const std::string& newName) {
    sharedMutex.lock();
    std::cout << "Writer thread changed name from " << name << " to " << newName << std::endl;
    name = newName;
    sharedMutex.unlock();
}


void reader(int threadNumber) {
    sharedMutex.lock_shared();
    std::cout << "Thread " << threadNumber << " is reading the name: " << name << std::endl;
    sharedMutex.unlock_shared();
}


void utilityTestSharedMutex(int index, const std::string& newName) {
    int indexPlusFour = index + 4;
    for(int i = index; i < index + 10; ++i){
        std::jthread readerThread(reader, i);
        if (i == indexPlusFour)
            std::jthread writerThread(writer, std::ref(newName));
    }
}


void sharedMutexExample() {

    std::string nameOne{"Sam Wilson"};
    std::string nameTwo{"Paul Miller"};
    utilityTestSharedMutex(1, nameOne);
    utilityTestSharedMutex(11, nameTwo);

}