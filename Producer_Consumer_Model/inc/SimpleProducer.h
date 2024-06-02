#ifndef _SIMPLEPRODUCER_
#define _SIMPLEPRODUCER_

#include <iostream>
#include <chrono>
#include <thread>
#include <future>


void producer(std::promise<int>& promise) 
{

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Producer: Creating ID number" << std::endl;
    int ID_number{10};

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Producer: Sending new ID number" << std::endl;
    promise.set_value(ID_number);

}



#endif //_SIMPLEPRODUCER_