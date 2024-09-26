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


int create_directory(const char *path,int os);

int directory_exists(const char *path);

void nowtime_getter(char *buf,size_t buf_size);


#endif //TEST_CLI_LOG_CONTROLLER_H
