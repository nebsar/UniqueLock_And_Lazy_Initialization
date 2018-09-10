/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.cpp
 * Author: Eagleye
 * 
 * Created on September 9, 2018, 8:12 PM
 */

#include "LogFile.h"

LogFile::LogFile() {
    /* @brief output file stream to write data to file*/
    m_oFstream.open("UinqueLock.txt");
}

LogFile::~LogFile() {
    m_oFstream.close();
}

void LogFile::shared_print(char* msg, int i) {
    m_oFstream << "From " << msg << " " << i << endl;
}

