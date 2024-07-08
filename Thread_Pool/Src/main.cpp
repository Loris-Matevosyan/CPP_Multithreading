#include "ThreadPool.h"
#include "TasksQueue.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std::literals;


std::mutex mutex;

void myask() 
{    
    std::scoped_lock lock(mutex);
    static int count{1};

    std::cout << "This thread ID is: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(100ms);
    std::cout << "Task " << count << " is called" << std::endl;
    
    ++count;
}

int main() 
{

    ThreadPool threadPool;

    for(int i = 0; i < 20; ++i)
        threadPool.submit(myask);


    return 0;
}