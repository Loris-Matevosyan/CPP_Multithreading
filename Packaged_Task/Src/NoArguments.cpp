#include "NoArguments.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::literals;


void noArguments()
{
    
    std::cout << "Called function without argument on thread with id: " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(2s);
    std::cout << "Function is going on thread with id: " << std::this_thread::get_id() << std::endl; 

    std::this_thread::sleep_for(2s);
    std::cout << "Function from thread with id: " << std::this_thread::get_id() << "  finished its existence" << std::endl;

}