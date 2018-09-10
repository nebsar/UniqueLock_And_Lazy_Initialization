/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.h
 * Author: Eagleye
 *
 * Created on September 9, 2018, 8:12 PM
 */

#ifndef LOGFILE_H
#define LOGFILE_H

#include <mutex>
#include <fstream>

class LogFile {
public:
    LogFile();
    virtual ~LogFile();

    void shared_print(char* msg, int i);

private:
    /*@brief mutex to sync the threads*/
    std::mutex m_mutex;
    /* @brief output file stream to write data to file*/
    std::ofstream m_oFstream;

};

#endif /* LOGFILE_H */

