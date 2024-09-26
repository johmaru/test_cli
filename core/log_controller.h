//
// Created by Administrator on 2024/09/24.
//

#ifndef TEST_CLI_LOG_CONTROLLER_H
#define TEST_CLI_LOG_CONTROLLER_H

#include <stddef.h>

enum Ostype {
    WINDOWS,
    LINUX,
    MACOS,
    UNKNOWN
};


enum Logstate{
    INFO,
    WARNING,
    ERROR
};

struct LogStruct{
    char time[20];
   enum Logstate state;
    char message[256];
};

struct LogstateStruct{
    enum Logstate state;
    const char *state_name;
};

extern struct LogstateStruct info;
extern struct LogstateStruct warning;
extern struct LogstateStruct error;


int create_directory(const char *path,int os);

int directory_exists(const char *path);

void nowtime_getter(char *buf,size_t buf_size);

int create_file(const char *path);

int open_file_a(const char *path,char *msg);

int create_log(const char *path,enum Logstate state,const char *log);


#endif //TEST_CLI_LOG_CONTROLLER_H
