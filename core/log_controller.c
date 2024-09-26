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

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

extern char instance_time[20];

struct LogstateStruct info = {
    .state = INFO,
    .state_name = "INFO"
};

struct LogstateStruct warning = {
    .state = WARNING,
    .state_name = "WARNING"
};

struct LogstateStruct error = {
    .state = ERROR,
    .state_name = "ERROR"
};

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

int create_file(const char *filepath){
    FILE *file = fopen(filepath,"w");
    if(file == NULL){
        printf("Unable to create file\n");
        return 1;
    }
    fprintf(file,"Log file created successfully\n");
    fclose(file);
    return 0;
}

int open_file_a(const char *filepath,char *msg){
    FILE *file = fopen(filepath,"a");
    if(file == NULL){
        printf("Unable to open file\n",strerror(errno));
        return 1;
    }
    fprintf(file,"%s\n",msg);
    fclose(file);
    return 0;
}

const char *get_logstate_name(enum Logstate state){
    switch (state)
    {
    case INFO:
        return info.state_name;
        break;
    case WARNING:
        return warning.state_name;
        break;
    case ERROR:
        return error.state_name;
        break;
    default:
        return "UNKNOWN";
        break;
    }
}

int create_log(const char *path,enum Logstate state,const char *msg){
    

   struct LogStruct log = {
        .time = "",
        .state = state,
        .message = ""
    };

    strncpy(log.time,instance_time,sizeof(log.time) -1);
    strncpy(log.message,msg,sizeof(log.message)-1);
    char file_path[MAX_BUF + 10];
    snprintf(file_path,sizeof(file_path),"%s/log.txt",path);

    char full_msg[MAX_BUF + 100];
     snprintf(full_msg, sizeof(full_msg), "[%s] %s", get_logstate_name(log.state), log.message);
     FILE *file = fopen(path,"a");
    if(file == NULL){
        printf("Unable to create file\n");
        return 1;
    }
    fprintf(file,full_msg);
    fclose(file);
    return 0;
}