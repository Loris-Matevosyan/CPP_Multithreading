#include "Headers.h"
#include <iostream>
#include <string>
#include <future>
#include <thread>


void sameThreadExample()
{
    std::packaged_task<void(void)> taskOne( [] { 
        std::cout << "Called lambda expression on the same thread with id: " << std::this_thread::get_id() << std::endl;
    });

    taskOne();
}


void withoutArgumentsExample()
{
    std::packaged_task<void(void)> taskTwo(noArguments);

    std::thread threadOne(std::move(taskTwo));

    threadOne.join();
}


void withArgumentsExample()
{
    std::packaged_task<void(int, std::string)> taskThree(withArguments);

    std::string name{"James"};

    std::thread threadTwo(std::move(taskThree), 123456789, name);

    threadTwo.join();
}


void withReturnValueExample()
{
    std::packaged_task<int(int)> taskFour(withReturnValue);

    std::future<int> returnValue = taskFour.get_future();

    std::thread threadThree(std::move(taskFour), 25);

    returnValue.wait();
    std::cout << "Returned value is " << returnValue.get() << std::endl;

    threadThree.join();
}


int main()
{

    sameThreadExample();
    withoutArgumentsExample();
    withArgumentsExample();
    withReturnValueExample();


    return 0;
}