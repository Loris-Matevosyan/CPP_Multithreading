#include "WithArguments.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::literals;


void withArguments(int number, std::string name)
{
    
    std::cout << "Called function with argument on thread with id: " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(2s);
    std::cout << name << " number is " << number << std::endl;
    std::cout << "Function is going on thread with id: " << std::this_thread::get_id() << std::endl; 

    std::this_thread::sleep_for(2s);
    std::cout << "Function from thread with id: " << std::this_thread::get_id() << "  finished its existence" << std::endl;

}