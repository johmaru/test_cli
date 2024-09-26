#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "core/log_controller.h"
#include "log.h"

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

char instance_time[20];
FILE *log_file;

int main(void) {
        int os_value = 0;
       nowtime_getter(instance_time,sizeof(instance_time));
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
    
    char time_path[MAX_BUF];
    snprintf(time_path,sizeof(time_path),"logs/%s",instance_time);
    create_directory(time_path,os_value);

    char file_path[MAX_BUF + 10];
    snprintf(file_path,sizeof(file_path),"%s/log.txt",time_path);
    
    create_file(file_path);
    create_log(file_path,INFO,"intialized");

    return 0;
}
