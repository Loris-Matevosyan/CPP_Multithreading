#include "ThreadPool.h"


void ThreadPool::worker()
{
    while(true)
    {
        Function task;
        myTasks.pop(task);
        task();
    }
}


void ThreadPool::submit(Function task)
{
    myTasks.push(task);
}


ThreadPool::ThreadPool()
{
    const unsigned short int threadCount = std::thread::hardware_concurrency();
    for(int i = 0; i < threadCount; ++i)
        threads.emplace_back(std::thread{&ThreadPool::worker, this});
}


ThreadPool::~ThreadPool()
{
    for(auto& thread: threads)
        thread.join();
}