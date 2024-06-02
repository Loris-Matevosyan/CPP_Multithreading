#include "PCModel.h"
#include <vector>
#include <mutex>


void firstExample() 
{
    std::cout << "\n\n=========PRODUCER-CONSUMER MODEL=========\n\n" << std::endl;

    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread producerThread(producer, std::ref(promise));
    std::thread consumerThread(consumer, std::ref(future));


    producerThread.join();
    consumerThread.join();
}


void secondExample() 
{
    std::cout << "\n\n=========SINGLE PRODUCER - MULTIPLE CONSUMER=========\n\n" << std::endl;

    std::mutex mutex;

    std::promise<int> singlePromise;
    std::shared_future<int> sharedFuture = singlePromise.get_future();

    std::jthread singleProducerThread(singleProducer, std::ref(singlePromise));
    std::vector<std::jthread> threads;

    for(int i = 1; i < 11; ++i) 
    {
        std::shared_future<int> sharedFutureCopy = sharedFuture;
        threads.emplace_back(std::jthread(multipleConsumers, std::move(sharedFutureCopy), std::ref(mutex), i));
    }
}



int main() 
{

    firstExample();
    secondExample();


    return 0;
}