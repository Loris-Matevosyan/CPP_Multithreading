#ifndef _SIMPLECONSUMER_
#define _SIMPLECONSUMER_

#include <iostream>
#include <future>


void consumer(std::future<int>& future) 
{

    std::cout << "Consumer: Waiting for ID number" << std::endl;
    int ID_number = future.get();

    std::cout << "Consumer: ID number is " << ID_number << std::endl;

}



#endif //_SIMPLECONSUMER_