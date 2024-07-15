#include "Writer.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals;


void writer(std::mutex& mutex, std::condition_variable& condVar, std::string& text)
{   
    {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Writer locked and ready to write\n";
        std::this_thread::sleep_for(1s);
        
        std::cout << "Writing...\n";
        std::this_thread::sleep_for(2s);

        text = "The text is changed";
        std::cout << "Done writing!\n";
    }

    condVar.notify_one();
    
}