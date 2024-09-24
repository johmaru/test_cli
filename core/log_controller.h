//
// Created by Administrator on 2024/09/24.
//
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#ifndef TEST_CLI_LOG_CONTROLLER_H
#define TEST_CLI_LOG_CONTROLLER_H

int create_directory(const char *path);

int directory_exists(const char *path);


#endif //TEST_CLI_LOG_CONTROLLER_H
