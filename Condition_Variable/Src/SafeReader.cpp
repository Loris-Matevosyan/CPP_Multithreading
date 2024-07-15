#include "Reader.h"
#include <iostream>


void safeReader(std::mutex& mutex, std::condition_variable& condVar, const std::string& text, bool& flag)
{
    std::unique_lock<std::mutex> lock(mutex);
    std::cout << "Reader thread locking the mutex\n";

    std::cout << "Reader thread waiting\n";
    condVar.wait(lock, [&flag] { return flag; } );

    std::cout << "Back to reader\n";
    std::cout << "Text: " << text << std::endl;

}