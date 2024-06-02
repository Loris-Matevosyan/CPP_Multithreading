#ifndef _MULTIPLECONSUMERS_
#define _MULTIPLECONSUMERS_

#include <iostream>
#include <future>


void multipleConsumers(std::shared_future<int>&& sharedFuture, std::mutex& mutex, int consumerNumber) 
{

    mutex.lock();
    std::cout << "Consumer " << consumerNumber << ": Waiting for ID number" << std::endl;
    mutex.unlock();

    int ID_number = sharedFuture.get();

    mutex.lock();
    std::cout << "Consumer " << consumerNumber << ": ID number is " << ID_number << std::endl;
    mutex.unlock();

}



#endif //_MULTIPLECONSUMERS_