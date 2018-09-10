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
    /* @brief output file stream to write data to file*/
    m_oFstream.open("UinqueLock.txt");
}

LogFile::~LogFile() {
    m_oFstream.close();
}

void LogFile::shared_print(const char* msg, int i) {
    m_oFstream << "From " << msg << " " << i << endl;
}

