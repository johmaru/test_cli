//
// Created by Administrator on 2024/09/24.
//

#include "log_controller.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#if _WIN32
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)
#endif

int create_directory(const char *path, int os){
   switch (os)
   {
   case 1:
     #if _WIN32
     #define if(mkdir(path) == 0){
        printf("Directory created successfully\n");
        return 0;
       
    }
    else{
        printf("Unable to create directory\n");
        return -1;
    }
     #endif
    break;
    case 2:
    case 3:
    if(mkdir(path, 0777) == 0){
        printf("Directory created successfully\n");
        return 0;
    }
    else{
        printf("Unable to create directory\n");
        return -1;
    }
   
   default:
    break;
   }
}

int directory_exists(const char *path){
    if(opendir(path) == NULL){
        return -1;
    }
    else{
        return 0;
    }
}

void nowtime_getter(char *buf,size_t buf_size){
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buf,buf_size,"%Y-%m-%d %H:%M:%S",t);
}