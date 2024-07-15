#ifndef _READER_
#define _READER_

#include <string>
#include <condition_variable>
#include <mutex>


void reader(std::mutex& mutex, std::condition_variable& condVar, const std::string& text);
void safeReader(std::mutex& mutex, std::condition_variable& condVar, const std::string& text, bool& flag);



#endif //_READER_