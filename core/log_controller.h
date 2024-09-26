//
// Created by Administrator on 2024/09/24.
//

#ifndef TEST_CLI_LOG_CONTROLLER_H
#define TEST_CLI_LOG_CONTROLLER_H

enum Ostype {
    WINDOWS,
    LINUX,
    MACOS,
    UNKNOWN
};


int create_directory(const char *path,int os);

int directory_exists(const char *path);


#endif //TEST_CLI_LOG_CONTROLLER_H
