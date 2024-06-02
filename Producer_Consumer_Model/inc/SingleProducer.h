#ifndef _SINGLEPRODUCER_
#define _SINGLEPRODUCER_

#include <iostream>
#include <chrono>
#include <thread>
#include <future>


void singleProducer(std::promise<int>& promise) 
{

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "\nSingle Producer: Creating ID number" << std::endl;
    int ID_number{5};

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Single Producer: Sending new ID number\n" << std::endl;
    promise.set_value(ID_number);

}



#endif //_SINGLEPRODUCER_