#include "Headers.h"
#include <iostream>
#include <thread>


// Main problem with condition_variable is 
// Lost Wakeup (wait() called after notify_one()) and
// Spurius Wakeup (wait() wakes up before notify_one())

// Can avoid this problems by using
// condition_variable with predicate


// Note: this is an example for learning and code is written to explain in an easy way
// and passing 5 arguments like in this example is not considered as clean code
// so try to avoid that in real world projects


void firstExample(std::mutex& mutex, std::condition_variable& condVar)
{

    std::string text{"Empty"};
    std::cout << "Text: " << text << std::endl;

    std::thread threadOne(reader, std::ref(mutex), std::ref(condVar), std::cref(text));
    std::thread threadTwo(writer, std::ref(mutex), std::ref(condVar), std::ref(text));

    threadOne.join();
    threadTwo.join();

}


void secondExample(std::mutex& mutex, std::condition_variable& condVar)
{
    
    std::string text{"Empty"};
    std::cout << "Text: " << text << std::endl;

    bool flag{false};

    std::thread threadThree(safeReader, std::ref(mutex), std::ref(condVar), std::cref(text), std::ref(flag));
    std::thread threadFour(safeWriter, std::ref(mutex), std::ref(condVar), std::ref(text), std::ref(flag));

    threadThree.join();
    threadFour.join();

}


int main()
{

    std::condition_variable condVar;
    std::mutex mutex;

    firstExample(mutex, condVar);
    secondExample(mutex, condVar);


    return 0;
}