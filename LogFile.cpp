/* 
 * File:   LogFile.cpp
 * Author: Eagleye
 * 
 * Created on September 9, 2018, 8:12 PM
 */

#include "LogFile.h"
#include <iostream>
#include <mutex>

using namespace std;

LogFile::LogFile() {
}

LogFile::~LogFile() {
    m_oFstream.close();
}

void LogFile::shared_print(const char* msg, int i) {
    /*{ 
        std::lock_guard<mutex> lockFile(m_open_file);
        {
            if (!m_oFstream.is_open())
                m_oFstream.open("UinqueLock.txt");
        }
    }*/

    /* we do not need to use above lines if we use std::call_once function */
    std::call_once(m_onceFlag, [&]() {
        m_oFstream.open("UinqueLock.txt"); // file will be opened only once by one thread.
    }); /* we use lambda function as predicate here */

    // lock_guard<mutex> locker(m_mutex); // does the same thing with below statement, except std::defer lock

    std::unique_lock<mutex> locker(m_mutex, std::defer_lock);
    /* if you use std::defer_lock argument, then you do not lock the mutex, 
     * after writing some other code lines then you can lock the mutex */

    locker.lock(); // since we used defer_lock above, we lock the locker at this line

    m_oFstream << "From " << msg << " " << i << endl;

    locker.unlock(); // we unlock the locker with this line.

    // you can lock the mutex again with the below code
    //  locker.lock();

    /* unique_lock is also movable to another unique_lock */

    // unique_lock<mutex> locker2 = move(locker);

    /* unique_lock is flexible but lock_guard is faster*/

}

