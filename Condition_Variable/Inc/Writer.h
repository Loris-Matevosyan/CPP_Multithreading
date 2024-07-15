#ifndef _WRITER_
#define _WRITER_

#include <condition_variable>
#include <mutex>
#include <string>


void writer(std::mutex& mutex, std::condition_variable& condVar, std::string& text);
void safeWriter(std::mutex& mutex, std::condition_variable& condVar, std::string& text, bool& flag);



#endif //_WRITER_