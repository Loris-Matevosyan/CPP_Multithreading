#ifndef _THREADPOOL_
#define _THREADPOOL_

#include "TasksQueue.h"
#include <functional>
#include <thread>
#include <vector>

using Function = void(*)(void);


class ThreadPool
{

    TasksQueue<Function> myTasks;
    std::vector<std::thread> threads;    
    // std::vector<std::jthread> threads;   // Not needed threads to join in destructor, C++20 feature

    void worker();

public:

    void submit(Function func);
    ThreadPool();
    ~ThreadPool();

};





#endif //_THREADPOOL_