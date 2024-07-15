#include "WithReturnValue.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::literals;


int withReturnValue(int number)
{
    
    std::cout << "Called function with return value on thread with id: " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(2s);
    std::cout << "Number is " << number << std::endl;
    std::cout << "Function is going on thread with id: " << std::this_thread::get_id() << std::endl; 

    std::this_thread::sleep_for(2s);
    std::cout << "Function from thread with id: " << std::this_thread::get_id() << "  finished its existence" << std::endl;

    return number * 10;

}