#include "myRecursiveMutex.h"
#include <iostream>
#include <thread>
#include <mutex>


// recursive_mutex is a sign of bad design!
std::recursive_mutex recursiveMutex;


int fibonacciWithRecursiveMutex(int number) {
    if (number == 1)
        return 1;
    if (number == 0)
        return 0;
    recursiveMutex.lock();
    int result = fibonacciWithRecursiveMutex(number - 1) + fibonacciWithRecursiveMutex(number - 2);
    recursiveMutex.unlock();
    std::cout << result << " ";
    return result;
}


void recursiveMutexExample() {

    std::thread thread1(fibonacciWithRecursiveMutex, 7);
    
    thread1.join();

}
