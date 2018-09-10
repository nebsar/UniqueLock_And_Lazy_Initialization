/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 9, 2018, 8:11 PM
 */

#include <cstdlib>

#include "LogFile.h"
#include <thread>

using namespace std;

/*
 * 
 */
void function(LogFile& logf) {
    for (int i = 0; i>-100; i--)
        logf.shared_print("T1 Thread : ", i);
}

int main() {

    LogFile logFile;

    thread t1(function, ref(logFile));




}

