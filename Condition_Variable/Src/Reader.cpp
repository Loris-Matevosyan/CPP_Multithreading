#include "Reader.h"
#include <iostream>


void reader(std::mutex& mutex, std::condition_variable& condVar, const std::string& text)
{
    std::unique_lock<std::mutex> lock(mutex);
    std::cout << "Reader thread locking the mutex\n";

    std::cout << "Reader thread waiting\n";
    condVar.wait(lock);

    std::cout << "Back to reader\n";
    std::cout << "Text: " << text << std::endl;

}