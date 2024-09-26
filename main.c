#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "core/log_controller.h"

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

int main(void) {
        int os_value = 0;
    #if defined(_WIN32) || defined(_WIN64)
        os_value = 1;
    #elif defined(__linux__)
        os_value = 2;
    #elif defined(__APPLE__) && defined(__MACH__)
        os_value = 3;
    #else
        os_value = 0;
    #endif

    char path[MAX_BUF];
   getcwd(path, MAX_BUF);
    printf("Current working directory: %s\n",path);

    if(directory_exists("logs") == -1){
        create_directory("logs",os_value);
    }



    return 0;
}
