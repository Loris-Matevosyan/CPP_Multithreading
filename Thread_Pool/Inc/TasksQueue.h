#ifndef _TASKSQUEUE_
#define _TASKSQUEUE_

#include <type_traits>
#include <concepts>
#include <queue>
#include <condition_variable>
#include <mutex>


template <typename T>
concept Task = std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>;


template <Task T>
class TasksQueue
{

    std::mutex mutex;
    std::queue<T> tasks;
    std::condition_variable conVar;

public:

    void push(T task)
    {
        std::scoped_lock lock(mutex);
        tasks.push(task);
        conVar.notify_one();
    }

    void pop(T& task)
    {
        std::unique_lock lock(mutex);
        conVar.wait( lock, [this] { return !tasks.empty(); });
        task = tasks.front();
        tasks.pop();
    }

};



#endif //_TASKSQUEUE_