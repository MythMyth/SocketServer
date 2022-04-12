#ifndef __DEBUG__
#define __DEBUG__

#include<iostream>
#include<string.h>
#include<SingleTon.h>

using namespace std;

typedef enum _LogLevel {
    LOG_LEVEL_LOW = 0,
    LOG_LEVEL_MED,
    LOG_LEVEL_HIGH,
    LOG_LEVEL_NO_LOG
} LogLevel;

class Debug:public Singleton<Debug> {
    public:

    Debug() {
        debug_level = LOG_LEVEL_NO_LOG;
    }

    void SetDebugLevel(LogLevel level) {
        debug_level = level;
    }

    void Log(LogLevel level, string line) {
        if(level >= debug_level) {
            cout << line << "\n";
        }
    }

    private:
    LogLevel debug_level;
};

#endif